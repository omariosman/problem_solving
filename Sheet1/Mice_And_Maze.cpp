/*
Dijkstra
Omar Osman
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector< vector < pair <int, int>>> G;
int dis[110];


void Dij(int st) {
  memset(dis, 63, sizeof (dis));
  dis[st] = 0;
  priority_queue<pair<int, int>> PQ;
  PQ.emplace(0, st);
  while (PQ.size()){
    int d,u;
    tie(d, u) = PQ.top();
    PQ. pop();
    d *= -1;
    if(dis[u] != d) continue;
    for (pair<int, int> P:G[u]) {
      int v, len;
      tie(v, len) = P;
      if(d+len < dis[v]){
        dis[v] = d + len;
        PQ.emplace(-dis [v], v);
      }
    }
  }
}

int main() {
 
    G.resize(110);

    int n, e, timer, m;
    cin >> n >> e >> timer >> m;

    while (m--){
        int a, b;
        int cost;
        cin >> a >> b >> cost;    
        G[a].emplace_back(b, cost);
        G[b].emplace_back(a, cost);
  }

    Dij(e);
    int mice_exited_count = 0;
    for (int i = 1; i <= n; i++){
        if (dis[i] <= timer){
            mice_exited_count++;
        }
    }

    cout << mice_exited_count;



 
  return 0;

}
