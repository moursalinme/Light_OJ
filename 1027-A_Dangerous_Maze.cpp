#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    bool all_neg = 1;
    int n;
    cin >> n;
    vector<int> ara(n);
    
    for (int& i : ara)  {
        cin >> i;
        i > 0 ? all_neg = 0 : 1;
    }

    if(all_neg) {
        cout << "inf" << endl;
        return;
    }

    ll answer = 0, div = 0;
    for (int i = 0; i < n; ++i) {
        answer += (abs(ara[i]));
        if(ara[i] < 0)      ++div;
    }

    if(answer % (n-div)) {
        ll p = answer, q = n-div, lim = min(p, q);

        for (int i = 2; i < q; ++i) {
            while(p%i == 0 && q %i == 0) {
                p/= i;
                q/=i;
            }
        }
        cout << p << "/" << q << endl;
    }
    else cout << answer / (n-div) << "/1" << endl;
}

int main() 
{
    IO;
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        solve();
    }
    
    return 0;
}
