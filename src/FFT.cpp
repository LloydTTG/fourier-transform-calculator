#include "include/FT.h"
#include <iostream>

void FFT(CArray& input){
    const size_t N = input.size();
    if (N <= 1) return;

    CArray even = input[slice(0, N/2, 2)];
    CArray odd = input[slice(1, N/2, 2)];

    FFT(even);
    FFT(odd);

    for (size_t k = 0; k < N/2; k++){
        Complex expFunc = polar(1.0, -2 * pi * k / N) * odd[k];
        input[k] = even[k] + expFunc;
        input[k + N/2] = even[k] - expFunc;
    }
    
}

