//knapsack
//Notes: 
/*
  - each rack is considered one item
  - the weight = the value
/*
//Omar Osman

#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int W[105];
int n, k, d;

int knapsack(int i, int rem){
    
    if(i == n || rem == 0){
        return 0;
    }
    
    int &ret = dp[i][rem];
    if(~ret){
        return ret;
    }
    ret = 0;
    if(rem >= W[i]){
        ret = knapsack(i+1, rem - W[i]) + W[i];
    }
    return ret = max(knapsack(i+1, rem) + 0, ret);
    
    
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--){
        
        memset(dp, -1, sizeof(dp));
        memset(W, 0, sizeof(W));
        cin >> n >> k; //n = number of racks
        for(int i = 0; i < n; i++){
            cin >> d;
            int rack_items = 0;
            int units;
            for(int j = 0; j < d; j++){
                cin >> units;
                rack_items += units;  
            }
            W[i] = rack_items;
        }
        
        cout << knapsack(0, k) << "\n";

        
    }
    
}
