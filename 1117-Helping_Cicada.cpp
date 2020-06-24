#include <iostream>
#include <vector>

using namespace std;
long long answer;
int n, m;
vector<int> collection;

template <typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a%b);
}

template <typename T>
T lcm(T a, T b) {
    return (a * b) / gcd(a, b);
}

void bktk(int now, vector<int>& pre) {
    if(now == m) {
        if(collection.empty()) {
            return;
        }
        long long gun = collection[0];
        for (auto i : collection) {
            gun = lcm(gun, (long long) i);
        }
        if(collection.size() &1) {
            answer -= (n / gun);
        }
        else answer += (n/gun);
        return;
    }
    bktk(now+1, pre);
    collection.push_back(pre[now]);
    bktk(now+1, pre);
    collection.pop_back();
}

void run() {
    scanf("%d%d", &n, &m);
    vector<int> pre(m);
    answer = (long long) n;
    
    for (auto& i: pre) {
        scanf("%d", &i); 
    }

    bktk(0, pre); 
    printf("%lld\n", answer);
}

int main() 
{
    int t;
    scanf("%d", &t);
    
    for(int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        run();
    }
    return 0;
}
