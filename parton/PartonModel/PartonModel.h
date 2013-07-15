// ***************************************************************
// This file was created using the CreateProject.sh script.
// CreateProject.sh is part of Bayesian Analysis Toolkit (BAT).
// BAT can be downloaded from http://www.mppmu.mpg.de/bat
// ***************************************************************

#ifndef __BAT__PARTONMODEL__H
#define __BAT__PARTONMODEL__H

#include <BAT/BCModel.h>

#include <TH1D.h>
// This is a PartonModel header file.
// Model source code is located in file PartonModel/PartonModel.cxx

// ---------------------------------------------------------
class PartonModel : public BCModel
{
   public:

  /**
   * Compute model prediction for a single bin
   *
   * @param xmin : Is the lower boundary of the bin
   * @param xmax : Is the upper boundary of the bin
   * @param parameters 
   */
  virtual double Predict(double xmin, double xmax,const std::vector<double> &parameters)=0;
  virtual ~PartonModel() =0;

      // Constructors and destructor

  PartonModel(const char * name="");

  virtual void DefineParameters()=0;
      double LogAPrioriProbability(const std::vector<double> &parameters);
      double LogLikelihood(const std::vector<double> &parameters);
      // void MCMCIterationInterface();
 private:
      static TH1D* ReadData(const char * filename);

      TH1D data;
};

class SimpleModel : public PartonModel
{
public:

  SimpleModel(const char * name="");
  virtual void DefineParameters();
  virtual double Predict(double xmin, double xmax,const std::vector<double> &parameters);
  virtual ~SimpleModel();
 private:
};

class MixtureModel : public PartonModel
{
 public:

  MixtureModel(const char * name="");
  virtual void DefineParameters();
  virtual double Predict(double xmin, double xmax,const std::vector<double> &parameters);
  virtual ~MixtureModel();
 private:


};
// ---------------------------------------------------------

#endif

