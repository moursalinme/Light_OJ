#include <bits/stdc++.h>
using namespace std;

inline void in(int &n) {
    scanf("%d",&n);
}

long long cal(int me, int lift) {
    if(me == 0) {
        return 0LL;
    }
    long long ret = 0;
    me < lift ? ret = (lift - me) * 4 : ret = (me - lift) * 4;
    ret += 19;
    ret += (me - 0) * 4;
    return ret;
}

int main() 
{
    int t, tc = 1, m, l;    
    in(t);

    while(t--) {
        in(m), in(l);
        long long answer = cal(m, l);
        printf("Case %d: %lld\n", tc++, answer);
    }
    return 0;
}

