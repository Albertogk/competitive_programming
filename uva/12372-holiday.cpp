#include <iostream>

using namespace std;

int main() {
    int t, l, w, h;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> l >> w >> h;
        if(l > 20 || w > 20 || h > 20) {
            cout << "Case " << i+1 << ": bad" << endl; 
        }
        else {
            cout << "Case " << i+1 << ": good" << endl; 
        }
    }

    return 0;
}