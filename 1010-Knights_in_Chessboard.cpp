/**
 *  Find the pattern 
 *  Check the cases where row or col = 1 , 2
*/

#include <iostream>
#include <cmath>
 
using namespace std;
int m, n;
 
void run() {
    scanf ("%d%d", &m, &n);
    if(m == 1 || n == 1) {
        printf("%d\n", max(m, n));
        return;
    }
    if(m == 2 || n == 2) {
        if(m==2 && n == 2) {
            printf("4\n"); 
        }
        else {
            int not_2 = max(m, n);
            int ans = not_2 /4;
            ans*=4;
            int rem = not_2 % 4;
            if(rem) {
                rem == 1 ? ans += 2 : ans += 4;
            }
            printf("%d\n", ans);
        }
        return;
    }
    printf("%d\n", (int) ceil((m*n)/2.0));
}
 
int main()
{
    int t, tc = 1;
    scanf("%d", &t);
 
    while(t--) {
        printf("Case %d: ", tc++);
        run();
    }
    return 0;
}