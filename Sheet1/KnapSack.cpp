// 0-1 Knapsack
//Dynamic Programming
//Omar Osman

#include <bits/stdc++.h>
using namespace std;

int sz, n;
int W[2005], V[2005];

int dp[2005][2005];

int knapsack(int i, int rem){
    
    if(i == n || rem <= 0){
        return 0;
    }
    
    
    
    int ret = dp[i][rem];
    if(~ret){
        return ret;
    }
    
    if(rem >= W[i]){
        ret = knapsack(i+1, rem - W[i]) + V[i];    
    }
    
    dp[i][rem] = max(knapsack(i+1, rem) + 0, ret);
    
    return dp[i][rem];
    
}


int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &sz, &n);
    for(int i = 0; i < n; i++){
        cin >> W[i] >> V[i];
    }
    
    cout << knapsack(0, sz);
}
