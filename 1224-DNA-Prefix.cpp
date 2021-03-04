#include <bits/stdc++.h>
using namespace std; 

struct Trie {
    struct Node {
        Node *next[4];
        int cnt;

        Node () {
            for (int i = 0; i < 4; ++i) {
                next[i] = NULL;
            }
            cnt = 0;
        }
    }; 
    
    Node *root;

    Trie () {
        root = new Node ();
    }

    int add (string s) {
        int val, sz = s.size(), ret = 1;
        Node *cur = root;

        auto check = [&] (const char ch) {
            return ch == 'A' ? 0 : ch == 'C' ? 1 : ch == 'G' ? 2 : 3;
        };

        for (int i = 0; i < sz; ++i) {
            val = check (s[i]);
            
            if (cur-> next[val] == NULL) {
                cur-> next[val] = new Node ();
            }
            cur = cur-> next[val];
            cur-> cnt++;
            ret = max (ret, (i+1) * cur-> cnt);

        }
        return ret;
    }

    void clear (Node *cur) {
        for (int i = 0; i < 4; ++i) {
            if (cur-> next[i]) {
                clear (cur-> next[i]);
                delete (cur-> next[i]);    
            }
        }
    }

    void clear() {
        clear (root);
    }
};

void solve () {
    int n, ans = 1;
    cin >> n;
    string s;
    Trie t;

    while (n--) {
        cin >> s;
        int ret = t.add (s);
        ans = max (ans, ret);
    }
    cout << ans << endl;
    t.clear ();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t = 1, tc = 1;
    cin >> t;

    while (t--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }
    return 0;
}
