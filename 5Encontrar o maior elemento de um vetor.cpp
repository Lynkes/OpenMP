#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int v[1000], max_val = -1;

    // Preenchendo vetor
    for (int i = 0; i < 1000; i++) {
        v[i] = i;
    }

    #pragma omp parallel for reduction(max:max_val)
    for (int i = 0; i < 1000; i++) {
        if (v[i] > max_val) {
            max_val = v[i];
        }
    }

    // Exibindo resultado
    cout << "Maior valor: " << max_val << endl;

    return 0;
}
