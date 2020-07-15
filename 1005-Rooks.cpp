#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if(k > n) {
        cout << "0" << endl;
        return;
    }
    long long r = k, answer = 1, q = 1;
    
    for (int i = 0; i < k; ++i, --n, --r) {
        answer *= (n*n);
        q *= r;
        long long g = __gcd(answer, q);
        answer /= g;
        q /= g;
    }
    cout << answer/q << endl;
}

int main() 
{
    IO;
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        solve();
    }   
    return 0;
}
