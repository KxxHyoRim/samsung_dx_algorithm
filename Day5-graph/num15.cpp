#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

list<int> ll[100000];
list<int> visited;
int depth[100000];
int parent[100000];

void bfs();

int realBFS();

int sp(int from, int to);

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num15.txt", "r", stdin);

    int TC, n, parentIdx;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        ll->clear();
        visited.clear();

        depth[1] = 0;
        cin >> n;
        for (int i = 2; i < n + 1; i++) {
            cin >> parentIdx;
            parent[i] = parentIdx;
            depth[i] = depth[parentIdx] + 1;
            ll[parentIdx].push_back(i);
        }

        bfs(); // 방문순서
        // 최단경로 찾기 (LCA활용하기)

        cout << "#" << tc << " " << realBFS() << "\n";
    }
    return 0;
}

void bfs() {
    int n = 1;
    queue<int> q;
    q.emplace(n);
    visited.push_back(n);
    int tempDepth = 0;
    while (!q.empty()) {
        n = q.front();
        q.pop();
        tempDepth++;
        while (!ll[n].empty()) {
            int child = ll[n].front();
            ll[n].pop_front();
            q.emplace(child);
            visited.push_back(child);
        }
    }
}

int realBFS() {
    int move = 0;

    int from = visited.front();
    visited.pop_front();

    while (!visited.empty()) {
        int to = visited.front();
        visited.pop_front();
        move += sp(from, to);
        from = to;
    }

    return move;
}

int sp(int from, int to) {
    // cout << "from/to : " << from << ", " << to << " ";
    int count = 1;
    int depthFrom = depth[from];
    int depthTo = depth[to];
    bool isFromDeeper = depthFrom > depthTo;
    int sub = abs(depthFrom - depthTo);
    for (int i = 0; i < sub; i++) {
        if (isFromDeeper) from = parent[from];
        else to = parent[to];
    }

    if (from == to) {
        return sub;
    }

    while (from > 1) {
        if (parent[from] == parent[to]) {
            break;
        }
        from = parent[from];
        to = parent[to];
        count++;
    }

    // cout << count * 2 + sub;
    return count * 2 + sub;
}