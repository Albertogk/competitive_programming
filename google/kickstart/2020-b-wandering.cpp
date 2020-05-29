#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int get_number(int cols, int row) {
    int result = 0;
    for(int i=0; i < min(cols, row); i++) {
        for(int j=0; j<=i; j++) {
            result++;
        }
    }
    return result;
}
int main() {
    int t, w, h, l, u, r, d;
    bool above_hole;
    double result;

    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> w >> h >> l >> u >> r >> d;
        result = 0.0;
        if(r < w) {
            for(int j=1; j<u; j++) {
                result += 1/pow(2, r+j-l)*get_number(r, j);
            }
        }

        if(l > 1) {
            for(int j=1; j<d-u; j++) {
                result += 1/pow(2, d-u+j-u)*get_number(d-u, j);
            }
        }
        
        printf("Case #%d: %lf\n", i, result);
        
        
    }
    return 0;
}