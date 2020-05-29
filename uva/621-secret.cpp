#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    string read;

    cin >> t;
    cin.ignore();
    for(int i=0; i < t; i++) {
        getline(cin, read);
        const int n = read.size();

        if (read == "1" || read == "4" || read == "78") {
            cout << "+" << endl;
        }
        else if (read[n-1] == '5' && read[n-2] == '3') {
            cout << "-" << endl;
        }
        else if (read[0] == '9' && read[n-1] == '4') {
            cout << "*" << endl;
        }
        else {
            cout << "?" << endl;
        }
    }
    return 0;
}