#include <cstdio>

#define DEG_PER_MARK 9

using namespace std;

int main() {
    int pos, a, b, c;
    while(scanf("%d %d %d %d", &pos, &a, &b, &c), pos|a|b|c) {
        int degrees = 720;
        int diff = pos-a;
        if (diff < 0) {
            diff = 40 + diff;
        }
        degrees += diff*DEG_PER_MARK;
        degrees += 360;

        diff = b-a;
        if (diff < 0) {
            diff = 40 + diff;
        }

        degrees += diff*DEG_PER_MARK;
        diff = b-c;
        if (diff < 0) {
            diff = 40 + diff;
        }

        degrees += diff*DEG_PER_MARK;
        printf("%d\n", degrees);
    }
    return 0;
}