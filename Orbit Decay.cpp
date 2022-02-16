#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
using namespace std;

int calculate(long double dt,// time step
 double s, // inverse semi-major rate
 double end_time, // ending time of orbit integration
 double e,  //eccentricity of orbit
 string filename) // output file name; contains relative positions of one BH w.r.t other,i.e., orbit path
{
		long double v[3]={-1.44221,-1.44626,2.17682}; // initial three components of relative velocity of one BH w.r.t other
		long double r[3]={0.000332117,0.000535554,-0.000613144}; //initial three components of relative position of one BH w.r.t other
		long double ac[3]; //relative acceleration of one BH w.r.t other
		double m1=0.005, m2=0.005; // masses of both BHs
		double G=1; //gravitational constant
		double u=G*(m1+m2); //standard gravitational parameter
		
	ofstream write(filename.c_str()); //'write' will be used for writing in the output file
	
	long double Vi = sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2)); //initial velocity magnitude
	long double Ri = sqrt(pow(r[0],2)+pow(r[1],2)+pow(r[2],2)); //initial position magnitude
	double Ki = 0.5*pow(Vi,2), Pi=-1/Ri; //initial K.E and P.E
	double Ei = Ki+Pi;// initial total energy
	
	cout<<"Initial Energy: "<<Ei<<endl;
	
	double a=-u/(2*Ei); cout<<"Initial Semi-major Axis: "<<a<<endl; //initial semi-major axis
	double T=2*3.1415*sqrt(pow(a,3)/u); cout<<"Orbital Period: "<<T<<endl; //orbital period
	dt = T/500; cout<<"Time Step: "<<dt<<endl;//time step
	
	long double r1=sqrt(pow(r[0],2)+pow(r[1],2)+pow(r[2],2)); //initial position magnitude
	long double r3 = pow(r1,3); //cube of initial position magnitude
	for (int c; c<=2;c++)
	{
		ac[c]= - u*r[c]/r3; //calculation of initial acceleration
	}
	
	double V, R, E,h;
	
	for(long double t=40; t<=end_time;t=t+dt)
	{
		
		for (int c=0; c<=2;c++)
		{
			v[c]=  v[c]+ac[c]*dt*0.5; //calculation of half time-step velocity
			r[c] = r[c]+ v[c]*dt; //calculation to next point's position (at full time-step)
		}
		r1=sqrt(pow(r[0],2)+pow(r[1],2)+pow(r[2],2));
		r3 = pow(r1,3);		
		for (int c=0; c<=2;c++)
		{
			ac[c]= - ((u*r[c])/r3); //updating acceleration using next point's position
			v[c]=  v[c]+ac[c]*dt*0.5; // calcution of velocity at full time-step using updated acceleration
		}
		
		write<<t<<"\t"<<r[0]<<"\t"<<r[1]<<"\t"<<r[2]<<"\n"; // writing of next point position
	
		// Introducing energy loss
		/*
		V = sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2)); // current velocity magnitude
		R = sqrt(pow(r[0],2)+pow(r[1],2)+pow(r[2],2)); // current position magnitude
		E = 0.5*pow(V,2)-1/R; // current total energy
		a=-u/(2*E); //current semi-major axis
		a=a-(s*pow(a,2)*dt); cout<<a<<endl; //decresing semi-major axis,i.e., orbit losing energy
		E=-u/(2*a); // new energy
		h= pow((pow(u,2)*(pow(e,2)-1))/(2*E),1/2); new momentum
		
		STUCK: HOW TO OBTAIN NEW POSITION AND VELOCITY FOR NEXT STEP????????????
		*/
	}
	
	double Vf = sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2)); //final velocity calculation
	double Rf = sqrt(pow(r[0],2)+pow(r[1],2)+pow(r[2],2)); //final position calculation
	double Ef = 0.5*pow(Vf,2)-1/Rf; //final energy calculation
	
	cout<<"Final Energy: "<<Ef<<endl;
	cout<<"Absolute Error: "<<Ef-Ei<<endl; //orbit integration absolute error
	cout<<"Fractional Error: "<<(Ef-Ei)/Ei<<endl<<endl; //orbit integration relative error
	
	cout<<'\a'; //beep at the completion of running of the code
	return 0;
}

int main()
{
	//calculate(0.01,25.3353,"E:/Dropbox/Studies/FYP/codes and plots/Tasks/Orbit Decay/check/old initials path dt=0.01, t=30.txt");
	//calculate(0.001,25.3353,"E:/Dropbox/Studies/FYP/codes and plots/Tasks/Orbit Decay/check/old initials path dt=0.001, t=30.txt");//undecayed orbit.txt
	calculate(0.0001,25.3353,40.01,0.4,"E:/Dropbox/Studies/FYP/codes and plots/Tasks/Orbit Decay/check/new path dt=0.0001, t=30.txt"); //call to funtion 'calculate' for orbit integration
	//calculate(0.000001,25.3353,41,0.4,"E:/Dropbox/Studies/FYP/codes and plots/Tasks/Orbit Decay/check/new path dt=0.000001, t=30.txt");
	return 0;
}
