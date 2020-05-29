#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(char matrix[50][50], int n) {
    for (int j=0; j<n; j++) {
        for (int k=0; k<n; k++) {
            if (matrix[j][k] == '1') {
                if (j != n-1 && k != n-1) {
                    if(matrix[j+1][k] != '1' && matrix[j][k+1] != '1') {
                        return false;
                    }
                }
            }
        }    
    }
    return true;
}


int main() {
    int t, n;
    
    cin >> t;
    for (int i=0; i < t; i++) {
        cin >> n;
        char matrix[50][50];
        for (int j=0; j<n; j++) {
            cin >> matrix[j];
        }
        if (solve(matrix, n)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}