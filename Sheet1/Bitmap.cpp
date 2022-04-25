//multisource BFS
//Omar Osman

#include <bits/stdc++.h>
using namespace std;


pair<int, int> moves[4] = {{-1,0},{0, 1},{1, 0},{0, -1}};

int bitmap[205][205];

int r, c;

int dis[205][205];
bool vis[205][205];

queue<pair<int, int>>q;


void reset_vis(){
    for (int i = 1; i <= r; i++){
      for(int j = 1; j <= c; j++){
         vis[i][j] = false;
      }
    }  
}


void print_bitmap(){
      for (int i = 1; i <= r; i++){
          for(int j = 1; j <= c; j++){
            cout << bitmap[i][j] << "\n";
          }
    }  
    
    
}


void print_dis(){
      for (int i = 1; i <= r; i++){
          for(int j = 1; j <= c; j++){
            cout << dis[i][j] << " ";
          }
          cout << "\n";
    }  
    
    
}


bool isInside(int i , int j){
    return i >= 1 && i <= r && j >=1 & j <= c;
}


void BFS(){
    while(!q.empty()){
        auto node = q.front();
        int i = node.first;
        int j = node.second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int new_i = i + moves[k].first;
            int new_j = j + moves[k].second;
            if(isInside(new_i, new_j) && !vis[new_i][new_j] && bitmap[new_i][new_j] != 1){
                vis[new_i][new_j] = true;
                q.push({new_i, new_j});
                dis[new_i][new_j] = dis[i][j] + 1;
            }
        }
    }
}


void start_process(){
      for (int i = 1; i <= r; i++){
          for(int j = 1; j <= c; j++){
              if(bitmap[i][j] == 1){
                dis[i][j] = 0; 
                vis[i][j] = true;
                q.push({i, j});
              }
          }
    }  
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        //TEST CASE START
        //memset(dis, 63, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        scanf("%d%d",&r, &c);
        //init();
        char str[200];
        //read bitmap
        for (int i = 1; i <= r; i++){
            scanf("%s", str);
            for(int j = 1; j <= c; j++){
                    bitmap[i][j] = str[j-1] - '0';
            }
        }   
        
        //start processing
        start_process();
        BFS();
        
        print_dis();        
        //TEST CASE END
        
        
    }

    //print_bitmap();
    
}
