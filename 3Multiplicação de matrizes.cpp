#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int a[100][100], b[100][100], res[100][100];

    // Preenchendo matrizes
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = i+j;
            b[i][j] = i-j;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 100; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Exibindo resultado
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
