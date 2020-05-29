#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    
    char line[1024];
    bool flag = false;
    while(gets(line)) {
        for(int i=0; i < strlen(line); i++) {
            if (line[i] == '\"') {
                if (flag) {
                    printf("''");
                }
                else {
                    printf("``");
                }
                flag = !flag;
            }
            else {
                printf("%c", line[i]);
            }
        }
        printf("\n");
    }

    return 0;
}