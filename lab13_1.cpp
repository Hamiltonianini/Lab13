#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double sum = 0;
    for(int i=0; i<N; i++) sum += A[i];
    B[0] = sum/N;

    double diffSum = 0;
    for(int j=0; j<N; j++) diffSum += pow(A[j]-B[0],2);
    B[1] = sqrt(diffSum/N);

    double geoSum = 1;
    for(int k=0; k<N; k++) geoSum *= A[k];
    B[2] = pow(geoSum, double(1.0/N));

    double harmoSum = 0;
    for(int t=0; t<N; t++) harmoSum += double(1.0/A[t]);
    B[3] = double(N/harmoSum);

    double min = A[0], max = A[0];
    for(int x=0; x<N; x++){
        if(min>=A[x]){
            min = A[x];
        }else if(max<=A[x]){
            max = A[x];
        }
    }
    B[4] = max;
    B[5] = min;
}