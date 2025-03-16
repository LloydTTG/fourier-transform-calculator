#include <iostream>
#include "include/DFT.h"
#include "include/SignalReconstruction.h"

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
    cout << "Do you want to compute DFT or IDFT?: ";
    cin >> choice;

    if (choice == "DFT"){
        cout << "DFT Outputs: \n";
        CVector output = DFT(input);
        cout << "Reconstructed Signal Components: \n";
        originalFunc(output, N);
    }
    else if (choice == "IDFT"){
        cout << "IDFT Outputs (original samples): ";
        IDFT(input);
    }
    return 0;
    
}