#include <iostream>
#include <cstdio>


using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int min_juegos, n, hora, minuto, tiempo;
        int tiempo_juego = 360;
        int fin_anterior = 480;
        const int limite = 840;

        cin >> min_juegos >> n;
        for(int i=0; i<n; i++) {
            scanf("%d:%d %d", &hora, &minuto, &tiempo);
            int aux = hora*60+minuto;
            if (aux - fin_anterior < min_juegos) {
                tiempo_juego = tiempo_juego - aux + fin_anterior;
            }
            tiempo_juego -= tiempo;
            fin_anterior = aux+tiempo;
        }

        if (limite - fin_anterior < min_juegos) {
            tiempo_juego = tiempo_juego - limite + fin_anterior;
        }

        cout << tiempo_juego << endl;
        
    }
    return 0;
}