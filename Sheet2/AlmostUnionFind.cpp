//Disjoint Set Union
//Status: Accepted
//Omar Osman

#include <bits/stdc++.h>
using namespace std;


const int N = 3e5 + 5;

class DSU {
    public:
    long long par[N], sz[N], sum[N];
    void init(int n){
       
        for(int i = 0; i < 2 * n; i++){
            par[i] = i % n + n;
            sum[i] = i % n;
            sz[i] = 1;
        }
        /*
                for (int i = 1; i<=n;i++) {
            par[i] = i+n;
            sum[i] = i;
            sz[i] = 1;
        }
        for (int i = n+1;i <= 2*n; i++) {
            par[i] = i;
            sum[i] = i - n;
            sz[i] = 1;
        }
        */
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
    
}dsu;


int main()
{
    int n, m;
    
    while(cin >> n >> m){
        dsu.init(n+1);
        for(int i = 0; i < m; i++){
            int a,p,q;
            cin >> a;
            if(a==1){
                cin >> p >> q;
                dsu.merge(p,q);
            } else if(a==2){
                cin >> p >> q;
                dsu.mv(p, q);
            } else if(a==3){
                cin >> p;
                int pp = dsu.find(p);
                cout << dsu.sz[pp] << " " << dsu.sum[pp] << "\n";
            }
        }
        
    }

    return 0;
}
