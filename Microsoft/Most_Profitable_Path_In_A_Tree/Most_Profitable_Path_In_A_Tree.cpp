class Solution {
    vector<vector<int>> adj;
    vector<int> par,dis;
public:
    void dfs1(int u,int p,int d){
        dis[u] = d;
        par[u] = p;
        for(int v:adj[u]){
            if(v==p)continue;
            dfs1(v,u,d+1);
        }
    }
    int dfs2(int u,vector<int>&amount,int p){
        int ret = amount[u];
        int mxc = -INT_MAX;
        for(int v:adj[u]){
            if(v!=p){
                mxc= max(mxc,dfs2(v,amount,u));
            }
        }
        if(mxc==-INT_MAX) return ret;
        else return ret+mxc;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n,vector<int>());
       for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs1(0,0,0);
        int cur = bob;
        int bob_dis = 0;
        while(cur!=0){
            if(dis[cur]>bob_dis){
                amount[cur] = 0;
            }else if(dis[cur]==bob_dis){
                amount[cur]/=2;
            }
            cur = par[cur];
            bob_dis++;
        }
        return dfs2(0,amount,0);
    }
};