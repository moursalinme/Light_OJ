#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ncr(int n, int r) {
    if(r == 0) return 1;
    if(r > n/2) ncr(n, n-r);
    return n*ncr(n-1, r-1) / r;
}

void solve() 
{
    ll n, r;
    scanf("%lli%lli", &n, &r);
    if(r > n)   puts("0");
    else {
        ll k = n;
        n = ncr(n, r);
        n *= n;

        for (int i = 1; i <= r ; ++i) {
            n *= i;
        }
        printf("%lli\n", n);
    }
}

int main() 
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}
