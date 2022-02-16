#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
double pi=3.14159;

void transform_xz(double vector[],double phi_trans)
{
	
	double L_mag=sqrt(pow(vector[0],2)+pow(vector[1],2)+pow(vector[2],2));
	
	cout<<"Angle b/w New and Old Z-axis: "<<acos(fabs(vector[2])/L_mag)*180/pi;
	cout<<endl<<endl;
	
	cout<<vector[0]<<endl; cout<<vector[1]<<endl;cout<<vector[2]<<endl<<endl;			
	
	cout<<"L= "<<L_mag<<endl<<endl;
	
	phi_trans=atan(fabs(vector[1])/fabs(vector[2]));
	cout<<"About x: "<<phi_trans*180/pi<<endl;
	
	cout<<endl;
	
	
	
	double trans_array[3][3]={{1,0,0},
							 {0,cos(phi_trans),sin(-phi_trans)},
							 {0,-sin(-phi_trans),cos(phi_trans)}};

							 
	long double v_trans[3],new_vector[3];
	
	for(int i=0;i<=2;i++)
		{v_trans[i]=0;
		} 
		
	for(int i=0; i<=2;i++)
	{
		for (int j=0; j<=2;j++)
		{v_trans[i] += trans_array[i][j]*vector[j];}//	cout<<"mat: "<<trans_array[i][j]<<"\t"<<"org_v: "<<vector[j]<<"\t"<<"v_trans: "<<v_trans[i]<<endl;}
		cout<<v_trans[i]<<endl;
		new_vector[i]=v_trans[i];
	}
	cout<<endl;
	L_mag=sqrt(pow(new_vector[0],2)+pow(new_vector[1],2)+pow(new_vector[2],2));
	cout<<"L= "<<L_mag<<endl<<endl;
	
	phi_trans=atan(fabs(new_vector[0])/fabs(new_vector[2])); cout<<"About y: "<<phi_trans*180/pi<<endl<<endl;
	
	double	trans_array2[3][3]={{cos(phi_trans),0,-sin(phi_trans)},
						{0,1,0},
						{sin(phi_trans),0,cos(phi_trans)}};
						
	
	
	for(int i=0;i<=2;i++)
		{v_trans[i]=0;
		} 
		
	for(int i=0; i<=2;i++)
	{
		for (int j=0; j<=2;j++)
		{v_trans[i] += trans_array2[i][j]*new_vector[j];}//cout<<"mat: "<<trans_array2[i][j]<<"\t"<<"org_v: "<<new_vector[j]<<"\t"<<"v_trans: "<<v_trans[i]<<endl;}		
		cout<<v_trans[i]<<endl;
	}
	cout<<endl;
	L_mag=sqrt(pow(v_trans[0],2)+pow(v_trans[1],2)+pow(v_trans[2],2));
	cout<<"L= "<<L_mag<<endl<<endl;
	
		
	
	double v_mag=sqrt(pow(v_trans[0],2)+pow(v_trans[1],2)+pow(v_trans[2],2));
	
	//double phi_rad = acos(fabs(L[2])/L_mag);
	cout<<acos(fabs(v_trans[2])/v_mag)*180/pi<<endl;
	//cout<<r_trans[0]/r_trans[2];
}

main()
{ 	double r[3]={0.000332117,0.000535554,-0.000613144};
	double r_mag = sqrt(pow(r[0],2)+pow(r[1],2)+pow(r[2],2)); //cout<<r_mag<<endl;
	double v[3]={-1.44221,-1.44626,2.17682};
	double v_mag = sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2)); //cout<<v_mag<<endl;
	
	double L_mag,L[3];
	L[0]=(r[1]*v[2]-r[2]*v[1]); 
	
	L[1]=(r[2]*v[0]-r[0]*v[2]);  
	
	L[2]=(r[0]*v[1]-r[1]*v[0]); 
	
//	L[0]=5; L[1]=5; L[2]=5; 
	

	double phi_rad = acos(fabs(L[2])/L_mag);//cout<<phi_rad<<endl;
	double phi_deg=phi_rad*180/pi; //cout<<phi_deg<<endl;
	double phi_trans=phi_rad; //cout<<phi_trans<<endl;//(pi/2)-
	

	
	transform_xz(L,phi_trans);						 
	//transform_xz(r,phi_trans);
	//transform_xz(v,phi_trans);
	

	cout<<'\a';
}

