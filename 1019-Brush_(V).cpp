/**
 *  Straight forward implementation of Dijkstra's algorithm
*/
#include <bits/stdc++.h>
#define m  105

using namespace std;

vector<pair<int, int>>graph[m];
vector<long long> dis(m);
int node, edge, u, v, w;

void dijkstra() {
    for(int i = 0 ; i < m; ++i) {
        dis[i] = 1e18;
    }
    dis[1] = 0;
    set<pair<long long, int>> ms;
    ms.insert(make_pair(0,1));

    while(!ms.empty()) {
        auto it = ms.begin();
        ms.erase(ms.begin());
        u = it->second;

        for(pair<int, int> i : graph[u]) {
            if(dis[i.first] > dis[u] + i.second) {
                dis[i.first] = dis[u] + i.second;
                ms.insert(make_pair(dis[i.first], i.first));
            }
        }
    }
}


int main() 
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; ++i) {
        cin>> node >> edge;

        while(edge--) {
            cin>> u>>v>>w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        dijkstra();
        cout << "Case " << i << ": " ;
        
        if(dis[node]!=1e18) {
            cout << dis[node] << endl;
        } else {
            cout << "Impossible" << endl;
        }
        if(i != t) {
            for(int i= 0 ; i <= node; ++i) {
                graph[i].clear();
            }
        }
    }
    return 0;
}