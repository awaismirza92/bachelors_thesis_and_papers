#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;

void compute(string input_filename, string output_filename)//,string output)
{
	ifstream read;
read.open(input_filename.c_str(),ios::in);
double *rel_R=NULL;
rel_R=new double [122400];
int G=1,norb=0; double rel_Rx, rel_Ry, rel_Rz, V1,V2,rel_Vx,rel_Vy,rel_Vz,rel_V,r1,r2,R,E,Lx,Ly,Lz,L,e,a;//,rel_R
double t,Rx1,Ry1,Rz1,Vx1,Vy1,Vz1,Rx2,Ry2,Rz2,Vx2,Vy2,Vz2,Rx,Ry,Rz;
double ind1,ind2,aa,b,c,d,ee,f,g,h,i,j,k,l,m,n,o,p;
double m1, m2,red_m,u;
double ra,rp,ecc;
ofstream write,write1;
write.open(output_filename.c_str(),ios::binary);
//write1.open(output.c_str(),ios::binary);
int count=0;
while(read>>t>>ind1>>m1>>Rx1>>Ry1>>Rz1>>Vx1>>Vy1>>Vz1>>aa>>b>>c>>d>>ee>>f>>g>>h>>ind2>>m2>>Rx2>>Ry2>>Rz2>>Vx2>>Vy2>>Vz2>>i>>j>>k>>l>>m>>n>>o>>p)
{	
rel_Rx=Rx2-Rx1; rel_Ry=Ry2-Ry1; rel_Rz=Rz2-Rz1;
rel_R[count]=sqrt(pow(rel_Rx,2)+pow(rel_Ry,2)+pow(rel_Rz,2));
//	write1<<t<<"\t"<<rel_R[count]<<endl;


 if (rel_R[count-2]<rel_R[count-1] && rel_R[count]<rel_R[count-1] && t<40)
{
	 ra=rel_R[count-1];
	 
//cout<<count<<"\t"<< ra<<"\t"<<rel_R[count+1]<<endl;
	}
	else if (rel_R[count-2]>rel_R[count-1] && rel_R[count]>rel_R[count-1]&&t<40)
	{norb=norb+1;
		 rp=rel_R[count-1];
		 ecc=(ra-rp)/(ra+rp);
		 //cout<<rp<<endl;
		 //write<<norb<<"\t"<<t<<"\t"<<ecc<<endl;//"\t"<<ra<<"\t"<<rp<<"\t"<<endl;
		 write<<norb<<"\t"<<t<<"\t"<<ecc<<"\t"<<ra<<"\t"<<rp<<endl;
	}
//	double e=ra-rp/ra+rp;
	//write<<t<<"\t"<<e<<endl;
count++;

}




read.close();
write.close();
}

main()
{
//	compute("C:/Users/Afnan/Dropbox/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/In plane - Dr Fazeel/bh-paramr21.dat","C:/Users/Afnan/Dropbox/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/In plane - Dr Fazeel/bh-paramr21_results_eccentr.dat");//"C:/Users/Afnan/Dropbox/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-Co-0.3-relr");
//	compute("C:/Users/Afnan/Dropbox/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/In plane - Dr Fazeel/bh-paramrc21.dat","C:/Users/Afnan/Dropbox/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/In plane - Dr Fazeel/bh-paramrc21_results_eccentr.dat");
	//compute("E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-45-co.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh_co45/bh-45-co_eccentricity.dat");
	//compute("E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh90/bh90_rel-eccentricity.dat");
	compute("/e_drive/MEGA/Research/SMBHs/Paper 2/Data/rot-180-counter0.5/bh.dat","/e_drive/MEGA/Research/SMBHs/Paper 2/Data/rot-180-counter0.5/rot-180-counter0.5_rel-eccentricity_check_bh.txt");
	//compute("E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90.dat","E:/Dropbox/Studies/FYP/codes and plots/Tasks/task - e and a extraction from snaps/bhdata/bh-90_results.dat");
}
