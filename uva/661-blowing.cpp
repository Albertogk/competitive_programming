#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c, aux, cnt = 0;
    bool status[20], first = true;
    int power[20];

    while(scanf("%d %d %d", &n, &m, &c), n|m|c) {
        cnt++;
        int consumption = 0, max_c = 0;
        bool blowed = false;
        for(int i=0; i<n; i++) {
            scanf("%d", &power[i]);
            status[i] = false;
        }

        for(int i=0; i<m; i++) {
            scanf("%d", &aux);
            aux--;
            status[aux] = !status[aux];
            if(status[aux]) {
                consumption += power[aux];
            }
            else {
                consumption -= power[aux];
            }

            if (consumption > c) {
                blowed = true;
            }

            max_c = max(consumption, max_c);
        }

        printf("Sequence %d\n", cnt);
        if(blowed) {
            printf("Fuse was blown.\n\n");
        }
        else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max_c);
        }
    }
    return 0;
}