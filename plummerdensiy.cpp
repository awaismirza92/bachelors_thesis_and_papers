#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
main()
{
	ifstream read;
	read.open("E:/extra programming/plummer_sphere/plummersphere100k.txt",ios::in);
	double pi=3.141, rho;//rmag[1000],mass[1000];
	
    int n=100000;
	//write.open(,ios::binary);
double *rmag=NULL;
rmag=new double [n];
double *mass=NULL;
mass=new double [n];
double x,y,z,Vx,Vy,Vz,m; 
	int i=0;
	while(read>>x>>y>>z>>Vx>>Vy>>Vz>>m)
	{
		rmag[i]=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
		mass[i]=m;
		i++;
	//	cout<<x<<endl;
	}
	read.close();
	//	rho=3.0*m/4.0*pi*pow(pow(rmag,2),5.0/2.0);
	//	write<<rmag<<"\t"<<rho<<endl;
		
		int rmin=0,rmax=0.01,nrad=1000;
		double rbin[nrad];
		for(int j=1;j<=nrad;j++)
		{
			rbin[j]=0.1*j; 
			//cout<<rbin[j]<<endl;
		}
	
		double massbin[nrad];
		for(int c=0;c<nrad;c++)
		{
			massbin[c]=0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<nrad;j++)
			{
				if(rmag[i]>=rbin[j] && rmag[i]<rbin[j+1])
				{
					massbin[j] +=mass[i];
							
				}
			}
		}
		//	cout<<massbin[0]<<endl;	
    	double totalmass=0;
ofstream results("E:/extra programming/plummer_sphere/plumden100k.txt");	
	double dv;
		for(int k=0;k<nrad;k++)
		{
			totalmass=totalmass+massbin[k];
			dv=(pow(rbin[k+1],3.0)-pow(rbin[k],3.0))*(4.0/3.0)*(3.1415);
			rho=massbin[k]/dv;
	    	results<<0.5*((rbin[k+1])+(rbin[k]))<<"\t"<<rho<<"\t"<<totalmass<<endl;
		//	cout<<0.5*((rbin[k+1])+(rbin[k]))<<"\t"<<rho<<endl;	
		
}
	
}
