#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    const int ROWS = 1000;
    const int COLS = 1000;

    int mat[ROWS][COLS];
    double sum = 0.0;
    double avg = 0.0;

    // Inicializa matriz com valores aleatórios
    #pragma omp parallel for
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    // Calcula a soma de todos os elementos da matriz
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += mat[i][j];
        }
    }

    // Calcula a média dos elementos da matriz
    avg = sum / (ROWS * COLS);
    cout << "Média: " << avg << endl;

    return 0;
}
