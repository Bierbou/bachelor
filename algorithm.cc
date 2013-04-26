#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<math.h>
using namespace std;


vector<float> algorithm(float n , vector<float> v)  //definiere Vektor gibt Vektor

{
  vector<float> y;                          // in Vektor y wird geschrieben 
  for(int i = 0 ; i<v.size(); ++i)          // übergibt v[i] an Funktion
    {float z = v[i];
      float x = (1-exp(log(z)/(n+1)));
      y.push_back(x);
    }	

  return y;                                // gibt Vektor zurück

}
