#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t, n, m;

    scanf("%d", &t);
    for(int i=0; i < t; i++){
        scanf("%d %d", &n, &m);
        if (n < m) {
            printf("<\n");
        }
        else if (n > m) {
            printf(">\n");
        }
        else {
            printf("=\n");
        }
    }

    return 0;
}