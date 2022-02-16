//This program determines the percentages of objects with positve, negative and zero
//z-component of angular momentum (Lz). The code first counts the positive and zero Lz
//particles and then calculate their percentages. Negative Lz particles are obtained
//by subtracting positive and zero Lz particles from total number of particles

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//'compute' function determines the percentages of angular momentum
void compute(string input_filename, string output_filename)
{
ifstream read;
//opeing the galaxy model file
read.open(input_filename.c_str(),ios::in);

double n,m,Rx,Ry,Rz,Vx,Vy,Vz;
double Lz=0;
int positive_counter=0, zero_counter=0;

double snap,tn,t;
read>>snap>>tn>>t;
while(read>>n>>m>>Rx>>Ry>>Rz>>Vx>>Vy>>Vz)
{
	
	Lz=m*(Rx*Vy-Ry*Vx);
	if (Lz>0)
	{positive_counter=positive_counter+1;} //counting the particles with positive Lz
	else if (Lz==0)
	{zero_counter=zero_counter+1;} //counting the particles with Lz equal to 0
}
read.close();
//calculating angular momentum percentages
float positive_Lz=(positive_counter)*100/(n+1), zero_Lz=(zero_counter)*100/(n+1), negative_Lz=((n+1)-positive_counter-zero_counter)*100/(n+1);
cout<<"Percentage of Objects with Positive Lz: "<<positive_Lz<<endl;
cout<<"Percentage of Objects with Negative Lz: "<<negative_Lz<<endl;
cout<<"Percentage of Objects with Zero Lz: "<<zero_Lz<<endl;

//writing the percentages
ofstream write;
write.open("output_filename.c_str(),ios::binary);
write<<"Positive Lz: "<<positive_Lz<<"\t"<<"Negative Lz: "<<negative_Lz<<"\t"<<"Zero Lz: "<<"\t"<<zero_Lz<<endl;
cout<<'\a';
}


main()
{
	//compute function being called with addresses of input model file and output 
	//percentages file as argument.
	compute("/","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - Angular momentum percentages Finder/Model Stability/Rotational in Influence Radius/results_0002.dat");
	compute("E:/SkyDrive/Space Sciences/FYP/Awais/Coding/Simulations/Verifying Models/Rotation in Influence Radius/0006.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - Angular momentum percentages Finder/Model Stability/Rotational in Influence Radius/results_0006.dat");
	
}
