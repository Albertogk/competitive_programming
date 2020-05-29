#include <cstdio>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


struct Fecha {
    int dia;
    int mes;
    int anio;
    int victimas;
};

using namespace std;

void print_fecha(struct Fecha fecha) {
    if(fecha.dia < 10) {
        printf("0");
    }
    printf("%d/",fecha.dia);
    if(fecha.mes < 10) {
        printf("0");
    }
    printf("%d/", fecha.mes);
    if (fecha.anio < 1000) {
        printf("0");
    }
    if (fecha.anio < 100) {
        printf("0");
    }
    if(fecha.anio < 10) {
        printf("0");
    }

    printf("%d\n", fecha.anio);

    return;
}

int main() {
    int t;
    
    while(scanf("%d", &t) == 1 && t) {
        struct Fecha fecha;
        struct Fecha aux;
        int mid_idx;
        struct Fecha result;
        vector<struct Fecha> buscar;
        buscar.clear();

        scanf("%d/%d/%d %d", &fecha.dia, &fecha.mes, &fecha.anio, &fecha.victimas);
        printf("NO HAY\n");
        aux = fecha;
        for(int i=1; i<t; i++) {
            scanf("%d/%d/%d %d", &fecha.dia, &fecha.mes, &fecha.anio, &fecha.victimas);
            bool flag_hay = false;

            if (fecha.victimas < aux.victimas) {
                flag_hay = true;
                result = aux;
                buscar.push_back(aux);
            }

            else if (!buscar.empty()) {
                const int n = buscar.size();
                /*
                int low = 0, hi = n-1;
                mid_idx = -1;
                while(low <= hi) {
                    int mid = (low+hi)/2;
                    if(fecha.victimas >= buscar[mid].victimas) {
                        hi = mid - 1;
                    }
                    else {
                        low = mid + 1;
                        result = buscar[mid];
                        mid_idx = mid;
                        flag_hay = true;
                    }

                }*/

                for(int j=n-1; j >= 0; j--) {
                    if (buscar[j].victimas > fecha.victimas) {
                        flag_hay = true;
                        result = buscar[j];
                        break;
                    }
                }

                if(!flag_hay) {
                    buscar.clear();
                    buscar.push_back(fecha);
                }
            }
            if (!flag_hay) {
                printf("NO HAY\n");
            }
            else {
                print_fecha(result);
            }
            aux = fecha;
        }
        printf("---\n");
    }
    
  
    return 0;
}