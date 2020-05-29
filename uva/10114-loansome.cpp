#include <cstdio>

using namespace std;

bool check_conditions(float loan, float car_value) {
    return (loan < car_value);
}

int main() {

    int months, n_records, month, prev_month, result;
    double down, loan, deprecated, prev_deprecated;

    while(scanf("%d %lf %lf %d", &months, &down, &loan, &n_records), months > 0) {
        prev_month = 0;
        double car_value = loan + down;
        double pay_loan = loan/months;
        result = 0;
        bool end = false;
        for(int i=0; i<n_records; i++) {
            scanf("%d %lf", &month, &deprecated);
            if (!end) {
                if (month == 0) {
                    car_value -= (car_value*deprecated);
                    prev_deprecated = deprecated;
                    prev_month = month;
                    result++;
                    if(check_conditions(loan, car_value)) {
                        end = true;
                        printf("0 months\n");
                        continue;
                    }
                }
                
                for (; result < month; result++) {
                    car_value -= (car_value*prev_deprecated);
                    loan -= pay_loan;
                    if(check_conditions(loan, car_value)) {
                        end = true;
                        if(result == 1) {
                            printf("1 month\n");
                        }
                        else {
                            printf("%d months\n", result);
                        }
                        break;
                    }
                }
                if(!end && month > 0) {
                    car_value -= (car_value*deprecated);
                    loan -= pay_loan;
                    if(check_conditions(loan, car_value)) {
                        if(result == 1) {
                            printf("1 month\n");
                            end = true;
                        }
                        else {
                            printf("%d months\n", result);
                            end = true;
                        }
                    }
                    result++;

                    if (i + 1 == n_records) {
                        for(; result<months; result++) {
                            car_value -= (car_value*deprecated);
                            loan -= pay_loan;
                            if(check_conditions(loan, car_value)) {
                                end = true;
                                if(result == 1) {
                                    printf("1 month\n");
                                }
                                else {
                                    printf("%d months\n", result);
                                }
                                break;
                            }
                        }
                    }
                    
                }

                prev_deprecated = deprecated;
                
            }
            
        }
        if(!end) {
            printf("%d months\n", months);
        }
    }
    return 0;
}