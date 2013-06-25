#include "parton.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{ 
  static const unsigned N = 10000;
  unsigned power;
  unsigned count;
  cout<<"Program for whatever"<<endl;
  cout<<"Please choose power..."<<endl;
  cin>>power;
  cout<<"How much bins do you want?"<<endl;//number of bins
  cin>>count;


  vector<double> random_numbers(N);
  draw_random(random_numbers, power);
  plot(random_numbers, count);

  return 0;
#if 0
  string name;
  cout<<"Output filename"<<endl;
  cin>>name;
  ofstream ofs(name.c_str());
  if(!ofs) cout<<"can't write file\n";
  ofs<< "Histogrambins\t"<<endl;
  //for(size_t i=0; i< histos.size(); ++i) 
    ofs<<"  "<<histo<<endl;
  ofs.close();
#endif
}

