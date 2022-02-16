//The code gives overall resultant rotation to the objects of a galaxy within a certain
//radius. A non-rotational model in inputed in the program and z-component of angular 
//momentum (Lz) of all its objects is computed. Provided an object lies within the 
//required radius range and its Lz is negative, its total angular momentum is inverted.
// As a result of this inversion, all the objects within the radius range get positive 
//Lz which means all of them are moving about z-axis now. When this happens, we call 
//the obtained model to be rotational within the radius range. This published instance
//of the program gives resultant rotation to objects within influence radius of super-
//massive black hole binary of the galaxy model

#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

//'influence_radius' function computes the influence radius of supermassive black hole 
//binary. Three boday scattering starts here.
double influence_radius(double g,double rs,double Ms)
{
	double t=1/(3-g);
	double Rh= (rs*pow(Ms,t))/(1-pow(Ms,t));
	return Rh;	
}

main()
{
ifstream read;
//opening the non-rotational galaxy model file
read.open("E:/Awais/Coding/Angular Momentum Percentages Finder/norot.dat",ios::in); 
ofstream write;
//creating the output galaxy model file
write.open("E:/Tasks/task-introducerotationingalaxy/rot_influence.dat",ios::binary);  

//writing the preamble parameters of galaxy model file after reading them from input model
double t;
int snap,tn;
read>>snap>>tn>>t;
write<<snap<<endl<<tn<<endl<<t<<endl;

//call for calculation of influence radius
double Rh = influence_radius(0.92,0.47,0.02);
cout<<Rh;

//introducing rotation within inlfuence radius
double n,m,Rx,Ry,Rz,Vx,Vy,Vz;
double Lz=0,r;
while(read>>n>>m>>Rx>>Ry>>Rz>>Vx>>Vy>>Vz)
{
	
	Lz=m*(Rx*Vy-Ry*Vx);
	r=sqrt(pow(Rx,2)+pow(Ry,2)+pow(Rz,2));
	if (r<=Rh && Lz<0) //angluar momentum of particles within influence radius and 
					   //negative z-compoent of angular momentum are inverted.
	{
		Vx=-Vx; Vy=-Vy; Vz=-Vz;
	}
	//	writing the output rotational galaxy model
	write<<scientific<<n<<"\t"<<m<<"\t"<<Rx<<"\t"<<Ry<<"\t"<<Rz<<"\t"<<Vx<<"\t"<<Vy<<"\t";
	write<<Vz<<endl; 
}
read.close();
write.close();
cout<<'\a';
}	
