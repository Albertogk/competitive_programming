#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define COMUN 0
#define RARA 1

using namespace std;

vector<int> ordenar_por_precio(vector<int> cartas, map<int, int> precios, int idx) {
    int aux;
    for(int i = idx; i < cartas.size(); i++) {
        for(int j=i; j < cartas.size(); j++) {
            if (precios[cartas[j]] < precios[cartas[i]]) {
                aux = cartas[j];
                cartas[j] = cartas[i];
                cartas[i] = aux;
            }
        }
    }

    return cartas;
}

int main() {
    int m, aux, c, r, gastado = 0, j, carta, new_precio, total_mes;
    vector<int> presupuesto;
    map<int, int> comun_o_rara;
    vector<int> cartas;
    map<int, int> precios;

    cin >> m;

    for (int i=0; i<m; i++) {
        cin >> aux;
        presupuesto.push_back(aux);
    }

    cin >> c;

    for(int i=0; i<c; i++) {
        cin >> aux;
        cartas.push_back(aux);
        precios[aux] = aux;
        comun_o_rara[aux] = COMUN;
    }

    cin >> r;

    for(int i=0; i<r; i++) {
        cin >> aux;
        cartas.push_back(aux);
        precios[aux] = 2*aux;
        comun_o_rara[aux] = RARA;
    }

    int idx = 0;
    for(int i=0; i<m; i++) {
        cin >> j;
        for (int k=0; k < j; k++) {
            cin >> carta >> new_precio;

            if (precios[carta] > new_precio) {
                precios[carta] = new_precio;
            }
        }
        cartas = ordenar_por_precio(cartas, precios, idx);
        total_mes = 0;
        
        while(idx < cartas.size()) {
            total_mes += precios[cartas[idx]];
            if (total_mes > presupuesto[i]) {
                total_mes -= precios[cartas[idx]];
                break;
            }
            idx++;
        }
        

        gastado += total_mes;

    }

    cout << gastado << endl;
    if (idx == cartas.size()) {
        cout << "COMPLETADA" << endl;
    }
    else {
        sort(cartas.begin()+idx, cartas.end());
        for(int i=idx; i<cartas.size(); i++) {
            cout << cartas[i];
            if (i == cartas.size()-1) {
                cout << endl;
            }
            else {
                cout << " ";
            }
        }
    }

    return 0;

}