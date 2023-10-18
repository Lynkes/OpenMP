#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    const int ROWS = 1000;
    const int COLS = 1000;

    double mat[ROWS][COLS];
    double max_val = -1.0;

    // Inicializa matriz com valores aleatórios
    #pragma omp parallel for
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat[i][j] = (double) rand() / RAND_MAX;
        }
    }

    // Encontra o valor máximo da matriz
    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mat[i][j] > max_val) {
                max_val = mat[i][j];
            }
        }
    }

    cout << "Valor máximo: " << max_val << endl;

    return 0;
}
