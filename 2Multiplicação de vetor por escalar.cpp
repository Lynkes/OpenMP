#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int v[1000], x = 2;

    // Preenchendo vetor
    for (int i = 0; i < 1000; i++) {
        v[i] = i;
    }

    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        v[i] *= x;
    }

    // Exibindo resultado
    for (int i = 0; i < 1000; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
