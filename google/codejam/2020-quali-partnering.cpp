#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareHours(pair<int, pair<int, int>> i1, pair<int, pair<int, int>> i2) {
    return (i1.second.first < i2.second.first);
}
int main() {

    int t, n;
    int start, end;
    pair<int, int> as_c, as_j;
    
    vector<pair<int, pair<int, int>>> hours;

    int aux[2];
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        string result(n, 'C');
        hours.clear();
        for (int j=0; j < n; j++) {
            cin >> start >> end;
            hours.push_back(make_pair(j, make_pair(start, end)));
        }

        sort(hours.begin(), hours.end(), compareHours);

        as_c = hours[0].second;
        result[hours[0].first] = 'C';
        as_j = hours[1].second;
        result[hours[1].first] = 'J';

        for(int k=2; k < n; k++) {
            if(as_c.second <= hours[k].second.first) {
                result[hours[k].first] = 'C';
                as_c = hours[k].second;
            }
            else if(as_j.second <= hours[k].second.first) {
                result[hours[k].first] = 'J';
                as_j = hours[k].second;
            }
            else {
                result = "IMPOSSIBLE";
                break;
            }
        }

        cout << "Case #" << i+1 << ": " << result << endl;
    }
}