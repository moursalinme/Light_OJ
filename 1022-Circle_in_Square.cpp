#include <bits/stdc++.h>
using namespace std;

const double pi  = 2 * acos(0.0);

int main() {
    int t;
    double r;
    cin >> t;

    for(int i = 1; i <= t; ++i) {
        cin >> r;
        cout << setprecision(2) << fixed ;
        cout << "Case " << i <<": " <<  ((2 *r) * (2 * r)) - (pi * r * r) << endl;
    }
    return 0;
} 