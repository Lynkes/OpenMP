#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int v1[1000], v2[1000], res[1000];
    
    // Preenchendo vetores
    for (int i = 0; i < 1000; i++) {
        v1[i] = i;
        v2[i] = i+1;
    }

    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        res[i] = v1[i] + v2[i];
    }

    // Exibindo resultado
    for (int i = 0; i < 1000; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
