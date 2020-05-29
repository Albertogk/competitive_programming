#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string toBinary(long long n, int digits)
{
    string r;
    for(int i=0; i<digits; i++) {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}

int main() {
    int t, n, k, a, b, c;
    long long p;
    
    string result;
    string binary;

    cin >> t;

    for (int i=0; i < t; i++) {
        cin >> n >> k >> p;
        binary = toBinary(p-1, n-k);

        string bit_string(n, 'a');

        for(int j=0; j<k; j++) {
            cin >> a >> b >> c;
            bit_string[a-1] = c+'0';
        }
        int k=0;
        for(string::iterator iter = binary.begin(); iter != binary.end(); iter++) {
            while(bit_string[k] != 'a') {
                k++;
            }
            bit_string[k] = *iter;
        }

        cout << "Case #" << i+1 << ": " << bit_string << endl;
    }
    return 0;
}