#include<bits/stdc++.h>
#include <stack>
using namespace std;
typedef long long int ll;



void dfs(int i,unordered_map<int,list<int>>&adj,vector<bool>&vis,stack<int>&s){
	vis[i]=true;
  
	for(auto x:adj[i]){
		if(!vis[x]){
			dfs(x,adj,vis,s);
		}
	}
	s.push(i);
}

void rdfs(int i,vector<bool>&vis,unordered_map<int,list<int>>&trans){
	vis[i]=1;
	for(auto x:trans[i]){
		if(!vis[x]){
			rdfs(x,vis,trans);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}

	stack<int>s;
	vector<bool>vis(v+1,false);
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,adj,vis,s);
		}
	}
 
 unordered_map<int,list<int>>trans;
 for(int i=0;i<v;i++){
	 vis[i]=0;
	 for(auto c:adj[i]){
		 trans[c].push_back(i);
	 }
 }
 int ans=0;
 while(!s.empty()){
	 int top=s.top();
	 s.pop();
	 if(!vis[top]){
		 ans++;
		 rdfs(top,vis,trans);
	 }
 }

return ans;
}
int main(){
    
    return 0;
}