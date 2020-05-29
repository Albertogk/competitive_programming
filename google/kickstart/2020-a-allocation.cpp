#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t, n, b, aux, j, total;
    vector<int> a;

    cin >> t;

    for(int i=0; i < t; i++) {
        cin >> n >> b;
        a.clear();
        for(j=0; j < n; j++) {
            cin >> aux;
            a.push_back(aux);
        }
        total = 0;
        sort(a.begin(), a.end());
        for(j=0; j<n; j++) {
            total += a[j];
            if(total > b) {
                break;
            }
        }
        cout << "Case #" << i+1 << ": " << j << endl;
    }
    return 0;
}