#include <iostream>
#include <cstring>
#include <queue>

#define MINE 99999
#define check (-1)

using namespace std;

int map[300][300];
queue<pair<int, int>> q;
int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[8] = {1, -1, 0, 0, -1, -1, 1, 1};

int N;
int click;
int notVisit;

bool isInMap(int x, int y);

int getMineNum(int x, int y);

void bfs(int x, int y);

void init();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num14.txt", "r", stdin);

    int T;
    string oneLine;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        cin >> N;
        for (int y = 0; y < N; y++) {
            cin >> oneLine;
            for (int x = 0; x < N; x++) {
                if (oneLine[x] == '*') { map[y][x] = MINE; }
                else { notVisit += 1; }
            }
        }

        // 근처 지뢰수 초기화
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (map[y][x] == MINE) continue;
                map[y][x] = getMineNum(x, y);
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (map[y][x] == 0) {
                    bfs(x, y);
                    click++;
                }
            }
        }

        cout << "#" << tc << " " << click + notVisit << "\n";
    }
    return 0;
}


void bfs(int x, int y) {
    q.emplace(x, y);
    map[y][x] = -1;
    notVisit--;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isInMap(nx, ny)) continue;
            if (map[ny][nx] == 0) {
                q.emplace(nx, ny);
                map[ny][nx] = -1;
                notVisit--;
            } else if (map[ny][nx] != check && map[ny][nx] != MINE) {
                // 방문하지 않았음, but 근처에 상수가 있는 위치
                notVisit--;
            }
            map[ny][nx] = check;
        }
    }
}


void init() {
    for (auto &i: map)
        memset(i, 0, sizeof(int) * 300);
    notVisit = 0;
    click = 0;
}


int getMineNum(int x, int y) {
    int mine = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isInMap(nx, ny)) continue;
        if (map[ny][nx] == MINE) mine++;
    }
    return mine;
}


bool isInMap(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}