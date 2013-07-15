// ***************************************************************
// This file was created using the CreateProject.sh script.
// CreateProject.sh is part of Bayesian Analysis Toolkit (BAT).
// BAT can be downloaded from http://www.mppmu.mpg.de/bat
// ***************************************************************

#include "PartonModel.h"
#if 1
#include <BAT/BCMath.h>

#include <TFile.h>



// ---------------------------------------------------------
PartonModel::PartonModel(const char * name) : BCModel(name), 
					      data(*ReadData("rn.root"))
{
}

// ---------------------------------------------------------
PartonModel::~PartonModel()
   // default destructor
{
}

// ---------------------------------------------------------
TH1D* PartonModel::ReadData(const char * filename) 
{
   TFile f(filename);

   return (TH1D*)f.Get("h1");
}

// --------------------------------------------------------

double PartonModel::LogLikelihood(const std::vector<double> &parameters)
{
  // This methods returns the logarithm of the conditional probability
  // p(data|parameters). This is where you have to define your model.

  double logprob = 0.;
  for(int i=1 ; i<= data.GetNbinsX() ; ++i)
    {
      double xmin = data.GetBinLowEdge(i);
      double xmax = data.GetBinLowEdge(i+1);
      double ni = data.GetBinContent(i);
      double lambdai = Predict(xmin, xmax, parameters);
    
      logprob += ni * log(lambdai) - lambdai;
    }

  return logprob;
}

// ---------------------------------------------------------
double PartonModel::LogAPrioriProbability(const std::vector<double> &parameters)
{
   // This method returns the logarithm of the prior probability for the
   // parameters p(parameters).

   double logprob = 0.;

//   double x = parameters.at(0);
//   double y = parameters.at(1);

//   double dx = GetParameter(0)->GetRangeWidth();

//   logprob += log(1./dx);                    // flat prior for x
//   logprob += BCMath::LogGaus(y, 0., 1.0);   // Gaussian prior for y

   return logprob;
}

// --------------------------------------------------------
SimpleModel::SimpleModel(const char * name)
{
  DefineParameters();
}

// ---------------------------------------------------------
SimpleModel::~SimpleModel()
{
}

// --------------------------------------------------------
void SimpleModel::DefineParameters()
{
   // Add parameters to your model here.
   // You can then use them in the methods below by calling the
   // parameters.at(i) or parameters[i], where i is the index
   // of the parameter. The indices increase from 0 according to the
   // order of adding the parameters.

   AddParameter("a", 0., 10.0); // index 0
}

// ---------------------------------------------------------
double SimpleModel::Predict(double xmin, double xmax, const std::vector<double> &parameters)
{
  const double & a=parameters[0];

  return (pow( 1- xmin, a+1) - pow(1- xmax, a+1))/10000.0;
}

// --------------------------------------------------------
MixtureModel::MixtureModel(const char * name)
{
  DefineParameters();
}

// ---------------------------------------------------------
MixtureModel::~MixtureModel()
{
}

// ---------------------------------------------------------
void MixtureModel::DefineParameters()
{
   // Add parameters to your model here.
   // You can then use them in the methods below by calling the
   // parameters.at(i) or parameters[i], where i is the index
   // of the parameter. The indices increase from 0 according to the
   // order of adding the parameters.

   AddParameter("a", 0., 10.0); // index 0
   AddParameter("b",  0.,  5.0); // index 1
}

// ---------------------------------------------------------
 double MixtureModel::Predict(double xmin, double xmax, const std::vector<double> & parameters)
{
  const double & a = parameters[0];
  const double & b = parameters[1];

  // const double A = (a+1)*4*(b+1)/(4(b+1)+(a+1)); 

  return ((a+1)/(4*(b+1)+(a+1))*pow(1-xmin,b+1)-4*(b+1)/(4*(b+1)+(a+1))*pow(1- xmax,a+1))/1000.0;
}

// ---------------------------------------------------------

#endif
