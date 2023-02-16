#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;


int N, M, s, e, c, parent[50000];

struct Edge {
    int u;
    int v;
    int cost;

    bool operator<(const Edge &d)
    const {
        return cost > d.cost;
    }
};

int findParent(int num) {
    if (num == parent[num])
        return num;
    return findParent(parent[num]);
}

void merge(int a, int b) {
    int p1 = findParent(a);
    int p2 = findParent(b);
    if (p1 < p2) parent[p2] = p1;
    else parent[p1] = p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num17.txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M;

        for (int i = 0; i < N; i++)
            parent[i] = i;

        priority_queue<Edge> pq;

        for (int i = 0; i < M; i++) {
            cin >> s >> e >> c;
            pq.push({s, e, c});
        }
        long long result = 0;

        while (!pq.empty()) {
            int u = pq.top().u;
            int v = pq.top().v;
            int cost = pq.top().cost;
            pq.pop();
            if (findParent(u) != findParent(v)) {
                merge(u, v);
                result += cost;
            }
        }

        cout << "#" << tc << " " << result << endl;
    }
    return 0;
}
