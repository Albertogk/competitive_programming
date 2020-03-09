#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

    int t, n, p, flag = 0;
    long long result;
    int tamanio;
    string *forb_list;
    string forb, aux;
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n >> p;
        result = pow(2, n);
        cin.ignore();
        forb_list = new string[p];
        tamanio = 0;
        for(int j=0; j<p; j++) {
            getline(cin, forb);
            forb_list[j] = forb;
            for(int k=0; k < j; k++) {
                if (forb.size() < forb_list[k].size()) {
                    aux = forb_list[k].substr(0, forb.size());
                    if(aux == forb) {
                        result-=pow(2, n-forb.size());
                        result+=pow(2, n-forb_list[k].size());
                        flag = 1;
                    }
                }
                else {
                    aux = forb.substr(0, forb_list[k].size());
                    if(aux == forb_list[k]) {
                        flag = 1;
                        break;
                    }
                }
                
            }

            if (flag == 0) {
                result-=pow(2, n-forb.size());
            }
            
            flag = 0;
        }
        cout << "Case #" << i+1 << ": " << result << endl;
    }
    return 0;
}