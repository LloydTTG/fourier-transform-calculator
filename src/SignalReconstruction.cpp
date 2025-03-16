#include "include/SignalReconstruction.h"
#include "include/DFT.h"
#include <iostream>
#include <cmath>

vector<signalVect> originalFunc(const CVector& output, int N){
    int nyquist = N/2;
    vector<signalVect>  Signal;

    for (int i=0; i < output.size(); i++){
       double frequency = i > nyquist ? i-N : i;
       double amplitude = round(abs(output[i])/N*100)/100;
       double phase = round(arg(output[i])*100)/100;
        Signal.push_back({amplitude, frequency, phase});
        }
    for (int i = 0; i < N; i++){
        cout << Signal[i].amplitude << "cos(2pi(" << Signal[i].frequency << "t) + " << Signal[i].phase << ")" << endl;
    }
    return Signal;
}