#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool ordenar(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second > p2.second) {
        return true;
    }

    else if(p1.second < p2.second) {
        return false;
    }

    else {
        return (p1.first > p2.first);
    }

}
int main() {
    int t;

    while(cin >> t, t) {

        vector<pair<int, int>> aplausos;
        int min_aplausos = 100001;
        unordered_map<int, int> minutos;

        for(int i=0; i < t; i++) {
            int min, personas;
            cin >> min >> personas;
            aplausos.push_back(make_pair(min, personas));
        }

        sort(aplausos.begin(), aplausos.end(), ordenar);

        int dist = 0;
        int result = -1;
        for(int i=0; i < t; i++) {
            
            if(aplausos[i].second <= dist) {
                if (aplausos[i].second == min_aplausos) {
                    minutos[aplausos[i].second] = max(minutos[aplausos[i].second], aplausos[i].first);
                }
            }
            else {
                dist = aplausos[i].second;
                if (result == -1) {
                    result = 0;
                }
                else {
                    result = max(result, minutos[min_aplausos]);
                }
                min_aplausos = dist;
                minutos[aplausos[i].second] = aplausos[i].first;
            }

            dist++;
            
        }

        result = max(result, minutos[min_aplausos]);

        cout << result << endl;

    }
    return 0;
}