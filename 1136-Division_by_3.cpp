#include <bits/stdc++.h>

using namespace std;
inline void in(int &n) { scanf("%d", &n); }

int fn(int n) {
    int ret = n/3;
    ret *= 2;
    if(n % 3 == 2) ret ++;
    return ret;
}

int main() 
{
    int t, tc = 1, m, n;
    in(t);

    while(t--) {
        in(m); in(n);
        printf("Case %d: %d\n", tc++, fn(n) - fn(m-1));
    }
}