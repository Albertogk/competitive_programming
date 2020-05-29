#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int min_complains(int n, vector<int>final_sum, int p, vector<vector<int>> forb, int m) {
    vector<int> min_comp, least_complains;
    int aux, comp_with_0, comp_with_1, complains = 0, min_impact = -1, impact, index_mod;

    for(int i=0; i<p; i++) {
        aux = n-final_sum[i];
        if(aux <= final_sum[i]) {
            min_comp.push_back(1);
            complains += aux;
        }
        else {
            min_comp.push_back(0);
            complains += final_sum[i];
        }
    }

    least_complains = min_comp;

    while(find(forb.begin(), forb.end(), min_comp) != forb.end()) {
        for(int i=0; i<p; i++) {
            aux = n-final_sum[i];
            impact = abs(aux-final_sum[i]);
            if(impact < min_impact || min_impact == -1) {
                min_impact = impact;
                index_mod = i;
            } 
        }
        complains += min_impact;
        min_comp[index_mod] = (min_comp[index_mod] == 0) ? 1 : 0;
    }

    return complains;

}

int main() {
    int t, n, p, m;
    vector<int> accumulation, aux;
    vector<vector<int>> forb;
    string rd_aux;
    cin >> t;

    for(int i=0; i < t; i++) {

        cin >> n >> m >> p;
        cin.ignore();

        for(int j=0; j<n; j++) {
            getline(cin, rd_aux);
            aux.clear();

            for(auto c: rd_aux) {
                if (j == 0) {
                    accumulation.push_back(c-'0');
                }
                else {
                    aux.push_back(c-'0');
                    
                }
            }
            if (j != 0) {
                transform(accumulation.begin(), accumulation.end(), aux.begin(), accumulation.begin(), std::plus<int>());
            }

        }

        for(int j=0; j < m ; j++) {
            getline(cin, rd_aux);
            aux.clear();

            for(auto c: rd_aux) {
                aux.push_back(c-'0');
            }
            
            forb.push_back(aux);
        }

        cout << "Case #" << i+1 << ": " << min_complains(n, accumulation, p, forb, m) << endl;
    }
}
