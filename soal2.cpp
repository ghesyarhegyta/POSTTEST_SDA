#include <iostream>
using namespace std;

int main(){
    const int N = 3;
    int m[N][N];

    cout << "Input elemen matriks 3x3:" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> m[i][j];
        }
    }

    int jumlah = 0;
    for(int i=0; i<N; i++){
        jumlah += m[i][i];
        jumlah += m[i][N-1-i];
    }
    if(N % 2 == 1) jumlah -= m[N/2][N/2];

    cout << "\nMatriks:\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Jumlah diagonal utama + sekunder = " << jumlah << endl;
    return 0;
}
