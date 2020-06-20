#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t, tc = 0;
    scanf("%d", &t);

    while(tc++ < t) {
        printf("Case %d:\n", tc);
        
        vector<string> forward, backward;
        string user, temp, cur_page = "http://www.lightoj.com/";

        while (cin >> user, user != "QUIT") {
            if(user == "VISIT") {
                cin >> temp;
                forward.clear();
                backward.push_back(cur_page);
                cur_page = temp;
                cout << cur_page << endl;
            }
            if(user == "FORWARD") {
                if(!forward.empty()) {
                    backward.push_back(cur_page);
                    temp = forward.back();
                    cur_page = temp;
                    forward.pop_back();
                    cout << temp << endl;
                }
                else cout << "Ignored" << endl;
            }
            if(user == "BACK") {
                if(cur_page != "http://www.lightoj.com/" && (!backward.empty())) {
                    forward.push_back(cur_page);
                    temp = backward.back();
                    backward.pop_back();
                    cur_page = temp;
                    cout << cur_page << endl;
                }
                else cout << "Ignored" << endl;
            }
        } 
    }
    return 0;
}