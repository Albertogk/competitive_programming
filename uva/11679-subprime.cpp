#include <cstdio>

using namespace std;

int main() {

    int b, n, debtor, creditor, amount, last_amount_debtor, last_amount_creditor;
    int money[20];
    while(scanf("%d %d", &b, &n), b|n) {
        
        int can_pay = b;

        for(int i=0; i<b; i++) {
            scanf("%d", &money[i]);
        }

        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &debtor, &creditor, &amount);
            debtor--;
            creditor--;
            last_amount_debtor = money[debtor];
            last_amount_creditor = money[creditor];

            money[debtor] -= amount;
            money[creditor] += amount;

            if(last_amount_debtor >= 0 && money[debtor] < 0) {
                can_pay--;
            }
            
            if(last_amount_creditor < 0 && money[creditor] >= 0) {
                can_pay++;
            }
        }

        if(can_pay < b) {
            printf("N\n");
        }
        else {
            printf("S\n");
        }
    }
}