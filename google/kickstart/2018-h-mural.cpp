#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    int t, n;
    char lectura;
    int n_sumas;
    int *leidos;
    int numero;
    int suma;
    string mural;
    int max_suma;
    int cielo;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> n;
        n_sumas = n+1-(n/2);
        leidos = new int[n];
        suma = 0;
        max_suma = 0;
        cin.ignore();
        getline(cin, mural);
        cielo = ceil((n*1.0)/2);
        for(int j=0; j < n; j++) {
            numero = mural[j] - '0';
            leidos[j] = numero;
            suma += numero;
            if(j>=cielo) {
                suma -= leidos[j-cielo];
                if (suma > max_suma) {
                    max_suma = suma;
                }
            }
            if(j == cielo-1) {
                max_suma = suma;
            }

        }
        cout << "Case #" << i+1 << ": " << max_suma << endl;
    }

    return 0;
}