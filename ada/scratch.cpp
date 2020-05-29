#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, test;
    long long k, n;
    long long i, j;
    char ch;
    int price, index;
    int arr[256];
    long long total_price;
    string line;

    cin >> t;

    for (test = 0; test < t; test++) {

        for (i = 0; i < 256; i++) {
            arr[i] = 0;
        }

        cin >> k;
        total_price = 0;

        for (i = 0; i < k; i++) {
            cin >> ch >> price;
            arr[ch] = price;
        }

        cin >> n;
        cin.ignore();
        for (i = 0; i < n; i++) {
            getline(cin, line);

            for (auto c: line) {
                if (c < 256) {
                    total_price = total_price + arr[c];
                }
            }

        }
        printf("%.2lf$\n", total_price*1.0/100);
    }

    return 0;
}