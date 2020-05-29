#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[6];
    int i = 0;
    while(cin >> str, strcmp(str, "*")) {
        i++;
        if(strcmp(str, "Hajj") == 0) {
            cout << "Case " << i << ": " << "Hajj-e-Akbar" << endl;
        }
        else {
            cout << "Case " << i << ": " << "Hajj-e-Asghar" << endl;
        }
    }
    return 0;
}