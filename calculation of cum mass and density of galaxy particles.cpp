//This code is used for generating density profile, mass profile and cumulative mass 
//profile of a galaxy model or a snap of a galaxy model during any instant of
//simulations running. The program takes the model or snap file as input and 
//returns the density and mass profiles values file as output. Calculated distance and 
//mass of particles is stored in corresponding dynmaic arrays. Next, the masses of 
//particles are put in corresponding mass bins. Finally, bin masses are divided
//by bin volumes to obtained bin densities.

#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

void compute(string input_filename, string output_filename)
{ifstream read1,read2;
int n,tn,bh_n,dm_n,st_n;
double m,Rx,Ry,Rz,Vx,Vy,Vz,s;

//reading preamble parameters of a galaxy model
read2.open(input_filename.c_str(),ios::in);
double snap,unknown,t;
read2>>snap>>tn>>bh_n>>dm_n>>st_n,t;

//dynamic array of distance from center and mass is created with size equal to total objects
double *r=NULL;
r=new double [tn];
double *mass=NULL;
mass=new double [tn];

//first object, i.e., black hole is discarded
read2>>n>>m>>Rx>>Ry>>Rz>>Vx>>Vy>>Vz,s;

//distance from center and mass is stored in corresponding arrays
int i=0;
while(read2>>n>>m>>Rx>>Ry>>Rz>>Vx>>Vy>>Vz>>s)
{
r[i]=sqrt(pow(Rx,2)+pow(Ry,2)+pow(Rz,2));
mass[i]=m;
i++;
}
read2.close();

//creating distance bins 
int rmin=0,rmax=10,nrad=1000;
double rbin[1000];
for(int j=1;j<=nrad;j++)
	{
	rbin[j]=0.01*j;
	}	
	
ofstream results(output_filename.c_str(),ios::binary);

//initializing mass bins with 0 value
double massbin[nrad];
for(int c=0;c<nrad;c++)
	{
		massbin[c]=0;
	}
	
//putting mass of particles in corresponding mass bins	
for(int i=0;i<tn-2;i++)
{
	for(int j=0;j<nrad;j++)
	{	
		if(r[i]>=rbin[j] && r[i]<rbin[j+1])
		{
		massbin[j] +=mass[i];
		}
	}	
}

double totalmass=0;
for(int k=0;k<nrad;k++)
{	totalmass=totalmass+massbin[k]; //cumulative mass calculation
	//differtial volume of a bin calculation
	double dv=(rbin[k+1]*pow(rbin[k+1],2)-rbin[k]*pow(rbin[k],2))*(4.0/3.0)*(3.1415);
	double den=massbin[k]/dv;//density of the bin calculation
	//writing of values. first column is mid point of a bin	
	results<<0.5*((rbin[k+1])+(rbin[k]))<<"\t"<<massbin[k]<<"\t"<<den<<endl;
}
	
cout<<"\a";	
}

int main()
{
	//'compute' function gets address of input model or snap file and output file
	// to compute the density and mass profiles. 
	compute("E:/SkyDrive/Space Sciences/FYP/Awais/Coding/Simulations/Verifying Models/Rotation in Influence Radius/0002.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - Mass and Density Profiles/Model Stability/Rotational in Influence Radius/results_0002.dat");
	compute("E:/SkyDrive/Space Sciences/FYP/Awais/Coding/Simulations/Verifying Models/Rotation in Influence Radius/0006.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - Mass and Density Profiles/Model Stability/Rotational in Influence Radius/results_0006.dat");
//compute("E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90_results.dat");
}
