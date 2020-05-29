#include <iostream>

using namespace std;

int main() {
    int t, n, data1, data2, data3;
    cin >> t;

    for(int i=0; i<t; i++) {
        int result = 0;
        cin >> n;
        cin >> data1 >> data2;
        for(int j=2; j<n; j++) {
            cin >> data3;
            if(data2 > data1 && data2 > data3) {
                result++;
            }
            data1 = data2;
            data2 = data3;
        }
        cout << "Case #" << i+1 << ": " << result << endl;
    }
    return 0;
}