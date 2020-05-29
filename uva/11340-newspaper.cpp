#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    int n, k, m;
    map<char, int> values;
    char aux;
    string text;
    long long total;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> k;
        values.clear();
        for(int j=0; j<k; j++) {
            cin >> aux;
            cin >> values[aux]; 
        }

        cin >> m;
        cin.ignore();
        total = 0;

        for(int j=0; j<m; j++) {
            getline(cin, text);
            for(auto c: text) {
                if(c != ' ' && c != '\n') {
                    if(values.find(c) != values.end()) {
                        total += values[c];
                    }

                }
            }
        }

        printf("%.2lf$\n", (total*1.0)/100);

    }
    return 0;
}