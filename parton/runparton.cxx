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

  string name;
  cout<< "input filename"<<endl;
  cin>> name;
  ofstream ofs(name.c_str());
  if(!ofs) cout<<"can't write file\n";
  ofs<< "Transverse rn\t"<<endl;
  for(size_t i=0; i< random_numbers.size(); ++i) 
    ofs<<"  "<<random_numbers[i]<<endl;
  ofs.close();
  return 0;
}

