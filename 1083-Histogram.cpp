#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> ara(n+3), forward(n+1), backward(n+1);
    
    for (int i = 1; i <= n; ++i)  
        scanf("%d", &ara[i]);

    priority_queue <pair<int, int>, vector<pair<int, int>>> q;
    for (int i = 1; i <= n; ++i) {
        if(!q.empty()) {
            pair<int, int> frnt = q.top();
            while(frnt.first > ara[i] && (!q.empty())) {
                q.pop();
                forward[frnt.second] = (i-1) - frnt.second; 
                if(!q.empty()) frnt = q.top();
            }
        }
        q.push({ara[i], i});
    }

    while(!q.empty()) {
        pair<int, int> frnt = q.top();
        q.pop();
        forward[frnt.second] = n - frnt.second; 
    }

    for (int i = n; i >= 1; --i) {
        if(!q.empty()) {
            pair<int, int> frnt = q.top();
            while(frnt.first > ara[i] && (!q.empty())) {
                q.pop();
                backward[frnt.second] = frnt.second - (i+1); 
                if(!q.empty()) frnt = q.top();

            }
        }
        q.push({ara[i], i});
    }

    while(!q.empty()) {
        pair<int, int> frnt = q.top();
        q.pop();
        backward[frnt.second] = frnt.second - 1; 
    }

    ll answer = -1e8;
    for (int i = 1; i <= n; ++i) {
        ll temp = (forward[i] + backward[i] + 1) * ara[i];
        answer = max(answer, temp);
    }
    printf("%lld\n", answer);
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