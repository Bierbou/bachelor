#include <TCanvas.h>
#include <TH1.h>
#include <TRandom3.h>

#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

/**
 * Draw random according to (1-x)^n
 *
 * @param storage Size determines number of random numbers.
 * @param power The exponent n.
 */
void draw_random(vector<double> & random_numbers, unsigned power)
{
  TRandom3 rng;
  rng.SetSeed(657767645); 
  for(size_t i = 0; i < random_numbers.size() ; ++i)
    {
      // inverse transform
      random_numbers[i] = 1 - exp(log(rng.Rndm()) / (power + 1));
    }
}

TH1D histogram_factory(const vector<double> & random_numbers, double min, double max, unsigned nbins)
{
  // name, title, equal-sized bins
  TH1D histo(TString::Format("Markus' first histo %u", nbins), "Distribution", nbins, min, max);
  for(size_t i = 0; i < random_numbers.size() ; ++i)
    {
      histo.Fill(random_numbers[i]);
    }
  histo.Scale(1.0 / histo.Integral() / histo.GetBinWidth(1));
  return histo;
}

// todo document
void plot(const vector<double> & random_numbers, unsigned count)
{
  static const double min = 0;
  static const double max = 1;

  // name is c1, empty title, width, height in pixels
  TCanvas canvas("c1","", 800, 400);

  histogram_factory(random_numbers, min, max, count).Draw();

  canvas.Print("rn.pdf");
}
