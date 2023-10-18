#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int mat[100][100], target = 50;
    bool found = false;

    // Preenchendo matriz
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            mat[i][j] = i+j;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (mat[i][j] == target) {
                found = true;
            }
        }
    }

    // Exibindo resultado
    if (found) {
        cout << "Elemento encontrado!" << endl;
    } else {
        cout << "Elemento não encontrado!" << endl;
    }

    return 0;
}
