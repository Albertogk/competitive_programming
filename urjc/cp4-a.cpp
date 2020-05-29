#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int minDistancia(int *distancias, bool *procesado, int n) {
    int min = -1, min_index;

    for(int i =0; i<n; i++) {
        if(procesado[i] == false && distancias[i] != -1 && (distancias[i] < min || min == -1)) {
            min = distancias[i];
            min_index = i;
        }
    }

    return min_index;
}

bool mySort(pair<int, int> l1, pair<int, int> l2) {
    if (l1.second == l2.second) {
        return (l1.first < l2.first);
    }
    return (l1.second < l2.second);
}

int main() {
    int n, c, a, b, d, ini, e, p;
    vector<pair<int, int>> equipos;
    vector<int> iguales;
    vector<pair<int, int>> tiempos;
    map<int, map<int, int>> distances;

    cin >> n >> c;
    for(int i=0; i<c; i++) {
        cin >> a >> b >> d;
        distances[a][b] = d;
        distances[b][a] = d;
    }

    cin >> ini;
    cin >> e;
    for(int i=0; i<e; i++) {
        cin >> d >> p;
        equipos.push_back(make_pair(d, p));
    }

    int distancias[n];
    bool procesado[n];
    for(int i=0; i < n; i++) {
        distancias[i] = -1;
        procesado[i] = false;
    }

    distancias[ini] = 0;
    for(int i=0; i<n-1; i++) {
        int u = minDistancia(distancias, procesado, n);
        procesado[u] = true;
        for(int j=0; j < n; j++) {
            if(!procesado[j] && distances[u].count(j) == 1 && distancias[u] != -1 && (distancias[u] + distances[u][j] < distancias[j] || distancias[j] == -1)) {
                distancias[j] = distancias[u] + distances[u][j];
            }
        }
    }


    for(int i=0; i < e; i++) {
        tiempos.push_back(make_pair(i, distancias[equipos[i].first] + equipos[i].second));
    }

    sort(tiempos.begin(), tiempos.end(), mySort);

    cout << tiempos[0].first;
    for(int i=1; i<e; i++) {
        
        if(tiempos[i].second > tiempos[i-1].second) {
            cout << " -> ";
            
        }
        else {
            cout << " = ";
        }

        cout << tiempos[i].first;
    }

    return 0;

}