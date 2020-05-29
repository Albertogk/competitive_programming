#include <iostream>
#include <algorithm>
#include <cstdio>

#define LIMIT2 100
#define LIMIT3 9900
#define LIMIT5 9990000

using namespace std;

int calculate_price_from_consume(int cons) {
    int price = 0;
    price += min(max(0, cons*2), 2*100); cons -= 100;
    price += min(max(0, cons*3), 3*9900); cons -= 9900;
    price += min(max(0, cons*5), 5*990000); cons -= 990000;
    price += max(0, cons*7);
    return price;

}

int works(int my_consume, int neigh_consume) {
    return (calculate_price_from_consume(neigh_consume) - calculate_price_from_consume(my_consume));
}

int main() {
    int a, b, aux;
    scanf("%d %d", &a, &b);
    while(a != 0 || b != 0) {
        /* Sacamos de la consumición total */
        aux = a;

        int cons = 0;
        cons += min(max(0, a/2), 100); a -= 2*100;
        cons += min(max(0, a/3), 9900); a -= 3*9900;
        cons += min(max(0, a/5), 990000); a -= 5*990000;
        cons += max(0, a/7);

        int lo = 0;
        int hi = cons;
        int ans = 0;
        int mid;

        while(lo < hi) {
            mid = (lo+hi)/2;
            ans = works(mid, cons-mid);
            if (ans > b) {
                lo = mid;
            }
            else if(ans < b) {
                hi = mid;
            }
            else {
                break;
            }
        }

        cout << calculate_price_from_consume(mid) << endl;
        scanf("%d %d", &a, &b);

    }
    return 0;
}