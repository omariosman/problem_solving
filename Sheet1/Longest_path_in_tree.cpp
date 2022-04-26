
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> nodes_array;



int dis[10010];


pair<int, int> BFS(int U){

    queue <int>q;

    q.push(U);

    dis[U] = 0;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for (int v: G[t]){

            if (dis[v] == -1){
                q.push(v);
                dis[v] = dis[t] + 1;
            }
        }
    }

    int node_index;
    int first_longest_path = 0;

    for (int i: nodes_array){
        int cur_dis = dis[i];
        if (cur_dis > first_longest_path){
            first_longest_path = cur_dis;
            node_index = i;

        } 
    }

    return make_pair(first_longest_path, node_index);

}



int main() {
  int n;
    cin >> n;
    int m = n - 1;
    G.resize(n);

    while(m--){
        int a,b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);

        nodes_array.push_back(a);
        nodes_array.push_back(b);


    }
    memset(dis, -1, sizeof(dis));

    pair<int, int> first_endpoint = BFS(0);
    
    memset(dis, -1, sizeof(dis));

    pair<int, int> actual_path = BFS(first_endpoint.second);

    cout << actual_path.first << endl;
    
    

    return 0;
}
