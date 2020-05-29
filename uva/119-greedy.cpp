#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, amount, k;
    char name[13];
    bool flag = false;
    unordered_map<string, int> money;
    vector<string> names;

    while(scanf("%d", &n) == 1) {
        money.clear();
        names.clear();
        for(int i=0; i<n; i++) {
            cin >> name;
            money[name] = 0;
            names.push_back(name);
        }

        for(int i=0; i<n; i++) {
            cin >> name >> amount >> k;
            if (k > 0) {
                amount /= k;
                money[name] -= amount*k;
                
            }
                      
            for(int j=0; j<k; j++) {
                cin >> name;
                money[name] += amount;
            }
        }
        if (flag) {
            cout << endl;
        }
        else {
            flag = !flag;
        }

        for(auto it = names.begin(); it != names.end(); it++) {
            cout << *it << " " << money[*it] << endl;
        }
    }
    return 0;
}