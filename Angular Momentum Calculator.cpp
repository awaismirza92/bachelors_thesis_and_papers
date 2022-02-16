//This code is used primarily to determine the angular momentum components (Lx, Ly, Lz) 
//of a galaxy model in hand. Besides, it also calculates the components of center of 
//mass (Rx, Ry, Rz) of the galaxy model. These output parameters are not only printed 
//at console but are also written in a text file.

#include<iostream>
#include<fstream>
using namespace std;

main()
{
ifstream read1;
int k; float l,mm,n,o,p,q,r;
//opening galaxy model file
read1.open("F:/BS-Space Sciences/Final Year Project/task 1/gal1.dat",ios::in); 

//counting number of objects in the galaxy model
while(read1>>k>>l>>mm>>n>>o>>p>>q>>r)
{}
cout<<k+1<<endl; 
read1.close();

//making dynamic arrays of all parameters of galaxy objects
float m[], Rx[],Ry[],Rz[],Vx[], Vy[], Vz=[]; 
float *m=NULL;
m=new float[k+1];

float *Rx=NULL;
Rx=new float[k+1];

float *Ry=NULL;
Ry=new float[k+1];

float *Rz=NULL;
Rz=new float[k+1];

float *Vx=NULL;
Vx=new float[k+1];

float *Vy=NULL;
Vy=new float[k+1];

float *Vz=NULL;
Vz=new float[k+1];

//opening galaxy model file again; now for angular momentum calculation
ifstream read2;
read2.open("F:/BS-Space Sciences/Final Year Project/task 1/gal1.dat",ios::in); 

//reading values from galaxy file and assigning them to corresponding arrays
int i=0;
while(read2>>k>>l>>mm>>n>>o>>p>>q>>r)
{
	m[i]=l,Rx[i]=mm,Ry[i]=n,Rz[i]=o,Vx[i]=p,Vy[i]=q,Vz[i]=r;
	i++;
}

//calculating and displaying COM and angular momentum components
float M=0,mRx=0,mRy=0,mRz=0,Lx=0,Ly=0,Lz=0;
for(i=0;i<k+1;i++)
{
	mRx=mRx+(m[i]*Rx[i]);
	mRy=mRy+(m[i]*Ry[i]);
	mRz=mRz+(m[i]*Rz[i]);
	M=M+m[i];
	Lx=Lx+(m[i]*Rx[i]*Vx[i]);
	Ly=Ly+(m[i]*Ry[i]*Vy[i]);
	Lz=Lz+(m[i]*Rz[i]*Vz[i]);
}
cout<<"Rx of COM:"<<mRx/M<<endl;
cout<<"Ry of COM:"<<mRy/M<<endl;
cout<<"Rz of COM:"<<mRz/M<<endl;
cout<<"Lx:"<<Lx<<endl;
cout<<"Ly:"<<Ly<<endl;
cout<<"Lz:"<<Lz<<endl;
read2.close();

//writing the values COM and angular momentum components in a file
ofstream write;
write.open("F:/BS-Space Sciences/Final Year Project/task 1/results.txt",ios::binary);
write<<mRx/M<<" "<<mRy/M<<" "<<mRz/M<<" "<<Lx<<" "<<Ly<<" "<<Lz;
write.close();


}
