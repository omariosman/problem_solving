//DSU
//Status: Accepted
//Omar Osman
#include <bits/stdc++.h>
using namespace std;


const int N = 3e5 + 5;

class DSU {
    public:
    long long par[N], sz[N], sum[N];
    void init(int n){
       
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sum[i] = i;
            sz[i] = 1;
        }
        
    }
    
    int find(int x){
        if (par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    
    void merge(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv){
            return;
        }
        if(sz[u] < sz[v]){
            swap(u, v);
        }
        par[pv] = pu;
        sum[pu] += sum[pv];
        sz[pu] += sz[pv];
        
        
    }
    
    void mv(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        par[u] = pv;
        sum[pv] += u;
        sum[pu] -= u;
        sz[pv] += 1;
        sz[pu] -= 1;
    }
    
}dsu1, dsu2;


int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu1.init(n+1);
    dsu2.init(n+1);
    
    while(m1--){
        int p, q;
        cin >> p >> q;
        dsu1.merge(p, q);
    }
    while(m2--){
        int p, q;
        cin >> p >> q;
        dsu2.merge(p, q);
    }
    int ctr=0;
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <=n; j++ ){
            if(dsu1.find(i) != dsu1.find(j) && dsu2.find(i) != dsu2.find(j)){
                dsu1.merge(i, j);
                dsu2.merge(i, j);
                ctr++;
                ans.push_back({i, j});
            }
        }
    }
    
    cout << ctr << "\n";
    for(auto i: ans){
        cout << i.first << " " << i.second << "\n";
    }
    

    return 0;
}
