#include "parton.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{ 
  static const unsigned N = 10000;
  unsigned power;
  unsigned count;
  cout<<"Program for parton distribution functions"<<endl;
  cout<<"Please choose power..."<<endl;
  cin>>power;
  cout<<"How much bins do you want?"<<endl;//number of bins
  cin>>count;


  vector<double> random_numbers(N);
  draw_random(random_numbers, power);
  plot(random_numbers, count);
#if 0
  string name;
  cout<< "input filename"<<endl;
  cin>> name;
  ofstream ofs(name.c_str());
  if(!ofs) cout<<"can't write file\n";
  ofs<< "Transverse rn\t"<<endl;
  ofs<< "Transverse rn\t"<<"binned data"<<endl;
  for(size_t i=0; i< random_numbers.size(); ++i) 
    ofs<<"  "<<random_numbers[i]<<endl;
  ofs<<"  "<<random_numbers[i]<<"\t"<<endl;
  ofs.close();
#endif
  return 0;
}

