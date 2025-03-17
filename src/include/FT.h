#ifndef DFT_H
#define DFT_H

#include <vector>
#include <complex>
#include <valarray>

using namespace std;

const double pi = M_PI;

typedef complex<double> Complex;
typedef vector<Complex> CVector;
typedef valarray<Complex> CArray;

CVector DFT(const CVector& input);
CVector IDFT(const CVector& input);
void FFT(CArray& input);
// void IFFT(CArray& input);

CArray vectorToArray(const std::vector<Complex>& inputVect);
CVector complexToVector(const std::complex<double>& input);

#endif