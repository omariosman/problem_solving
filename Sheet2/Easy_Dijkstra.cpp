#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAX 1061109567
typedef long long ll;

vector< vector < pair <ll, ll>>> G;
ll dis[(int)(1e7 + 6)];
ll visited[(int)(1e7+5)];



void Dij(int st) {
dis[st] = 0;
priority_queue<pair<ll, ll>> PQ;
PQ.emplace(0, st);
while (PQ.size()){
    ll d,u;
    tie(d, u) = PQ.top();
    PQ. pop();
    d *= -1;
    if(dis[u] != d) continue;
    for (pair<ll, ll> P:G[u]) { 
    ll v, len;
    tie(v, len) = P;
    if(d+len < dis[v]){
        dis[v] = d + len;
        PQ.emplace(-dis [v], v);
    }
    }
}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   G.resize((int)1e4+5);

    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >>n >> m;


        
        memset(visited, 0, sizeof(visited));
        memset(dis, 63, sizeof(dis));
for(int i = 0; i <= n; i++)G[i].clear();
        while (m--){
            ll a, b;
            ll cost;
            cin >> a >> b >> cost;    

            G[a].emplace_back(b, cost);

        }
        ll src, dest;
        cin >> src >> dest;

    
    
        Dij(src);
        (dis[dest] >= MAX ? cout << "NO\n" : cout << dis[dest] << "\n");
                
    }



return 0;

}
