#include <cstdio>

using namespace std;

int main() {
    int price, n, b, h, w, p, a, min_price;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
        min_price = -1;
        price = -1;
        for(int i=0; i<h; i++) {
            scanf("%d", &p);
            for(int j=0; j < w; j++) {
                scanf("%d", &a);
                if(a >= n) {
                    price = n*p;
                }
            }

            if(price < b && price != -1) {
                if(min_price == -1 || price < min_price) {
                    min_price = price;
                }
            }
        }
        if (min_price == -1) {
            printf("stay home\n");
        }
        else {
            printf("%d\n", min_price);
        }
    }

    return 0;
}