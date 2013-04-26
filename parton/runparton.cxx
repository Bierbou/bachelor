#include <TH1.h>
#include <TCanvas.h>

#include<cstdlib>
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
   for(size_t i = 0; i < random_numbers.size() ; ++i)
   {
      // uniform RN
      double u = (double)rand() / (double)RAND_MAX;
      // inverse transform
      random_numbers[i] = 1 - exp(log(u) / (power + 1));
   }
}

// todo document
void plot(const vector<double> & random_numbers, double min, double max, unsigned nbins=50)
{
   TH1D histo("Markus' first histo", "Distribution", nbins, min, max);
   for(size_t i = 0; i < random_numbers.size() ; ++i)
   {
      histo.Fill(random_numbers[i]);
   }

   TCanvas canvas("c1","", 800, 400);

   histo.Draw();
   canvas.Print("rn.pdf");
}

int main()
{
   static const unsigned N = 1000;
   static const unsigned power = 2;

   vector<double> random_numbers(N);
   draw_random(random_numbers, power);
   plot(random_numbers, 0, 1);

   return 0;
}

