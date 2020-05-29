#include <iostream>

using namespace std;

int main() {

    int t, n, wall, last_wall;
    cin >> t;

    for(int i=1; i<=t; i++) {
        cin >> n;
        int higher = 0;
        int lower = 0;
        if (n > 0) {
            cin >> last_wall;
        }
    
        for(int j=1; j<n; j++) {
            cin >> wall;

            if(wall < last_wall) {
                lower++;
            }
            else if(wall > last_wall) {
                higher++;
            }
            last_wall = wall;
        }

        cout << "Case " << i << ": " << higher << " " << lower << endl;
    }
    return 0;
}