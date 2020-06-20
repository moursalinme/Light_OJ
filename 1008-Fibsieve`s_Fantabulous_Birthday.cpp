#include <iostream>
#include <math.h>
 
using namespace std;

int main() 
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";

        long long int n;
        cin >> n;
        long long row, col, mid, high, low, dis;
        low = floor(sqrt(n));
        high = ceil(sqrt(n));

        if(low == high) {
             if( high & 1)  cout << 1 << " " << low << endl;
             else           cout << low << " " << 1 << endl;
             continue;
        }
        mid = ((high * high) + ((low * low) + 1)) / 2;
        dis = (mid - n);
 
        if(mid == n) cout << high << " " << high << endl;
        else {
            if(high & 1) {
                 if(dis > 0)    cout << high << " " << high - dis << endl;
                 else           cout << high + dis << " " << high << endl;
            }
            else {
                if(dis > 0) cout << high - dis << " " << high << endl;
                else        cout << high << " " << high + dis << endl;
            }
        }
    }
    return 0;
}