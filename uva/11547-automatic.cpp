#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t, n;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> n;
        cout << abs((((((n*567)/9)+7492)*235)/47 - 498)/10 % 10) << endl;
    }
}