// This code is used for scaling Galaxy Model Units with physical units.
//The mass of galaxy taken in this model is 1 and the mass of central SMBH is 0.005.
//We have converted Model mass and influence radius to physical units by equating them
//with masses and influence radius of real galaxies.

#include<iostream>
#include<math.h>
using namespace std;


//class for refrenced galaxies or the real galaxies
class Ref_galaxies 
{public:
 double mass_BH,rh; //declaring variables for mass and influence radius of real galaxies



};
//class for model galaxy 
class model_galaxy 
{public:
double mass_BH,rh; //declaring variables for mass and influence radius for model galaxy

	
double infrad(float rs,float Ms,float g) // function to calculate influence radius
{float p; //Ms is mass of stars, rs is scale radius, g is gamma
	p=1/(3-g);
	rh=(rs*pow(Ms,p))/(1-pow(Ms,p)); // equation to compute scale radius
	//this equation is obtained by manipulating the equation "Ms= (rh/rh+rs)^3-g"
	// Note: Mass of galaxy is taken to be 1,thats why not included in equation
	return rh;
}
	
	
};

//Main Body
int main()
{   // defining real galaxies
	Ref_galaxies M87; //M87 is giant elliptical galaxy
	Ref_galaxies N4486A; // A galaxy in virgo constellation
	Ref_galaxies M32; //A satellite galaxy of andromedda galaxy
	
	//Masses of galaxies are written below with units in solar masses
	//Infuence radius is written in Parsec
	// Masses and ifluence radius of these galaxies have been taken from 
	//(Khan et al. 2012)
	M87.mass_BH=3.6e9;
	M87.rh=460;
	N4486A.mass_BH=1.3e7;
	N4486A.rh=31;
	M32.mass_BH=3.1e6;
	M32.rh=3;
	
	//declaring model galaxy. 
	//Note: A,B and D are not three galaxies but rather used to scale the
	// model galaxy with three galaxies
	model_galaxy A;
	model_galaxy B;
	model_galaxy D;
	
	//Below is the mass of SMBH in model galaxy
	//Mass of SMBH is taken to be 0.5 percent of the model galaxy i.e. Mgal x 0.5%
	A.mass_BH=0.005;
   	B.mass_BH=0.005;
	D.mass_BH=0.005;
	
 /*scaling mass of galaxy models to physical units by dividing real galaxy's
 SMBH mass with model galaxy's SMBH.
The output arrives in physical units*/
double Mass_unitA=M87.mass_BH/A.mass_BH;
double 	Mass_unitB=N4486A.mass_BH/B.mass_BH;
double	Mass_unitD=M32.mass_BH/D.mass_BH;


/*scaling length to physical units by dividing influence radius of SMBH
 both real/reference galaxies with model galaxy
in the function to calculate influence radius scale radius is 1,
 Mass of stars is 0.01 as the influence radius of SMBH is defined
 as the region covered where mass of stars become twice the mass of SMBH
where gamma is taken to be 0.5,1 and 1.5,different for all three
output is divided by 1000 to convert to kiloparsec*/
double length_unitA=(M87.rh/A.infrad(1,0.01,0.5))/1000;
double length_unitB=(N4486A.rh/B.infrad(1,0.01,1))/1000;
double length_unitD=(M32.rh/D.infrad(1,0.01,1.75))/1000;



//output mass units i.e. displaying output in solar mass
cout<< "Mass unit for model A= "<<Mass_unitA<<"\t"<<"Solar mass"<<endl;
cout<< "Mass unit for model B= "<<Mass_unitB<<"\t"<<"Solar mass"<<endl;
cout<<"Mass unit for model D= "<<Mass_unitD<<"\t"<<"Solar mass"<<endl
<<endl<<endl;

//output length units i.e. displayng output in kilo parsec
cout<< "Length unit for model A="<<length_unitA<<" kpc"<<endl;
cout<< "Length unit for model B="<<length_unitB<<" kpc"<<endl;
cout<< "Length unit for model D="<<length_unitD<<" kpc"<<endl<<endl<<endl;

//Simplification of units for calculations of time unit i.e dropping the exponent term
Mass_unitA = Mass_unitA/1e11;
Mass_unitB= Mass_unitB/1e11;
Mass_unitD= Mass_unitD/1e11;


/*Calculations for time unit i.e the time in model units taken for
 simulations to be performed*/
 // This relation is taken from (Khan et al. 2012)
double Time_unitA=((1.5)*(pow(Mass_unitA,-0.5))*(pow(length_unitA,1.5)));
double Time_unitB=((1.5)*(pow(Mass_unitB,-0.5))*(pow(length_unitB,1.5)));
double Time_unitD=((1.5)*(pow(Mass_unitD,-0.5))*(pow(length_unitD,1.5)));

//Display of time unit results i.e. displayng output in Mega years
cout<<"Time unit for model A="<<Time_unitA<<" Myr"<<endl;
cout<<"Time unit for model B="<<Time_unitB<<" Myr"<<endl;
cout<<"Time unit for model D="<<Time_unitD<<" Myr"<<endl<<endl<<endl;



//Calculation for velocity units
//// This relation is also taken from (Khan et al. 2012)
double velocityA=((655)*(pow(Mass_unitA,0.5))*(pow(length_unitA,-0.5)));
double velocityB=((655)*(pow(Mass_unitB,0.5))*(pow(length_unitB,-0.5)));
double velocityD=((655)*(pow(Mass_unitD,0.5))*(pow(length_unitD,-0.5)));

//Display of velocity in units i.e in terms of speed of light
cout<<" Speed of light for model A="<<3e8/(1e3*velocityA)<<" "<<endl;
cout<<" Speed of light for model B="<<3e8/(1e3*velocityB)<<" "<<endl;
cout<<" Speed of light for model D="<<3e8/(1e3*velocityD)<<" "<<endl;




/* Note the values for gamma, scale radius, Mass of stars, Mass of galaxy and SMBH
can vary for different models used but the equations are similar as used here*/


return 0;
}
