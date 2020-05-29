#include <cstdio>

using namespace std;

int main() {
    int h, u, d, f;
    while(scanf("%d %d %d %d", &h, &u, &d, &f), h) {
        double position = 0.0;
        bool success;
        double fatigue = u*f*1.0/100;
        int ndays = 0;
        double advance = u;
        while(true) {
            ndays++;
            position += advance;
            if(position > h) {
                success = true;
                break;
            }
            position -= d;
            if(position < 0) {
                success = false;
                break;
            }
            advance -= fatigue;
            if(advance < 0) {
                advance = 0;
            }
            
        }

        if (success) {
            printf("success on day %d\n", ndays);
        }
        else {
            printf("failure on day %d\n", ndays);
        }
        
    }
    return 0;
}