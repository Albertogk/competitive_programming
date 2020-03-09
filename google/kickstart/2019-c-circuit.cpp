#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

class Row {
    int inicio;
    int final;
};

int main() {
  int t, r, c, k, v;
  int min_v = -1, max_v = -1;
  vector<vector<int>> circuit;
  vector<set<Row>> rows;
  set<Row> row_set;
  Row row;

  cin >> t;
  for(int i=0; i < t; i++) {
    cin >> r >> c >> k;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for(int j=0; j<r ; j++) {
        for(int k=0; k<c; k++) {
            cin >> v;
            if (v < min_v || min_v == -1) {
                min_v = v;
            }

            if (v > max_v || max_v == -1) {
                max_v = v;
            }


        }
    }
    

  }
}