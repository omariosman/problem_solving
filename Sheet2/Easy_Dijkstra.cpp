#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAX 1061109567
typedef long long ll;
ll n;
vector< vector < pair <ll, ll>>> G;
//ll dis[(int)(1e7 + 6)];
//ll visited[(int)(1e7+5)];



ll Dij(ll st, ll dest) {
    vector<ll>dis(n, INT_MAX);
dis[st] = 0;
priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ;
PQ.push({0, st});
while (PQ.size()){
    ll d,u;
    d = PQ.top().first;
    u = PQ.top().second;
    
    if(u == dest){
        return d;
    }
    PQ. pop();
    //d *= -1;
    if(d > dis[u]) continue;
    for (pair<ll, ll> &P:G[u]) { 
    ll v, len;
    v = P.first;
    len = P.second;
    if(dis[u]+len < dis[v]){
        dis[v] = dis[u] + len;
        PQ.push({dis [v], v});
    }
    }
}
return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cout.tie(NULL);
   

    int t;
    cin >> t;
    while(t--){
        ll m;
        cin >>n >> m;
G.clear();        
G.resize(n);
        
        //memset(visited, 0, sizeof(visited));
        //memset(dis, 63, sizeof(dis));

        while (m--){
            ll a, b;
            ll cost;
            cin >> a >> b >> cost;    
            a--;
            b--;
            G[a].push_back({b, cost});
            //G[b].emplace_back(a, cost);
        }
        ll src, dest;
        cin >> src >> dest;

    
    
        int final_ans = Dij(src-1, dest-1);
        if (final_ans == -1){
            cout << "NO\n";
        } else{
            cout << final_ans << "\n";
        }
        //(dis[dest] >= MAX ? cout << "NO\n" : cout << dis[dest] << "\n");
                
    }



return 0;

}
