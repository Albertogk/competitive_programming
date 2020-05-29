#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

void custom_sort(int* list, int len, int limit) {
    int aux;
    if 
    for(int i=len-1; i>0; i--) {
        if(list[i] < list[i-1]) {
            aux = list[i-1];
            list[i-1] = list[i];
            list[i] = aux;
        }
        else {
            return;
        }
    }

    return;
}
int main() {
    int n;

    cin >> n;
    int *numbers;
    int *median_pointer;
    double result;

    numbers = new int[n];
    median_pointer = numbers;
    for(int i=0; i<n; i++) {
        cin >> numbers[i];

        custom_sort(numbers, i+1);
        result = (*median_pointer) * 1.0;

        if (i%2 != 0) {
            median_pointer++;
            result += *median_pointer;
            result /= (2 * 1.0);
        }

        cout << fixed;
        cout << setprecision(1);
        cout << result*1.0 << endl;
    }

    return 0;
}