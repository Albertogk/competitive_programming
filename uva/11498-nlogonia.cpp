#include <cstdio>

using namespace std;

int main() {
    int k;
    int dvd_x, dvd_y, x, y;

    while(!(scanf("%d", &k) == 1 && k == 0)) {
        scanf("%d %d", &dvd_x, &dvd_y);

        for(int i=0; i<k; i++) {
            scanf("%d %d", &x, &y);
            
            if(x > dvd_x && y > dvd_y) {
                printf("NE\n");
            }
            else if(x > dvd_x && y < dvd_y) {
                printf("SE\n");
            }
            else if(x < dvd_x && y > dvd_y) {
                printf("NO\n");
            }
            else if(x < dvd_x && y < dvd_y) {
                printf("SO\n");
            }
            else {
                printf("divisa\n");
            }
        }
    }

    return 0;
}