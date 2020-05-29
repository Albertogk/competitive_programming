#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int solve(string dni, unordered_map<char, int> valores, char letra) {
    const int pos = dni.find('?');

    if (pos == string::npos) {
        if (stoi(dni) % 23 == valores[letra]) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int retorno = 0;

    for (int i = 0; i < 10; i++) {
        char ch = i + '0';
        dni[pos] = ch;
        retorno += solve(dni, valores, letra);
    }

    return retorno;
}

int main() {
    unordered_map<char, int> valores = {{'T', 0}, {'R', 1}, {'W', 2}, {'A', 3}, {'G', 4}, {'M', 5}, {'Y', 6}, {'F', 7}, {'P', 8}, {'D', 9}, {'X', 10}, {'B', 11}, {'N', 12},
               {'J', 13}, {'Z', 14}, {'S', 15}, {'Q', 16}, {'V', 17}, {'H', 18}, {'L', 19}, {'C', 20}, {'K', 21}, {'E', 22}};

    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++) {
        string dni;
        getline(cin, dni);

        cout << solve(dni.substr(0, 8), valores, dni[8]) << endl;
    }
}