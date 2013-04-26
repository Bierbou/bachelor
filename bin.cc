#include<iostream>
#include<cmath>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;


vector<int> binning(/*float j,*/ vector<float> v)//deifniere vektoren je nach anzahl der bins
{
  vector<int> a;
 vector<int> b;
  vector<int> c;
  vector<int> d;
  vector<int> e;
  vector<int> f;
  vector<int> g;
  vector<int> h;
  vector<int> k;
  vector<int> l;
 for(int i =0 ; i<v.size(); ++i)
    {float x = v[i];
      int z = int(x*10);

      if (x<0.1);
      a.push_back(z);
      /* if(x> 0.1 && x<0.2);
      b.push_back(z);
      if(x> 0.2 && x<0.3);
      c.push_back(z);
      if(x> 0.3 && x<0.4);
      d.push_back(z);
      if(x> 0.4 && x<0.5);
      e.push_back(z);
      if(x> 0.5 && x<0.6);
      f.push_back(z);
      if(x> 0.6 && x<0.7);
      g.push_back(z);
      if(x> 0.7 && x<0.8);
      h.push_back(z);
      if(x> 0.8 && x<0.9);
      k.push_back(z);
      if(x> 0.9 && x<1.0);
      l.push_back(z);*/
    }
  return a;
  /* return b;
  return c;
  return d;
  return e;
  return f;
  return g;
  return h;
  return k;
  return l;

  cout<< " 1.bin: "<<a.size()<<endl;
  cout<< " 2.bin: "<<b.size()<<endl;
  cout<< " 3.bin: "<<c.size()<<endl;
  cout<< " 4.bin: "<<d.size()<<endl;
  cout<< " 5.bin: "<<e.size()<<endl;
  cout<< " 6.bin: "<<f.size()<<endl;
  cout<< " 7.bin: "<<g.size()<<endl;
  cout<< " 8.bin: "<<h.size()<<endl;
  cout<< " 9.bin: "<<k.size()<<endl;
  cout<< "10.bin: "<<l.size()<<endl;*/
}
