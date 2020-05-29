#include <iostream>
#include <string>

#define LIMIT 1000000000
using namespace std;

struct Ret {
    long long a;
    long long b;
    int i;
};

struct Ret compute_instr(string instruction) {
    string aux;
    struct Ret ret, aux2;
    const int size = instruction.size();
    int i = 0;
    ret.a = 0;
    ret.b = 0;
    ret.i = 0;
    while(i<size && instruction[i] != ')') {
        if(instruction[i] >= '2' && instruction[i] <= '9') {
            int times = instruction[i] - '0';
            aux = instruction.substr(i+2);
            aux2 = compute_instr(aux);
            ret.a += (((aux2.a%LIMIT)*times)%LIMIT);
            ret.b += (((aux2.b%LIMIT)*times)%LIMIT);
            i = i + aux2.i + 1;
        }
        else {
            char move = instruction[i];
            if(move == 'S') {
                ret.a++;
            }
            else if(move == 'N') {
                ret.a--;
            }
            else if(move == 'E') {
                ret.b++;
            }
            else if(move == 'W'){
                ret.b--;
            }    
        }
        i++;
    }
    ret.i = i+1;
    return ret;
}
int main() {
    string line;
    struct Ret ret;
    int t;

    cin >> t;
    cin.ignore();
    for(int i=1; i <= t; i++) {
        getline(cin, line);
        long long w = 0, h = 0;
        ret = compute_instr(line);
        w = ret.b%LIMIT;
        h = ret.a%LIMIT;
        if (w<0) {
            w = LIMIT + w;
        }
        if(h < 0) {
            h = LIMIT + h;
        }
        cout << "Case #" << i << ": " << w+1 << " " << h+1 << endl; 
    }
    return 0;
} 