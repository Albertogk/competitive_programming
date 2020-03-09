#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

/*
int mover(char mov, int pos, int c) {
  switch (mov) {
    case 'E':
      pos++;
      break;

    case 'N':
      pos-=c;
      break;

    case 'S':
      pos+=c;
      break;

    case 'W':
      pos--;
      break;
  }
  return pos;
}


int main() {
  int t, n, r, c, sr, sc;
  int columna, fila;
  string instrucciones;
  vector<int> visitados;
  std::vector<int>::iterator it;
  int pos;

  cin >> t;
  for(int i=0; i < t; i++) {
    visitados.clear();
    cin >> n >> r >> c >> sr >> sc;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, instrucciones);
    pos = (sr-1)*c + sc;
    visitados.push_back(pos);
    for(auto mov: instrucciones) {
      pos = mover(mov, pos, c);
      it = std::find(visitados.begin(), visitados.end(), pos);

      while(it != visitados.end()) {
        pos = mover(mov, pos, c);
        it = std::find(visitados.begin(), visitados.end(), pos);
      }

      visitados.push_back(pos);

    }

    columna = pos % c;
    if (columna == 0) {
        columna = c;
    }
    fila = (pos-columna)/c +1;
    cout << "Case #" << i+1 << ": " << fila << " " << columna << endl;

  }

  return 0;
}*/

class Interval {
    int row_or_col;
    int ini;
    int end;
};

int main() {
  int t, n, r, c, sr, sc;
  int columna, fila;
  string instrucciones;
  vector<int> interval;
  std::vector<int>::iterator it;
  set<Interval> col_set;
  set<Interval> row_set;

  cin >> t;
  for(int i=0; i < t; i++) {
    cin >> n >> r >> c >> sr >> sc;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, instrucciones);
    

  }
}