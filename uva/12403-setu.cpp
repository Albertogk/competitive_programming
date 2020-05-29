#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int t, aux;
    char str[7];
    int money = 0;

    cin >> t;
    for (int i=0; i < t; i++) {
        cin >> str;
        if (strcmp(str, "donate") == 0) {
            cin >> aux;
            money += aux;
        }
        else {
            cout << money << endl;
        }
    }
    return 0;
}