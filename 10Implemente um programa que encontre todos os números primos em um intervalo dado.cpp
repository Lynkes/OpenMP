#include <iostream>
#include <omp.h>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 1000;

    // Encontra os números primos no intervalo dado
    #pragma omp parallel for
    for (int i = LOWER_BOUND; i <= UPPER_BOUND; i++) {
        if (is_prime(i)) {
            #pragma omp critical
            cout << i << " é um número primo." << endl;
        }
    }

    return 0;
}
