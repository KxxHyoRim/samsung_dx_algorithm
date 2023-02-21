#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

int N, x[1000], y[1000], parent[1000];
double e;

struct Edge {
    int u;
    int v;
    double cost;

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

double getDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(abs(x1 - x2), 2)
                + pow(abs(y1 - y2), 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num16.txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N;

        for (int i = 0; i < N; i++)
            parent[i] = i;

        for (int i = 0; i < N; i++)
            cin >> x[i];

        for (int i = 0; i < N; i++)
            cin >> y[i];

        cin >> e;

        priority_queue<Edge> pq;

        for (int u = 0; u < N; u++) {
            for (int v = u + 1; v < N; v++) {
                double cost = getDistance(x[u], y[u], x[v], y[v]);
                pq.push({u, v, cost});
            }
        }

        double result = 0;

        while (!pq.empty()) {
            int u = pq.top().u;
            int v = pq.top().v;
            double cost = pq.top().cost;
            pq.pop();
            if (findParent(u) != findParent(v)) {
                merge(u, v);
                result += (cost * cost);
            }
        }

        cout << "#" << tc << " " << (long long) round(result * e) << endl;
    }
    return 0;
}