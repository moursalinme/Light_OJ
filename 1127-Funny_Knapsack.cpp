#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iterator>
#include <bitset>
using namespace std; 

vector<int64_t> make_subset (int n, vector<int> ref) {
    int tot = (1 << n);
    vector<int64_t> ret;

    for (int i = 0; i < tot; ++i) {
        int64_t sum = 0;
        for (int j = 0; (1 << j) <= i; ++j) {
            if ((1 << j) & i) {
                sum += ref[j];
            }
        }
        ret.emplace_back(sum);
    }
    if (!ret.size ()) 
        ret.emplace_back (0);
    return ret;
}

void solve () {
    int64_t n, w, temp;
    cin >> n >> w;
    vector<int> ar1, ar2;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        i & 1 ? ar1.emplace_back (temp) : ar2.emplace_back(temp);
    }

    vector<int64_t> subset1 = make_subset (ar1.size(), ar1), subset2 = make_subset (ar2.size(), ar2);
    sort (subset1.begin(), subset1.end());
    sort (subset2.begin(), subset2.end());
    int64_t cnt = 0, sz = subset1.size();

    for (int i = 0; i < sz && subset1[i] <= w; ++i) {
        cnt += upper_bound (subset2.begin(), subset2.end(), w - subset1[i]) - subset2.begin();
    }
    cout << cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);
    
    int tt, tc = 1;
    cin >> tt;

    while (tt--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }
    return 0;
}