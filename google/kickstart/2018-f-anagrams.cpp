#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

using namespace std;

map<char, int> get_map(string str, int l) {
  map<char, int> dict;
  for(int i=0; i<l; i++) {
    if(dict.count(str[i]) == 0) {
      dict[str[i]] = 1;
    }
    else {
      dict[str[i]]++;
    }
  }
  return dict;
}

int main() {

  int t, n, n_substrings, flag;
  string a, b, substring_a, substring_b;
  map<char, int> char_ap;

  cin >> t;
  for(int i=0; i<t; i++) {
    cin >> n;
    cin.ignore();
    getline(cin, a);
    getline(cin, b);

    n_substrings = 0;
    for(int j=1; j<=n; j++) {
      for(int k=1; k<=j; k++) {
        substring_a = a.substr(j-k, k);
        char_ap = get_map(substring_a, k);
        for(int x=0; x<=n-k; x++) {
          substring_b = b.substr(x, k);
          for(map<char,int>::iterator iter = char_ap.begin(); iter != char_ap.end(); ++iter) {
            if(count(substring_b.begin(), substring_b.end(), iter->first) != iter->second) {
              flag=1;
              break;
            }
          }
          if(flag == 0) {
            n_substrings++;
            break;
          }
          flag=0;
        }

      }

    }
    cout << "Case #" << i+1 << ": " << n_substrings << endl;
  }
  return 0;

}