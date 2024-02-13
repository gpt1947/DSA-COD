#include<bits/stdc++.h>
void dfs(int i,int parent,int &timer,vector<int>&dist,vector<int>&low,
vector<vector<int>>&result,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
    vis[i]=true;
    dist[i]=low[i]=timer++;

    for(auto nbr:adj[i]){
        if(nbr==parent)continue;
        if(!vis[nbr]){
            dfs(nbr,i,timer,dist,low,result,adj,vis);
            low[i]=min(low[i],low[nbr]);
            if(low[nbr]>dist[i]){
                vector<int>ans;
                ans.push_back(i);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            low[i]=min(low[i],dist[nbr]);
        }
    }
}




vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>>adj;

    for(int i=0;i<edges.size();i++){
       int u=edges[i][0];
       int v=edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    int timer=0;
    vector<int>dist(v);
    vector<int>low(v);
    int parent=-1;
    unordered_map<int,bool>vis;

    for(int i=0;i<v;i++){
        dist[i]=-1;
        low[i]=-1;
    }
    vector<vector<int>>result;
     
     for(int i=0;i<v;i++){
         if(!vis[i]){
             dfs(i,parent,timer,dist,low,result,adj,vis);
         }
     }
    
    return result;



}