#include <iostream>

using namespace std;

int f(int n) {
    int result = 0;
    while(n > 0) {
        result += (n % 10);
        n /= 10;
    }

    return result;
}
int g(int n) {
    int result;
    if(n/10 == 0) {
        return n;
    }
    return g(f(n));
}

int main() {
    int n;
    while(cin >> n, n) {
        cout << g(n) << endl;
    }

    return 0;
}