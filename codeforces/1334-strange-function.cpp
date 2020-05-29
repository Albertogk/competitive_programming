#include <iostream>

using namespace std;

int main() {
    int n, price = 0;
    bool not_posible = false;
    cin >> n;

    int a[n];
    int coins[n];

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    int m;
    cin >> m;

    int b[m];
    int low = 0;
    int low_idx = 0;
    for(int i=0; i<m; i++) {
        cin >> b[i];
        if(not_posible) {
            continue;
        }
        not_posible = true;

        while(low_idx < n && a[low_idx] >= low) {
            if (a[low_idx] == low) {
                low_idx++;
                continue;
            }
            if (a[low_idx] == b[i]) {
                low_idx++;
                not_posible = false;
                break;
            }
            price += coins[low_idx];
            low_idx++;
        }
        low = b[i];
    }

    while(low_idx < n) {
        if (a[low_idx] == low) {
            low_idx++;
            continue;
        }
        else if (a[low_idx] > low) {
            price += coins[low_idx];    
        }
        low_idx++;
    }

    if(!not_posible) {
        cout << "YES" << endl << price << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}