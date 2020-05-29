#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, k, p, aux, plates_used, max_b, b, last_ind;
    vector< vector<int>> stacks;
    vector<int> stack;
    cin >> t;

    for(int i=0; i < t; i++) {
        stacks.clear();
        for(int j=0; j < n; j++) {
            cin >> aux;
            stack.clear();
            stack.push_back(aux);
            for(int z=1; z < k; z++) {
                cin >> aux;
                stack.push_back(stack[z-1]+aux);
            }
            stacks.push_back(stack);
        }
        max_b = -1;
        for(int y=0; y<stacks.size(); y++) {
            for(int z=1; z <= stacks[y].size(); z++) {
                plates_used = z;
                b = stacks[y][z-1];
                for(int x = y+1; x < stacks.size()-1; x++) {
                    for(int l=1; l <= stacks[x].size(); x++) {

                    }
                }
                last_ind = p - plates_used;
                if(last_ind > k) {
                    last_ind = k;
                }

                if(last_ind != 0) {
                    b += stacks[stacks.size()-1][last_ind-1];
                }

                if(b > max_b || max_b == -1) {
                    max_b = b;
                }
            }
        }    
    }
    return 0;
}