#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> insert_order(vector<int> list, int ele1, int ele2) {
    // ele1 >= ele2
    int aux;
    list.push_back(ele2);
    list.push_back(ele1);
    for(int i=list.size()-3; i > 0; i--) {
        if(list[i] > list[i+1]) {
            aux = list[i];
            list[i] = list[i+1];
            list[i+1] = list[i+2];
            list[i+2] = aux;
        }
        else {
            break;
        }
    }
    return list;
}

int main() {
    int t, n, k, aux1, aux2, res, res_aux, ele;
    vector<int> difs;

    cin >> t;
    
    for(int i=0; i < t; i++) {
        cin >> n >> k;
        cin >> aux1;
        difs.clear();
        for(int j=1; j < n; j++) {
            cin >> aux2;
            difs.push_back(aux2-aux1);
            aux1=aux2;
        }

        sort(difs.begin(), difs.end());
        while(k > 0) {
            
            ele = difs.back();
            if(ele == 1) {
                break;
            }
            res_aux = ceil((ele*1.0)/2);
            difs.pop_back();

            difs = insert_order(difs, res_aux, ele-res_aux);
            k--;
        }

        cout << "Case #" << i+1 << ": " << difs.back() << endl;
    }
    return 0;
}