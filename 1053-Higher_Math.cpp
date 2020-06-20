#include <iostream>
#include <algorithm>

using namespace std;
inline void in(int &n) { scanf("%d", &n);}

int main() 
{
    int t, tc = 0;
    in(t);
    int ara[3];

    while(tc++ < t) {
        printf("Case %d: ", tc);
        int i = 0; 
        while( i < 3)  {
            in(ara[i]);
            ++i;
        }
        sort(ara, ara+3);
        if(ara[2] * ara[2] == ((ara[1] * ara[1]) + (ara[0] * ara[0]))) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}