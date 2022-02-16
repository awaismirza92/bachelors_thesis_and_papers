#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

void compute(string input_filename, string output_filename)
{
ifstream read1,read2;
int n,tn,bh_n,dm_n,st_n;
double m,Rx,Ry,Rz,Vx,Vy,Vz,s;

read2.open(input_filename.c_str(),ios::in);
double snap,unknown,t;
read2>>snap>>tn>>t;//bh_n>>dm_n>>st_n>>t;

read2>>n>>m>>Rx>>Ry>>Rz>>Vx>>Vy>>Vz;

double *r=NULL;
r=new double [tn];
/*double *mass=NULL;
mass=new double [tn];*/
double *velocity=NULL;
velocity=new double [tn];
int i=0;
while(read2>>n>>m>>Rx>>Ry>>Rz>>Vx>>Vy>>Vz)
{
r[i]=sqrt(pow(Rx,2)+pow(Ry,2)+pow(Rz,2));
	velocity[i]=sqrt(pow(Vx,2)+pow(Vy,2)+pow(Vz,2));
//mass[i]=m;
i++;
}
read2.close();

int rmin=0,rmax=10,nrad=1000;
double rbin[1000];
for(int j=1;j<=nrad;j++)
	{
	rbin[j]=0.01*j;
	}	
	
ofstream results(output_filename.c_str(),ios::binary);
	
double vbin[nrad], particle_counter[nrad];
		
for(int c=0;c<nrad;c++)
	{
		vbin[c]=0;
		particle_counter[c]=0;
	}

	
for(int i=0;i<tn-2;i++)
{
		for(int j=0;j<nrad;j++)
		{	
		if(r[i]>=rbin[j] && r[i]<rbin[j+1])
		{
			vbin[j] +=velocity[i];
			particle_counter[j]++;
		}
		}
} 
double avg_vel[nrad];
for(int k=0;k<nrad;k++)
{	
	avg_vel[k]=vbin[k]/particle_counter[k];
	

}
	

double diff_sq[nrad];
for(int l=0; l<=nrad;l++)
{
	diff_sq[l]=0;
}

for(int i=0;i<tn-2;i++)
{
		for(int j=0;j<nrad;j++)
		{	
		if(r[i]>=rbin[j] && r[i]<rbin[j+1])
		{
			diff_sq[j]=diff_sq[j]+pow(velocity[i]-avg_vel[j],2);
		}
		}
} 



double totalvelocity=0;
double disp_vel,velRdis;
for(int k=0;k<nrad;k++)
{	//totalvelocity=totalvelocity+vbin[k];
	//avg_vel=vbin[k]/particle_counter[k];
	
//double dv=(rbin[k+1]*pow(rbin[k+1],2)-rbin[k]*pow(rbin[k],2))*(4.0/3.0)*(3.1415);
		// double den=massbin[k]/dv;
	//	double disp_vel=(vbin[k]-avg_vel)/nrad;
	//disp_vel=pow(((pow(vbin[k],2)/particle_counter[k])-pow((vbin[k]/particle_counter[k]),2)),1/2);
	disp_vel=diff_sq[k]/particle_counter[k];
	velRdis=avg_vel[k]/disp_vel;
	
	
results<<0.5*((rbin[k+1])+(rbin[k]))<<"\t"<<avg_vel[k]<<"\t"<<disp_vel<<"\t"<<velRdis<<endl;//"\t"<<den<<endl;
}	
cout<<"\a";	
}

int main()
{

	//compute("C:/Users/Hp/Dropbox/FYP/codes and plots/Tasks/task-introducerotationingalaxy/norot.dat","C:/Users/Hp/Dropbox/FYP/codes and plots/Tasks/Galaxy Support Check - Velocity vs Dispersion/velocity_disp.dat");
	compute("C:/Users/Hp/Dropbox/FYP/codes and plots/Tasks/task-introducerotationingalaxy/norot.dat","C:/Users/Hp/Dropbox/FYP/codes and plots/Tasks/Galaxy Support Check - Velocity vs Dispersion/velocity_disp2.dat");
//	compute("E:/SkyDrive/Space Sciences/FYP/Awais/Coding/Simulations/Verifying Models/Rotation in Influence Radius/0002_bh_centered.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - Mass and Density Profiles/Model Stability/Rotational in Influence Radius/den_0006_bh_centered.dat");
	//compute("E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90_results.dat");
}
