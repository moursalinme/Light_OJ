#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll M = 1000000007;
const int nax = 2*(1e6+7);
ll fact[nax];

ll bm(ll a, ll b) {
    ll ret = 1;
    for (; b; b>>=1) {
        if(b&1) ret = (ret * a) % M;
        a = (a * a) % M;
    }
    return ret % M;
}

ll cal(int n, int r) {
    ll up = fact[n];
    ll down = (fact[r] * fact[n-r]) % M;
    down = bm(down, M-2);
    return (down*up) % M; 
}

void solve() {
    int n, r;
    scanf("%d%d", &n, &r);
    int sum = n+r-1;
    printf("%lli\n", cal(sum, r-1));
}

int main() 
{
    fact[0] = 1;
    for (int i = 1; i < nax; ++i)
        fact[i] = (fact[i - 1] * i) % M;

    int t = 1;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        solve();
    }
    
    return 0;
}
