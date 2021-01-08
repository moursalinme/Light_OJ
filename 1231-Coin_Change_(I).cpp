#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iterator>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
#ifdef LOCAL
#define _rp replace (_N.begin(), _N.end(), ',', ' ');
#define itrt istream_iterator<string>
#define out(_...) {string _N = #_; _rp; stringstream ss(_N); itrt it(ss);debug(it, _);}
inline void debug(itrt it) { cerr << endl;}
template <typename T, typename... X>
inline void debug(itrt it, T val, X ..._value) {
    cerr << "[" << *it << ": " << val << "] ";  
    debug(++it, _value...);
}
#else 
#define out(...)
#endif

int N, K;
vector<int> vec, can_use;
int64_t dp[55][1007];
const int M = 100000007;

int64_t calc (int pos, int sum) {
    if (!sum) {
        return 1;
    }
    if (pos == N) {
        return 0;
    }
    if (dp[pos][sum] != -1) {
        return dp[pos][sum];
    }
    int64_t answer = 0;

    for (int times = 1; times <= can_use[pos]; ++times) {
        int rest = sum - (vec[pos] * times);
        if (rest >= 0) {
            answer = (answer + calc (pos + 1, rest)) % M;
        }
    }
    answer = (answer + calc (pos+1, sum)) % M;
    return dp[pos][sum] = answer;
}

void solve () {
    cin >> N >> K;
    vec.resize(N);
    can_use.resize(N);
    memset (dp, -1, sizeof(dp));

    for (int& i : vec) 
        cin >> i;
    for (int& i : can_use)
        cin >> i;

    cout << calc (0, K) << endl;
    vec.clear();
    can_use.clear();
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
