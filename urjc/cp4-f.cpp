#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

vector<int> contagiar(vector<int> contagios, map<int, vector<int>> contactos, int idx) {
    for (vector<int>::iterator it = contactos[idx].begin(); it != contactos[idx].end(); it++) {
        if (contagios[*it] == 0) {
            contagios[*it] = 1;
            contagios = contagiar(contagios, contactos, *it);
        }
    }

    return contagios;
}

int main() {
    int n, m, a, b;
    bool flag;
    
    map<int, vector<int>> contactos;
    char frase[9];

    cin >> n >> m;

    vector<int> contagios(n, 0);

    for(int i=0; i<m; i++) {
        cin >> frase;

        if (strcmp(frase, "CONTACTO") == 0) {
            cin >> a >> b;

            contactos[a].push_back(b);
            contactos[b].push_back(a);
            if (contagios[a] == 1) {
                
                if(contagios[b] == 0) {
                    contagios[b] = 1;
                    contagios = contagiar(contagios, contactos, b);
                }
            }
            else if(contagios[b] == 1) {
                contagios[a] = 1;
                contagios = contagiar(contagios, contactos, a);
            }
        }
        else if(strcmp(frase, "POSITIVO") == 0) {
            cin >> a;
            contagios[a] = 1;
            contagios = contagiar(contagios, contactos, a);
        }

        else {
            cin >> a;
            if (contagios[a] == 1) {
                cout << "POSIBLE" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }

    }

    return 0;
}