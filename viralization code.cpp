#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main()
{

float data[2][8], k,m1,X1,Y1,Z1,Vx1,Vy1,Vz1, l, m2,X2,Y2,Z2,Vx2,Vy2,Vz2;
float G=1;
ifstream myfile ;
myfile.open("F:/BS-Space Sciences/Final Year Project/Tasks/task 1/data.txt");
for(int i=0; i<=1; i++)
{
	for (int j=0;j<8;j++)
	{
		myfile>>data[i][j];
	}
}
k=data[0][0];
m1=data[0][1];
X1=data[0][2];
Y1=data[0][3];
Z1=data[0][4];
Vx1=data[0][5];
Vy1=data[0][6];
Vz1=data[0][7];
l=data[1][0];
m2=data[1][1];
X2=data[1][2];
Y2=data[1][3];
Z2=data[1][4];
Vx2=data[1][5];
Vy2=data[1][6];
Vz2=data[1][7];
//cout<<k<<"\t"<<m1<<"\t"<<X1<<"\t"<<Y1<<"t"<<Z1<<"\t"<<Vx1<<"\t"<<Vy1<<"\t"<<Vz1<<"\n" <<l<<"\t"<<m2<<"\t"<<X2<<"\t"<<Y2<<"\t"<<Z2<<"\t"<<Vx2<<"\t"<<Vy2<<"\t"<<Vz2<<"\n";
float r1=sqrt(pow(X1,2)+pow(Y1,2)+pow(Z1,2));
float r2=sqrt(pow(X2,2)+pow(Y2,2)+pow(Z2,2));

//distance between the two bodies
float del_X=X2-X1; float del_Y=Y2-Y1; float del_Z=Z2-Z1;
float r=sqrt(pow(del_X,2)+pow(del_Y,2)+pow(del_Z,2));

float V1=sqrt(pow(Vx1,2)+pow(Vy1,2)+pow(Vz1,2));
float V2=sqrt(pow(Vx2,2)+pow(Vy2,2)+pow(Vz2,2));
float del_Vx=Vx2-Vx1; float del_Vy=Vy2-Vy1; float del_Vz=Vz2-Vz1;
//relative velocity
float rel_V=sqrt(pow(del_Vx,2)+pow(del_Vy,2)+pow(del_Vz,2));

//redeced mass
float red_m= ((m1*m2)/(m1+m2));

//center of mass
float R=((m1*r1+m2*r2)/(m1+m2));

//toatal energy
float E=(0.5*(red_m*pow(rel_V,2)))-(G*m1*m2/r);

//Angular Momentum
float L=(red_m*r*rel_V);

//Eccentricity
float e= sqrt(1+((2*E*pow(L,2)/(red_m*pow(G*m1*m2,2)))));

//Semi-major axis
float sm_axis=-G*((m1+m2)/(2*E));

//Kinetic energry
float T=(0.5*(red_m*pow(rel_V,2)));

//potential energy
float U=(G*(m1+m2)/r);

//Virial theorem
if (U=2*T)
{
	cout<<"Virial theorem Proved"<<endl;
}
else 
cout<<"Virial Theorem not verified:"<<endl;

cout<<"Center of Mass:"<<R<<endl;
cout<<"Toatal Energy:"<<E<<endl;
cout<<"Angular Momentum:"<<L<<endl;
cout<<"Eccentricity:"<<e<<endl; 
cout<<"Semi-major Axis:"<<sm_axis<<endl;

ofstream write;

write.open("F:/BS-Space Sciences/Final Year Project/Tasks/task 2/results.txt",ios::binary);
write<<R<<" "<<E<<" "<<L<<" "<<e<<" "<<sm_axis;
write.close();
return 0;
}