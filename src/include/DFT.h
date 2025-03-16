#ifndef DFT_H
#define DFT_H

#include <vector>
#include <complex>

using namespace std;

const double pi = M_PI;

typedef complex<double> Complex;
typedef vector<Complex> CVector;

CVector DFT(const CVector& input);
CVector IDFT(const CVector& input);

#endif