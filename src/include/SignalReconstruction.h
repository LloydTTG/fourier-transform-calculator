#ifndef SIGNAL_RECONSTRUCTION_H
#define SIGNAL_RECONSTRUCTION_H

#include <complex>
#include <vector>

using namespace std;

typedef struct{
    double amplitude;
    double frequency;
    double phase;
}signalVect;

vector<signalVect> originalFunc(const vector<complex<double>>& output, int N); //const CVector& output

#endif