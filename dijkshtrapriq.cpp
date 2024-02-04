#include<bits/stdc++.h>
 using namespace std;
 
 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    { 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,S});
        vector<int>dis(V,INT_MAX);
        dis[S]=0;
        
        while(!q.empty()){
            int node=q.top().second;
            int dist=q.top().first;
            q.pop();
            for(auto i:adj[node]){
                int abnode=i[0];
                int abdist=i[1];
                if(dist+abdist<dis[abnode]){
                    dis[abnode]=dist+abdist;
                    q.push({dis[abnode],abnode});
                }
            }
        } 
        return dis; 
    }
    int main(){
    return 0;
   }