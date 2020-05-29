#include <iostream>
#include <bitset>
#include <vector>
#include <string>

#define EXP 30
using namespace std;
#define NOT_USED 0
#define USED_X 1
#define USED_Y 2


int main() {
    int t, x_int, y_int;
    string result;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> x_int >> y_int;
        bool x_minus = false;
        bool y_minus = false;
        string result = "";
        if(x_int < 0) {
            x_minus = true;
            x_int = -x_int;
        }
        if(y_int < 0) {
            y_minus = true;
            y_int = -y_int;
        }
        if((x_int % 2) == (y_int % 2)) {
            result = "IMPOSSIBLE";
        }
        else {
            bitset<EXP+1> sum(x_int + y_int);
            int cnt_1s = sum.count();
            vector<bool> inverted(false, EXP+1);
            for(int j=1; j<=EXP ; j++) {
                if(cnt_1s == 0) {
                    break;
                }
                if(sum[j] == '0') {
                    sum[j] = '1';
                    inverted[j-1] = true;
                }
                else {
                    cnt_1s--;
                }
            }

            for(int j=0; j <= EXP; j++) {
                if()
            }

        }
        

    }
}