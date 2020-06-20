#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main() 
{
    int t, tc = 0;
    cin >> t;

    while(tc++ < t) {
        cout << "Case " << tc << ":\n";

        int n, cmd, temp;
        cin >> n >> cmd;
        deque<int> q;
        string s;

        while(cmd--) {
            cin >> s;

            if(s == "pushLeft") {
                cin >> temp;
                if(q.size() < n) {
                    q.push_front(temp);
                    cout << "Pushed in left: " << temp << endl;
                }
                else cout << "The queue is full" << endl; 
            }
            else if(s == "pushRight") {
                cin >> temp;
                if(q.size() < n) {
                    q.push_back(temp);
                    cout << "Pushed in right: " << temp << endl;
                }
                else cout << "The queue is full" << endl; 
            }
            else if(s == "popLeft") {
                if(q.size() > 0) {
                    cout  << "Popped from left: " << q.front() << endl;
                    q.pop_front();
                }
                else cout << "The queue is empty" << endl;
            }
            else if(s == "popRight") {
                if(q.size() > 0) {
                    cout << "Popped from right: " << q.back() << endl;
                    q.pop_back();
                }
                else cout << "The queue is empty" << endl;
            }
        }
    }
    return 0;
}