#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, n, max_len_1, max_len_2, max_idx_1, max_idx_2, aux_size;
    string strings[50];
    string part1[50];
    string part2[50];
    string substr, result;

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cin.ignore();
        max_len_1 = 0;
        max_idx_1 = 0;
        max_len_2 = 0;
        max_idx_2 = 0;
        for(int j=0; j<n; j++) {
            getline(cin, strings[j]);
            for(int k=0; k<strings[j].size();k++) {
                if(strings[j][k] == '*') {
                    part1[j] = strings[j].substr(0, k);
                    if(k > max_len_1) {
                        max_idx_1 = j;
                        max_len_1 = k;
                    }
                    part2[j] = strings[j].substr(k+1, strings[j].size()-k-1);
                    if(strings[j].size()-k-1 > max_len_2) {
                        max_idx_2 = j;
                        max_len_2 = strings[j].size()-k-1;
                    }
                    break;
                }
            }
        }
        result = part1[max_idx_1] + part2[max_idx_2];
        for (int j=0; j<n; j++) {
            if (j != max_idx_1) {
                aux_size = part1[j].size();
                if (aux_size > 0) {
                    if(part1[max_idx_1].substr(0, aux_size) != part1[j]) {
                        result = "*";
                        break;
                    }
                }
                
            }
            if (j != max_idx_2) {
                aux_size = part2[j].size();
                if (aux_size > 0) {
                    if(part2[max_idx_2].substr(max_len_2-aux_size, aux_size) != part2[j]) {
                        result = "*";
                        break;
                    }
                }
            }
        }

        cout << "Case #" << i+1 << ": " << result << endl;

    }
}