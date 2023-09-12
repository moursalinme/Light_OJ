#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define out(...) 
#endif

#define endl '\n'
#define ff first
#define ss second
using i64 = long long;

const int N = 12;
vector<int> ar;
int mod;
int last;
int dp[N][92][92][2];

int call (int pos, int sum, int dsum, int small) {

        if (pos == last) return sum == 0 && dsum == 0;

        if (dp[pos][sum][dsum][small] != -1) return dp[pos][sum][dsum][small];

        i64 ret = 0;

        int limit = ar[pos];
        if (small) limit = 9;
        int start = 0;

        for (int i = start; i <= limit; ++i) {
                ret += call (pos + 1, ((sum * 10) + i) % mod, (dsum + i) % mod, small | (i < ar[pos]));
        }

        return dp[pos][sum][dsum][small] = ret;
}

void addBinary (int n) {
        vector<int> v;
        while (n > 0) {
                v.push_back(n % 10);
                n /= 10;
        }
        reverse (v.begin(), v.end());
        ar = v;
        last = v.size();
        memset(dp, -1, sizeof dp);
}

void solve (int testNo) 
{       
        int a, b, k; cin >> a >> b >> k;
        if (k > 81) {
                cout << 0 << endl;
                return;
        }
        mod = k;

        addBinary(b);
        int ans = call(0, 0, 0, 0);

        addBinary(a - 1);
        int ans2 = call(0, 0, 0, 0);

        cout << ans - ans2 << endl;
}   

signed main() {
        ios::sync_with_stdio(false); 
        cin.tie(NULL); 

        int tc = 1;
        cin >> tc;

        for (int i = 1; i <= tc; ++i) { 
                cout << "Case " << i << ": ";
                solve (i);
        }
        
        return 0;
}
