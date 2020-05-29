#include <cmath>
#include <iostream>

using namespace std;

int main() {

    int t, w, r1, r2, diff;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> w;
        if (w == 0) {
            cout << "yes" << endl;
        }
        else {
            cin >> r1 >> r2;
            diff = abs(r1-r2);
            for(int j=1; j<w; j++) {
                cin >> r1 >> r2;
                if (diff != abs(r1-r2)) {
                    diff = -1;
                }
            }
            if(diff >= 0) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        
        if (i + 1 != t) {
            cout << endl;
        }
    }
    return 0;
}