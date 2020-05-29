#include <iostream>
#include <cstdio>

struct Fecha {
    int dia;
    int mes;
    int anio;
    int victimas;
};

using namespace std;

int main() {
    int t;
    cin >> t;

    while(scanf("%d", &t) == 1) {
        struct Fecha fechas[t];
        for(int i=0; i<t; i++) {
            scanf("%d/%d/%d %d", &fechas[i].dia, &fechas[i].mes, &fechas[i].anio, &fechas[i].victimas);
            bool flag_hay = false;
            for (int j=i-1; j>=0; j--) {
                if (fechas[j].victimas > fechas[i].victimas) {
                    if(fechas[j].dia < 10) {
                        printf("0");
                    }
                    printf("%d/",fechas[j].dia);
                    if(fechas[j].mes < 10) {
                        printf("0");
                    }
                    printf("%d/%d\n", fechas[j].mes, fechas[j].anio);
                    flag_hay = true;
                    break;
                }
            }
            if (!flag_hay) {
                cout << "NO HAY" << endl;
            }
        }
        cout << "---" << endl;
    }
    
    return 0;
}