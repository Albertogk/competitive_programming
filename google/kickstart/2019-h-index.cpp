#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t, n, a_leido;
    unsigned int* turnos;
    string input;
    int index = 0;
    cin >> t;

    for (int i=0; i < t; i++) {
        cin >> n;
        cin.ignore();
        turnos = new unsigned int[n]();
        cout << "Case #" << i+1 << ": ";
        index = 0;
        for(int j=0; j<n; j++) {
            cin >> a_leido;
            for(int k=index; k<a_leido; k++) {
                if (k == n) {
                    break;
                }
                turnos[k]++;
                if (turnos[k] >= k+1) {
                    index++;
                }
            }
            cout << index << " ";
            
        }
        cout << endl;



    }
    return 0;
}