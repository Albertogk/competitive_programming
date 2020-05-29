#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

vector<char> get_non_visited(vector<char> visited, vector<char> list) {
    vector<char> result;

    for(vector<char>::iterator it= list.begin(); it != list.end(); it++) {
        if(find(visited.begin(), visited.end(), *it) == visited.end()) {
            result.push_back(*it);
        }
    }
    return result;
}
int main() {

    int t;
    int trees, acorns;
    bool flag;
    string aux;
    map<char, vector<char> > edges;
    vector<char> visited;
    vector<char> explored;
    vector<char> not_visited, aux2;
    char element;
    cin >> t;
    cin.ignore();

    for(int i=0; i<t; i++) {
        getline(cin, aux);
        edges.clear();
        flag = true;
        not_visited.clear();
        visited.clear();
        explored.clear();
        trees = 0;
        acorns = 0;
        while( aux.find("*") == string::npos) {
            edges[aux[1]].push_back(aux[3]);
            edges[aux[3]].push_back(aux[1]);
            getline(cin, aux);
        }

        getline(cin,aux);
        for(auto c: aux) {
            if (flag) {
                not_visited.push_back(c);    
            }
            flag = !flag;  
        }

        while(!not_visited.empty() || !explored.empty()) {
            if(explored.empty()) {
                element = not_visited.back();
                not_visited.pop_back();
                if(edges.count(element) == 0) {
                    acorns++;
                }
                else {
                    aux2 = get_non_visited(visited, edges[element]);
                    explored.insert(explored.end(), aux2.begin(), aux2.end());
                }
                visited.push_back(element);
            }
            else {
                element = explored.back();
                explored.pop_back();
                if (find(visited.begin(), visited.end(), element) == visited.end()) {
                    aux2 = get_non_visited(visited, edges[element]);
                    
                    if(!aux2.empty()) {
                        explored.insert(explored.end(), aux2.begin(), aux2.end());
                    }
                    visited.push_back(element);
                }

                if (explored.empty()) {
                    trees++;
                }
                
            }

        }

        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
    }


    return 0;
}