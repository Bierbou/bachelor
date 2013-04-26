#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include"algorithm.h"
#include"bin.h" 
#include<fstream>
#include<string>
using namespace std;

int main()
{
  vector<float> v(1000);
  vector<float> u(1000);
  string name;
  vector<int> b;
vector<int> a;
  cout<<"Programm für Zufallszahlen und Verteilungen"<<endl;

  for(int i = 0; i <v.size(); ++i)    // random Zahl zwischen 0 und 1 in Vektor 
    { float a =(float)rand()/(float)RAND_MAX;          // schreiben
      v[i]= a;
    }
  // cout<< "Zufallswerte"<<endl;
  //for(int i = 0; i <v.size(); ++i) //nur zum auslesen
  // cout<<v[i]<< endl;


   cout<< "n eingeben...\n ";
    float n;
    cin>> n;
    u = algorithm(n,v);
    // cout<<" y(x)"<<endl;
    // for(int i= 0; i <u.size(); ++i) //nur zum auslesen
      // cout<<u[i]<< endl;

    cout<<"output filename\n"; //outpufile kreiren und in dieses schreiben
  cin>>name;
  ofstream ofs(name.c_str());
  if(!ofs) cout<<"can't write file\n";
  ofs<< "Zufallswerte\t"<<"  y(x)"<<endl;
  for(int i=0; i<1000; ++i) 
    ofs<<"  "<<v[i]<<"  \t"<<u[i]<<endl;
  ofs.close();

  b = binning(v);


  for(int i=0; i<b.size(); ++i)
    cout<<b[i]<<endl;
  cout<<b.size()<<endl;
  cout<< " 1.bin: "<<a.size()<<endl;
  /*  cout<<"filename/path!\n"; //aus Datei in Vekor lesen
  cin>>name;
  ifstream ifs(name.c_str());
  if(!ifs) cout<<"can't read file\n";
  string s;
  vector<string> b;
  float vtemp;
  float utemp;
  float wtemp;
  bool a=true;
  while (a)
    for(int i=0; i<1000; i++)
      {
	ifs>>vtemp>>utemp>>wtemp;
	cout<<vtemp<<"\t"<<utemp<<"\t"<<wtemp<<endl;
	v[i]=vtemp; u[i]=utemp; w[i]=wtemp;

	}
   b.push_back(s);
    // if (ifs.eof()) return 0;
  // ifs.close();
  for(int i=0; i<v.size(); ++i){
    cout<< b[i];
    }*/
}
