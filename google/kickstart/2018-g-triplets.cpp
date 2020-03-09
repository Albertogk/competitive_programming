#include <iostream>
#include <vector>

using namespace std;

bool is_triplet(int i, int j, int k) {
    return (i*j == k || i*k == j || j*k == i);

}

int main() {
    int t, n, leido;
    vector<int> numbers;
    int triplets;

    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> n;
        numbers.clear();
        triplets = 0;
        for(int j=0; j<n; j++) {
            cin >> leido;
            numbers.push_back(leido);
            if(j >= 2) {
                for(int k=0; k<j-1; k++) {
                    for(int z=k+1; z<j; z++) {
                        if(numbers[j-1] != numbers[j]) {
                            if(is_triplet(numbers[k], numbers[z], numbers[j])) {
                            triplets++;
                        }
                        }
                        
                    }
                }
            }
        }

        cout << "Case #" << i+1 << ": " << triplets << endl;

    }
    return 0;
}