#include <iostream>

using namespace std;

int main() {
    int t, f, farm_size, n_animals, friend_points;
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> f;
        int result = 0;
        for(int j=0; j<f; j++) {
            cin >> farm_size >> n_animals >> friend_points;
            result += farm_size*friend_points;
        }

        cout << result << endl;
    }
    return 0;
}