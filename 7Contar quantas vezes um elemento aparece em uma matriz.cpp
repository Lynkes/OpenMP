#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int mat[100][100], target = 50, count = 0;

    // Preenchendo matriz
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            mat[i][j] = i+j;
        }
    }

    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (mat[i][j] == target) {
                count++;
            }
        }
    }

    // Exibindo resultado
    cout << "O elemento " << target << " aparece " << count << " vezes." << endl;

    return 0;
}
