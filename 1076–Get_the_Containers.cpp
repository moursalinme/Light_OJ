#include <iostream>
using namespace std;

long long check(long long a) {
    long long x = 0;
    for (long long i = 5; a/i >= 1; i *= 5) {
        x += a/i;
    }
    return x;
}

void run() {
    int n;
    cin >> n;
    long long x, mid, lo = 0, hi = 1e18, found_num;
    bool found = 0;
    
    while(lo <= hi) {
        mid = lo + ((hi-lo)/2);
        x = check(mid);
        if(x == n) {
            found_num = mid;
            found = 1;
            hi = mid-1;
        }
        else if(x > n) {
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    if(found) {
        cout << found_num << endl;
    }
    else cout << "impossible" << endl;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        run();
    }
    return 0;
}