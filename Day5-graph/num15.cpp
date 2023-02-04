#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
const int MAXN = 100005;
int n;
int d[MAXN],parent[MAXN][23];
bool check[MAXN];
vector<vector<int>> Graph;

void sparse(){
    for(int i=1;i<=20;i++){
        for(int j=0;j<n;j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int lca(int x,int y){
    if(d[y]>d[x]) swap(x,y);
    for(int i=19;i>=0;i--){
        if((d[x]-d[y])>=(1<<i)) x = parent[x][i];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(parent[x][i] != parent[y][i]){
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int main(){
    //freopen("input.txt","r",stdin);
    int tcase; scanf(" %d",&tcase); int c=1;
    while(tcase--){
        memset(check,0,sizeof(check));
        memset(d,0,sizeof(d));
        memset(parent, 0, sizeof(parent));
        Graph.clear();

        scanf(" %d",&n);
        Graph.resize(n+3);

        for(int i=1;i<n;i++){
            int x; scanf(" %d",&x);
            Graph[x-1].push_back(i);
        }
        for(int i=0;i<n;i++) sort(Graph[i].begin(),Graph[i].end());

        queue<pair<int,int>> dq;
        dq.push({0,0});
        check[0]=true;

        while(!dq.empty()){
            int now = dq.front().first;
            int depth = dq.front().second;
            dq.pop();
            d[now]=depth;

            for(int i=0;i<Graph[now].size();i++){
                int next = Graph[now][i];
                if(!check[next]){
                    check[next]=true;
                    parent[next][0]=now;
                    dq.push({next,depth+1});
                }
            }
        }

        sparse();

        ll ret=0;
        memset(check,0,sizeof(check));
        vector<int> vt;
        queue<int> q;
        q.push(0);
        check[0]=true;

        while(!q.empty()){
            int now = q.front();
            q.pop();

            vt.push_back(now);
            for(int i=0;i<Graph[now].size();i++){
                int next = Graph[now][i];
                if(!check[next]){
                    check[next]=true;
                    q.push(next);
                }
            }
        }
        for(int i=0;i<n-1;i++){
            int LCA = lca(vt[i],vt[i+1]);
            ll a = d[vt[i]] - d[LCA];
            ll b = d[vt[i+1]] - d[LCA];
            ret+=a; ret+=b;
        }

        printf("#%d %lld\n",c++,ret);
    }
}

