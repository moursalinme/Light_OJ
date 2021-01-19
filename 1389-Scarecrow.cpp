#include <bits/stdc++.h>
using namespace std; 

void solve () {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            ans ++;
            i += 2;
        }
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);
    
    int tt = 1, tc = 1;
    cin >> tt;

    while (tt--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }
    return 0;
}