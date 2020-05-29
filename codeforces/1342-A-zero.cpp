#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int t, a, b;
    long long x;
    long long y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> a >> b;
        if (x*y < 0) {
            cout << (abs(x)+abs(y))*a << endl;
        }
        else if (b > 2*a) {
            cout << (abs(x)+abs(y))*a << endl;
        }
        
        else {
            x = abs(x);
            y = abs(y);
            cout << min(x, y)*b + (max(x, y)-min(x, y))*a << endl;
        }
    }
    return 0;
}