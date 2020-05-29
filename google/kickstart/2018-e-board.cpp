#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

map<int, int> get_map(vector<int> cards) {
    map<int, int> card_map;
    for(vector<int>::iterator iter = cards.begin(); iter != cards.end(); ++iter) {
        if(card_map.count(*iter) == 0) {
            card_map[*iter] = 1;
        }
        else {
            card_map[*iter]++;
        }
    }

    return card_map;
}


int main() {
    int t, n, rd, favorables, totales, campo1, campo2, campo3, bahu_values, bala_values;
    vector<int> bahu, bala;
    map<int, int> bahu_map, bala_map;

    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        bahu.clear();
        bala.clear();
        favorables = 0;
        totales = 0;
        for(int j=0; j<3*n; j++) {
            cin >> rd;
            bahu.push_back(rd);
        }

        for(int j=0; j<3*n; j++) {
            cin >> rd;
            bala.push_back(rd);
        }

        bahu_map = get_map(bahu);
        bala_map = get_map(bala);

        bahu_values = accumulate(bahu.begin(), bahu.end(), 0);
        bala_values = accumulate(bala.begin(), bala.end(), 0);


    }
    return 0;
}