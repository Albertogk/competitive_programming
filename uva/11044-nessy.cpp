#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t, n, m;

    scanf("%d", &t);
    for(int i=0; i < t; i++){
        scanf("%d %d", &n, &m);
        n -= 2;
        m -= 2;

        n = ceil((n*1.0)/3);
        m = ceil((m*1.0)/3);
        printf("%d\n", n*m);
    }

    return 0;
}