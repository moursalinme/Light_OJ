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

void prepare_subset (vector<int64_t>& vec, int tot, int pos, int64_t sum, vector<int> reference) {
    vec.emplace_back (sum);
    if (pos < tot) {
        prepare_subset (vec, tot, pos + 1, sum, reference);;
        prepare_subset (vec, tot, pos + 1, sum + reference[pos], reference);
        prepare_subset (vec, tot, pos + 1, sum + (2 * reference[pos]), reference);
    }
}

void solve () {
    int64_t n, k, temp;
    bool found = 0;

    scanf("%lld%lld", &n, &k);
    vector<int> ar1 (n/2), ar2(n - (n/2));
    
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        i < (int) n / 2 ? ar1[i] = temp : ar2[i - (int) (n / 2)] = temp; 
    }

    vector<int64_t> subset1, subset2;
    prepare_subset (subset1, (n / 2), 0, 0, ar1);
    prepare_subset (subset2, n - (n / 2), 0, 0, ar2);

    sort (subset2.begin(), subset2.end());
    int sz = subset1.size(), sz2 = subset2.size();

    for (int i = 0; i < sz; ++i) {
        if (binary_search (subset2.begin(), subset2.end(), k - subset1[i])) {
            found = 1;
            break;
        }
    }
    printf("%s\n", found ? "Yes" : "No");
}
 
int main() {
    int tt, tc = 1;
    scanf ("%d", &tt);
    
    while (tt--) {
        printf("Case %d: ", tc++);
        solve ();
    }
    return 0;
}