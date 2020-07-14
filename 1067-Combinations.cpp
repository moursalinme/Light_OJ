#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> fact(1000007);
const int M = 1000003;

ll minverse(long long a, long long b) 
{
    ll ret = 1;
    for (; b; b>>=1) {
        if(b&1) ret = (ret * a) % M;
        a = (a*a) % M;
    }
    return ret % M;
}

ll ncr(int n, int r) 
{
    ll up, down;
    up = fact[n];
    down = ((fact[r]) * (fact[n-r]))%M;
    down = minverse(down, M-2);
    up = (up*down)%M;
    return up;
}

void solve() 
{
    ll n, r;
    scanf("%lli%lli", &n, &r);
    if(n == r)      puts("1");
    else if(n < r)  puts("0");
    else            printf("%lli\n", ncr(n, r));
}

int main() 
{
    fact[0] = 1;
    for (int i = 1; i < 1000001; ++i) {
        fact[i] = ((ll)fact[i-1]*i) % M;
    }

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}
