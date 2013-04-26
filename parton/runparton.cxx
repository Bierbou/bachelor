#include <TH1.h>
#include <TCanvas.h>

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
    for(size_t i = 0; i < random_numbers.size() ; ++i)
    {
        // uniform RN
        double u = (double)rand() / (double)RAND_MAX;
        // inverse transform
        random_numbers[i] = 1 - exp(log(u) / (power + 1));
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
void plot(const vector<double> & random_numbers)
{
    static const double min = 0;
    static const double max = 1;

    vector<unsigned> bins { 10, 50, 200 };
    vector<TH1D> histos;

    // name is c1, empty title, width, height in pixels
    TCanvas canvas("c1","", 800, 400);

    unsigned j = 0;
    for (auto it = bins.begin() ; it != bins.end(); ++it, ++j)
    {
        histos.push_back(histogram_factory(random_numbers, min, max, *it));
        string option = "same";
        if (it == bins.begin())
            option = "";

        // choose different colors
        histos.back().SetLineColor(1 + j);

        // automatically select c1
        // ROOT's strange memory management needs clone, wtf?
        histos.back().DrawCopy(option.c_str());
    }

    canvas.Print("rn.pdf");
}

int main()
{
    static const unsigned N = 1000;
    static const unsigned power = 2;

    vector<double> random_numbers(N);
    draw_random(random_numbers, power);
    plot(random_numbers);

    return 0;
}

