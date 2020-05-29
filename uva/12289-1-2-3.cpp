#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;
    char str[6];

    for(int i=0; i < t; i++) {
        cin >> str;
        if (strlen(str) == 5) {
            cout << 3 << endl;
        }
        else {
            if(str[0] == 'o') {
                if (str[1] == 'n') {
                    cout << 1 << endl;
                }
                else {
                    if(str[2] == 'e') {
                        cout << 1 << endl;
                    }
                    else {
                        cout << 2 << endl;
                    }
                }
            }
            else {
                if(str[1] == 'n') {
                    if(str[2] == 'o') {
                        cout << 2 << endl;
                    }
                    else {
                        cout << 1 << endl;
                    }
                }
                else {
                    cout << 2 << endl;
                }
            }
        }
    }

    return 0;
}