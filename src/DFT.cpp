#include "include/DFT.h"
#include <iostream>
#include <cmath>

CVector DFT(const CVector& input){
    int N = input.size();
    CVector output(N);

    for (int k = 0; k < N; k++){ //for loop for frequency bin
        Complex cnum(0.0, 0.0); //set complex number to 0 + 0i
        for (int n = 0; n < N; n++){ //for loop for sample size
            double angle = -2.0 * pi * k * n/N; //following the formula for exp() function
            cnum += ((input[n] * polar(1.0, angle))); //using euler's identity
        }
        output[k] = cnum;
        double mag = abs(cnum);
        double phase = arg(cnum);
        cout << "X[" << k << "] = " << cnum << ", Magnitude = " << round(mag*100)/100 << ", Argument = " << round(phase*100)/100 << ", True Amplitude = " << round(mag*100)/100/N << endl;
    }
    return output;
}

CVector IDFT(const CVector& input){ 
    int N = input.size();
    CVector output(N);

    for(int k = 0; k < N; k++){
        Complex cnum(0.0, 0.0);
        for (int n = 0; n < N; n++){
            double angle = 2.0 * pi * k * n/N;
            cnum += input[n] * polar(1.0, angle) / static_cast<double>(N) ;
        }
    output[k] = cnum;
    cout << "X[" << k << "] = " << cnum << endl;
    }
    return output;
}