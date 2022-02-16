//This coding scheme calculates various parameters like relative distance, relative 
//velocity, center of mass, reduced mass, total specific energy, specific angular 
//momentum, eccentricity and semi-major axis of a supermassive black hole binary.
//The input file is a product of simulation run and contains position and velocity
//components of both of the black holes. Formulas of two-body (Keplerian) mechanices
//are used to compute all of the parameters.


#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;

void compute(string input_filename, string output_filename)
{
	ifstream read;
read.open(input_filename.c_str(),ios::in);

int G=1; double rel_Rx, rel_Ry, rel_Rz,rel_R, V1,V2,rel_Vx,rel_Vy,rel_Vz,rel_V,r1,
r2,R,E,Lx,Ly,Lz,L,e,a;
double t,Rx1,Ry1,Rz1,Vx1,Vy1,Vz1,Rx2,Ry2,Rz2,Vx2,Vy2,Vz2,Rx,Ry,Rz;
double ind1,ind2,aa,b,c,d,ee,f,g,h,i,j,k,l,m,n,o,p;
double m1, m2,red_m,u;

ofstream write;
write.open(output_filename.c_str(),ios::binary);

//reading the binary evolution file. unrequired parameters in the file are discarded.
while(read>>t>>ind1>>m1>>Rx1>>Ry1>>Rz1>>Vx1>>Vy1>>Vz1>>aa>>b>>c>>d>>ee>>f>>g>>h>>ind2>>
m2>>Rx2>>Ry2>>Rz2>>Vx2>>Vy2>>Vz2>>i>>j>>k>>l>>m>>n>>o>>p)
{
//calculating relative distance between the both black holes	
r1=sqrt(pow(Rx1,2)+pow(Ry1,2)+pow(Rz1,2));
r2=sqrt(pow(Rx2,2)+pow(Ry2,2)+pow(Rz2,2));
rel_Rx=Rx2-Rx1; rel_Ry=Ry2-Ry1; rel_Rz=Rz2-Rz1;
rel_R=sqrt(pow(rel_Rx,2)+pow(rel_Ry,2)+pow(rel_Rz,2));

//calculating relative velocity of one black hole w.r.t other one
V1=sqrt(pow(Vx1,2)+pow(Vy1,2)+pow(Vz1,2));
V2=sqrt(pow(Vx2,2)+pow(Vy2,2)+pow(Vz2,2));
rel_Vx=Vx2-Vx1; rel_Vy=Vy2-Vy1; rel_Vz=Vz2-Vz1;
rel_V=sqrt(pow(rel_Vx,2)+pow(rel_Vy,2)+pow(rel_Vz,2));

//calculating center of mass of the binary system
R=((m1*r1+m2*r2)/(m1+m2));Rx=((m1*Rx1+m2*Rx2)/(m1+m2));
Ry=((m1*Ry1+m2*Ry2)/(m1+m2));Rz=((m1*Rz1+m2*Rz2)/(m1+m2));

cout<<t<<'\t'<<endl;
cout<<m1<<'\t'<<ind1<<endl;
cout<<m2<<'\t'<<ind2<<endl;

//calculating reduced mass of the binary
red_m= ((m1*m2)/(m1+m2));
u=G*(m1+m2);//it's meu, gravitational parameter

//calculating specific total energy of the binary system
E=0.5*(pow(rel_V,2))-(u/rel_R);


//calculating Specific Angular Momentum of the binary system
Lx=(rel_Ry*rel_Vz-rel_Rz*rel_Vy);
	Ly=(rel_Rz*rel_Vx-rel_Rx*rel_Vz);
	Lz=(rel_Rx*rel_Vy-rel_Ry*rel_Vx);
L=sqrt(pow(Lx,2)+pow(Ly,2)+pow(Lz,2));

//calculating Eccentricity of the binary orbit
e= sqrt(1+((2*E*pow(L,2))/(pow(u,2))));

//calculating Semi-major axis of the binary orbit
a=-u/(2*E);

//writing all the calculated parameters in output file in scientific notation
write<<scientific<<t<<"\t"<<rel_R <<"\t"<<R <<"\t"<<(Lx/L)<<"\t"<<(Ly/L)<<"\t";//1,2,3,4,5
write<<scientific<<(Lz/L)<<"\t"<<e <<"\t"<<1/a<<"\t"<<Lx<<"\t"<<Ly<<"\t"<<Lz<<"\t";//6,7,8,9,10,11
write<<scientific<<Rx<<"\t"<<Ry<<"\t"<<Rz<<"\t"<<L<<"\t"<<rel_Rx<<"\t"<<rel_Ry<<"\t";//12,13,14
write<<scientific<<rel_Rz<<"\t"<<rel_Vx<<"\t"<<rel_Vy<<"\t"<<rel_Vz<<endl;
}
read.close();
write.close();
cout<<"Done!";
}

main()
{
	//'computer' function is called with input binary evolution file and output file 
	//addresses. The function actual extracts all the parameters.
	//compute("E:/Dropbox/Studies/Paper 2/Data/rot-180-counter0.25/bh.dat","E:/Dropbox/Studies/Paper 2/Data/rot-180-counter0.25/rot-180-counter0.25_parameters.txt");
	compute("../../Data/rot-co-0.25/O_0.25-hr-movie_bh.dat","../../Data/rot-co-0.25/O_0.25-hr-movie_my_param.dat");

}
