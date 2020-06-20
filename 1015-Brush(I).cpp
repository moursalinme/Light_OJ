#include <iostream>
using namespace std;
 
int main()
{
    int sum ,t, v, temp;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        sum = 0;
        cin >> v;
    
        while(v --) {
            cin >> temp;
            if(temp > 0) sum += temp;
        }
        cout << "Case " << i << ": " << sum << endl;
    }
    return 0;
}