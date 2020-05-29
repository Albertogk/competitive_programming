#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        float nota;
        
        bool flag9 = false, flag0 = false;
        for (int j=0; j<5; j++) {
            cin >> nota;
            if (nota == 0.0) {
                flag0 = true;
            }
            else if(nota >= 9.0) {
                flag9 = true;
            }
        }

        if (!flag0) {
            cout << "MEDIA" << endl;
        }
        else {
            if (flag9) {
                cout << "MEDIA" << endl;
            }
            else {
                cout << "SUSPENSO DIRECTO" << endl;
            }
        }
    }
    return 0;
}