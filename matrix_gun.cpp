#include <iostream>
using namespace std;

const int N = 4;

void multiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = 0;

            
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                C[i][j] += A[i][k] * A[k][j];
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
    multiply(A, B, C);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
