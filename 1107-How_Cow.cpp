#include <iostream>
using namespace std;

inline void in(int &n) {scanf("%d",&n);}

int main() 
{
    int t, tc = 0, qury, bx1, by1, bx2, by2, x1, y1;
    in(t);

    while(tc++ < t) {
        scanf("%d%d%d%d%d", &bx1, &by1, &bx2, &by2, &qury);
        printf("Case %d:\n", tc);

        while(qury--) {
            scanf("%d%d", &x1, &y1);
            if(x1 >= bx1 and x1 <= bx2 and (y1 >= by1 && y1 <= by2)) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
    }
    return 0;
}