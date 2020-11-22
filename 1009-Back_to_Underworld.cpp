#include <bits/stdc++.h>
using namespace std;

vector<int> fights[20000+1];
vector<bool> vis(20001, 0);
int lyc = 0, vam = 0, calls = 0;

void dfs(int now, bool lycan) {

    for (int i : fights[now]) {
        if(vis[i] == 0) {
            vis[i] = 1;
            ++calls;

            if(lycan) ++vam;
            else ++lyc;
            
            dfs(i, !lycan);
        }
    }
}


void solve () {
    int n, u, v, mx = -1;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> u >> v;
        fights[u].push_back(v);
        fights[v].push_back(u);
        mx = max(mx, max(u, v));
    }

    int ans = 0;

    for (int i = 1; i <= mx; ++i) {
        if(vis[i] == 0 && fights[i].size() > 0) {
            vis[i] = 1;
            bool ok = lyc > vam;
            dfs(i, lyc > vam);

            if(calls) {
                if(ok)  ++lyc;
                else    ++ vam;
                calls = 0;
            }
            ans += max(lyc, vam);
            lyc = 0;
            vam = 0;
        }
    }
    
    cout << ans << endl;
    
    for (int i = 0; i <= mx; ++i) {
        fights[i].clear();
        vis[i] = 0;
    }
}

int main() 
{
    int t = 1, tc = 1;
    cin >> t;

    while(t--) {
        cout << "Case " << tc++ << ": ";    
        solve();
    }

    return 0;
}