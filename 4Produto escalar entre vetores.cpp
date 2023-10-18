#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int v1[1000], v2[1000], res = 0;

    // Preenchendo vetores
    for (int i = 0; i < 1000; i++) {
        v1[i] = i;
        v2[i] = i+1;
    }

    #pragma omp parallel for reduction(+:res)
    for (int i = 0; i < 1000; i++) {
        res += v1[i] * v2[i];
    }

    // Exibindo resultado
    cout << "Produto escalar: " << res << endl;

    return 0;
}
