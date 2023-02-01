#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int TC, n, core, wire;
int map[12][12];
vector<pair<int, int>> v;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void resetGlobalVar() {
    core = 0;
    wire = INT_MAX;
    v.clear();
}

bool isEdge(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == n - 1;
}

void dfs(int idx, int connectN, int wireLen) {

    // 지금 방문하는 core의 전선 깔기
    for (int i = 0; i < 4; i++) {
        int x = v[idx].first;
        int y = v[idx].second;
        int temp_wire = 0;

        bool canConnect = true;
        while (!isEdge(x, y)) {
            x += dx[i];
            y += dy[i];
            if (map[y][x] != 0) {    // 전선 깔수있 상태
                canConnect = false;
                break;
            }
        }

        if (canConnect) {
            x = v[idx].first;
            y = v[idx].second;
            while (!isEdge(x, y)) {
                x += dx[i];
                y += dy[i];
                map[y][x] = 2;
                temp_wire++;
            }
        }

        int currCore = (canConnect) ? connectN + 1 : connectN;
        int currWire = wireLen + temp_wire;

        if (idx < v.size() - 1) {
            dfs(idx + 1, currCore, currWire);
        } else {    // 마지막 노드
            // cout << core << " " << wire << endl;
            if (currCore > core) {
                core = currCore;
                wire = currWire;
            } else if (currCore == core) {
                wire = min(wire, currWire);
            }
        }
        // reset
        if (canConnect) {
            x = v[idx].first;
            y = v[idx].second;
            while (!isEdge(x, y)) {
                x += dx[i];
                y += dy[i];
                map[y][x] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num13.txt", "r", stdin);


    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        cin >> n;
        resetGlobalVar();

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cin >> map[y][x];
                if (map[y][x] == 1 && !isEdge(x, y)) {
                    v.emplace_back(x, y);
                }
            }
        }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << wire << "\n";
    }
    return 0;
}
