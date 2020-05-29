#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <istream>

#define NOT_VERTEX 0
#define NOT_AWAKEN 1
#define AWAKEN 2

using namespace std;

bool can_awake(vector<char> awaken, vector<char> neighbours) {
    int cnt = 0;
    for(vector<char>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {
        if(find(awaken.begin(), awaken.end(), *it) != awaken.end()) {
            cnt++;
            if (cnt == 3) {
                return true;
            }
        }
    }

    return false;
}
int main() {
    int n, m, liminf, limsup, cnt, total;
    bool flag, flag2, flag3;
    string aux;
    vector<char> awaken, new_awaken;
    vector<char> explored;
    char act1, act2, act3;
    int *status;
    map<char, vector<char>> connections;
    vector<char> aux2;

    flag = true;

    while(true) {

        if(cin.eof()) {
            break;
        }   
        cin >> n;
        if(cin.eof()) {
            break;
        }  
        cin >> m;
        if(cin.eof()) {
            break;
        }  

        status = new int[26]();
        cin.ignore();
        getline(cin, aux);
        awaken.clear();
        awaken.push_back(aux[0]);
        awaken.push_back(aux[1]);
        awaken.push_back(aux[2]);
        total = 3;
        connections.clear();
        for(int j=0; j<m; j++) {
            getline(cin, aux);
            connections[aux[0]].push_back(aux[1]);
            connections[aux[1]].push_back(aux[0]);
            if(status[aux[0]-'A'] == NOT_VERTEX) {
                total++;
            }
            if(status[aux[1]-'A'] == NOT_VERTEX) {
                total++;
            }
            status[aux[0]-'A'] = NOT_AWAKEN;
            status[aux[1]-'A'] = NOT_AWAKEN;
        }

        if(total < n) {
            cnt = -1;
        }
        else {
            status[awaken[0]-'A'] = AWAKEN;
            status[awaken[1]-'A'] = AWAKEN;
            status[awaken[2]-'A'] = AWAKEN;

            int max = 0;
            flag3 = false;
            cnt = 0;
            new_awaken = awaken;
            while(awaken.size() < n) {
                
                cnt++;
                for(int j=0; j<26; j++) {
                    if(status[j] == NOT_AWAKEN) {
                        if(connections.count(j+'A') == 0) {
                            flag3 = false;
                            break;
                        }
                        if(can_awake(awaken, connections[j+'A'])) {
                            status[j] = AWAKEN;
                            new_awaken.push_back(j+'A');
                            flag3 = true;
                        }
                    }
                }
                if(!flag3) {
                    cnt = -1;
                    break;
                }
                awaken = new_awaken;
            }
        }
        
        

        if (cnt == -1) {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        }
        else {
            cout << "WAKE UP IN, " << cnt << ", YEARS" << endl;
        }

        getline(cin, aux);

    }
    
    return 0;
}