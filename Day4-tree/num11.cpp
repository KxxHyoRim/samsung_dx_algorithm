#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n1, n2, depthN1, depthN2;
int subSize[10001];
list<int> adjList[10001];
int parent[10001];

int dfs(int idx, int depth);

int findLCA();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num11.txt", "r", stdin);

    int tc, v, e, v1, v2;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> v >> e >> n1 >> n2;
        for (int i = 0; i < e; i++) {
            cin >> v1 >> v2;
            adjList[v1].push_back(v2);
            parent[v2] = v1;
        }
        dfs(1, 0); // subtree size 구하기
        int lca = findLCA();
        cout << "#" << t << " " << lca << " " <<  subSize[lca] << endl;
    }
    return 0;
}


int findLCA() {
    int isN1Deeper = depthN1 > depthN2;
    int sub = abs(depthN1 - depthN2);

    if (isN1Deeper) {
        for(int i = 0 ; i < sub ; i++){
            n1= parent[n1];
        }
    } else {
        for(int i = 0 ; i < sub ; i++){
            n2= parent[n2];
        }
    }
    int parentIdx = 0;
    while(n1 >= 1){
        if(parent[n1] == parent[n2]){
            parentIdx = parent[n1];
            break;
        }
        n1 = parent[n1];
        n2 = parent[n2];
    }
    return parentIdx;

}

int dfs(int idx, int depth) {

    if (idx == n1) { depthN1 = depth; }
    if (idx == n2) { depthN2 = depth; }

    if (adjList[idx].size() == 0) {
        subSize[idx] = 1;
        return 1;
    }
    int childSize = 0;

    while (!adjList[idx].empty()) {
        childSize += dfs(adjList[idx].front(), depth + 1);
        adjList[idx].pop_front();
    }
    subSize[idx] = childSize + 1;
    return childSize + 1;
}
