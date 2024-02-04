 #include<bits/stdc++.h>
 using namespace std;
 
 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    { vector<int>dis(V,INT_MAX);
        dis[S]=0;
        set<pair<int,int>>s;
        s.insert(make_pair(0,S));
        
        while(!s.empty()){
            pair<int,int> x=*(s.begin());
            int diss=x.first;
            int node=x.second;
         
            s.erase(s.begin());
            for(auto v:adj[node]){
                if(diss+v[1]<dis[v[0]]){
                    auto record=s.find(make_pair(dis[v[0]],v[0]));
                    if(record!=s.end())s.erase(record);
                    
                    dis[v[0]]=diss+v[1];
                    s.insert({dis[v[0]],v[0]});
                }
                
            }
        }
        return dis;
        
    }
    int main(){
    return 0;
   }