#include <bits/stdc++.h>

using namespace std;
#define out(x) "[" << #x << ": " << x << "] "

void solve() {
    int p, l;
    scanf("%d%d", &p, &l);
    p -= l;
    if(p <= l || p == 0) {
        puts("impossible");
        return;
    }
    int limit = sqrt(p) + 1;
    set <int> ms;

    for (int i = 1; i <= limit; ++i) {
        if(!(p%i)) {
            if(i > l)       ms.insert(i);
            if(p/i > l)     ms.insert(p/i);
        }
    }
    set <int> :: iterator it = ms.begin();
    
    for (; it!= ms.end(); ++it) {
        if(++it == ms.end()) {
            --it;
            printf("%d\n", *it);
        }
        else {
            --it;
            printf("%d ", *it);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        solve(); 
    }
    return 0;
}
