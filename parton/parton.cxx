// ***************************************************************
// This file was created using the CreateProject.sh script.
// CreateProject.sh is part of Bayesian Analysis Toolkit (BAT).
// BAT can be downloaded from http://www.mppmu.mpg.de/bat
// ***************************************************************

#include "parton.h"

#include <BAT/BCMath.h>

// ---------------------------------------------------------
parton::parton() : BCModel()
{
   // default constructor
   DefineParameters();
}

// ---------------------------------------------------------
parton::parton(const char * name) : BCModel(name)
{
   // constructor
   DefineParameters();
}

// ---------------------------------------------------------
parton::~parton()
   // default destructor
{
}

// ---------------------------------------------------------
void parton::DefineParameters()
{
   // Add parameters to your model here.
   // You can then use them in the methods below by calling the
   // parameters.at(i) or parameters[i], where i is the index
   // of the parameter. The indices increase from 0 according to the
   // order of adding the parameters.

//   AddParameter("x", -10.0, 10.0); // index 0
//   AddParameter("y",  -5.0,  5.0); // index 1
}

// ---------------------------------------------------------
double parton::LogLikelihood(const std::vector<double> &parameters)
{
   // This methods returns the logarithm of the conditional probability
   // p(data|parameters). This is where you have to define your model.

   double logprob = 0.;

//   double x = parameters.at(0);
//   double y = parameters.at(1);
//   double eps = 0.5;

   // Breit-Wigner distribution of x with nuisance parameter y
//   logprob += BCMath::LogBreitWignerNonRel(x + eps*y, 0.0, 1.0);


   return logprob;
}

// ---------------------------------------------------------
double parton::LogAPrioriProbability(const std::vector<double> &parameters)
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
// ---------------------------------------------------------

