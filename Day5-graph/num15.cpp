#include <iostream>
#include <list>
#include <queue>

#define ll long long

using namespace std;

int TC, N, parentIdx;
list<int> pList[100000];
list<int> visited;
int depth[100000];
int parent[100000][21];

ll bfs();

int LCA(int from, int to);

void dfs(int, int);

void setParent();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num15.txt", "r", stdin);

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        pList->clear();
        visited.clear();
        fill(depth, depth + N, 0);
        memset(parent, 0, sizeof(parent));

        depth[1] = 0;
        cin >> N;
        for (int i = 2; i < N + 1; i++) {
            cin >> parentIdx;
            parent[i][0] = parentIdx;
            depth[i] = depth[parentIdx] + 1;
            pList[parentIdx].push_back(i);
        }

        setParent();
        cout << "#" << tc << " " << bfs() << "\n";
    }
    return 0;
}

ll bfs() {
    long long move = 0;
    int n = 1;
    int from = n;
    queue<int> q;
    q.emplace(n);
    visited.push_back(n);
    int tempDepth = 0;
    while (!q.empty()) {
        n = q.front();
        int to = n;
        int lca = LCA(from, to);
        move += depth[from] + depth[to] - 2 * depth[lca];
        q.pop();
        tempDepth++;
        while (!pList[n].empty()) {
            int child = pList[n].front();
            pList[n].pop_front();
            q.emplace(child);
            visited.push_back(child);
        }
        from = to;
    }
    return move;
}

void setParent() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < N; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int LCA(int from, int to) {
    if (depth[from] < depth[to])
        swap(from, to);

    for (int i = 19; i >= 0; i--) {
        if ((depth[from] - depth[to]) >= (1 << i))
            from = parent[from][i];
    }

    if (from == to)
        return from;

    for (int i = 0; i <= 19; i++) {
        if (parent[from][i] != parent[to][i]) {
            from = parent[from][i];
            to = parent[to][i];
        }
    }
    return parent[from][0];
}