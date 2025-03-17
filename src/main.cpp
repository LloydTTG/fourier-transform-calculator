#include <iostream>
#include "include/FT.h"
#include "include/SignalReconstruction.h"


CArray vectorToArray(CVector& input){
    return CArray(input.data(), input.size());
}

CVector complexToVector(Complex& input){
    return std::vector<Complex>{input};
}

int main(){
    int N;
    cout << "Enter sample size: ";
    cin >> N;

    CVector input(N);
    CVector output(N);
    cout << "Enter real and imaginary parts of " << N << " samples:" << endl;
    for(int i = 0; i < N; i++){
        double realPart,imaginaryPart;
        cout << "Enter real part of sample " << i+1 << ":" << endl;
        cin >> realPart;
        cout << "Enter imaginary part of sample " << i+1 << ":" << endl;
        cin >> imaginaryPart;
        input[i] = Complex(realPart, imaginaryPart);
    }

    string choice;
    cout << "Do you want to compute DFT, IDFT or FFT?: ";
    cin >> choice;

    if (choice == "DFT"){
        cout << "DFT Outputs: \n";
        CVector output = DFT(input);
        cout << "Reconstructed Signal Components: \n";
        originalFunc(output, N);
    }

    else if (choice == "IDFT"){
        cout << "IDFT Outputs (original samples): \n";
        IDFT(input);
    }

    else if (choice == "FFT"){
        cout << "FFT Outputs: \n";
        CVector inputVect;
        inputVect.reserve(N);
        for (int i = 0; i < N; i++){
        inputVect.push_back(input[i]);
        }
        CArray data = vectorToArray(inputVect);
        FFT(data);

        for (size_t a = 0; a < data.size(); a++){
        cout << data[a] << endl;
        }
    
    }
    return 0;
}