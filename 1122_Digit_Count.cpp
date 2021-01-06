#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iterator>
#include <sstream>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int maxd, n;
vector<int> ara;
vector<bool> vis(12, 0);
long long dp[12][12];

int call (int pos, int last) {
    if (pos == maxd) 
        return 1;

    if (dp[pos][last] != -1) 
        return dp[pos][last];
    
    int answer = 0;

    for (int i = 0; i < n; ++i) 
        if (pos == 0 || abs(last - ara[i]) <= 2) 
            answer += call (pos + 1, ara[i]);

    return dp[pos][last] = answer;
}


void solve () {
    cin >> n >> maxd;
    ara.resize(n);
    memset(dp, -1, sizeof(dp));

    for (int& i: ara) 
        cin >> i;

    cout << call(0, 0) << endl;;
}
 
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1, tc = 1;
    cin >> t;

    while(t--) {
        cout << "Case " << tc++ << ": ";
        solve();
    }
    return 0;
}
