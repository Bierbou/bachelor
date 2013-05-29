// ***************************************************************
// This file was created using the CreateProject.sh script.
// CreateProject.sh is part of Bayesian Analysis Toolkit (BAT).
// BAT can be downloaded from http://www.mppmu.mpg.de/bat
// ***************************************************************

#ifndef __BAT__PARTON__H
#define __BAT__PARTON__H

#include <BAT/BCModel.h>

// This is a parton header file.
// Model source code is located in file parton/parton.cxx

// ---------------------------------------------------------
class parton : public BCModel
{
   public:

      // Constructors and destructor
      parton();
      parton(const char * name);
      ~parton();

      // Methods to overload, see file parton.cxx
      void DefineParameters();
      double LogAPrioriProbability(const std::vector<double> &parameters);
      double LogLikelihood(const std::vector<double> &parameters);
      // void MCMCIterationInterface();
};

void draw_random(std::vector<double> & random_numbers, unsigned power);
void plot(const std::vector<double> & random_numbers, unsigned count);
// ---------------------------------------------------------

#endif

