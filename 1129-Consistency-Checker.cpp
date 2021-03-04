#include <bits/stdc++.h>
using namespace std; 

struct Trie {
#define mx 11
    struct Node {
        Node *next[mx];
        bool end;

        Node () {
            for (int i = 0; i < mx; ++i) {
                next[i] = NULL;
            }
            end = 0;
        }
    }; 
    
    Node *root;

    Trie () {
        root = new Node ();
    }

    bool add (string s) {
        int val, sz = s.size();
        Node *cur = root;
        bool ret = 1;

        for (int i = 0; i < sz; ++i) {
            val = s[i] - '0';
            
            if (cur-> next[val] == NULL) {
                cur-> next[val] = new Node ();
            }
            cur = cur-> next[val];

            if (i == sz - 1) {
                if (cur-> end) {
                    ret = 0;
                    break;
                }
                cur-> end = 1;
            }

            if (i < sz - 1 && cur-> end) {
                ret = 0;
                break;
            } 
        }
        return ret;
    }

    void clear (Node *cur) {
        for (int i = 0; i < mx; ++i) {
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
    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort (v.begin(), v.end(), [&] (const string a, const string b){
        return a.size() < b.size();
    });
    Trie t;
    bool ok = true;

    for (int i = 0; i < n; ++i) {
        if(t.add (v[i]) == false) {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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
