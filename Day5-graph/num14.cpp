#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

#define check (-1)

using namespace std;

int map[300][300];
queue<pair<int, int>> q;
int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[8] = {1, -1, 0, 0, -1, -1, 1, 1};

int N;
int click;
int notVisit;

void printMap(){

    for(int y = 0 ; y < N; y++){
        for(int x = 0 ; x < N; x++){
            if (map[y][x] == INT_MAX)
                cout << "* ";
            else cout << map[y][x] << " " ;
        }
        cout << endl;
    }
}

bool isInMap(int x, int y);
bool getMineNum(int x, int y);
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
                if (oneLine[x] == '*') {
                    map[y][x] = INT_MAX;
                } else { // '.'인 경우
                    notVisit += 1;
                }
            }
        }

        // 근처 지뢰수 초기화
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (map[y][x] == INT_MAX) continue;
                map[y][x] = getMineNum(x, y);
            }
        }

//        printMap();

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (map[y][x] == 0) {
                    bfs(x, y);
                    click++;
                }
            }
        }

//        printMap();

        cout << "#" << tc << " " << click + notVisit << "\n";
    }
    return 0;
}


void bfs(int x, int y) {
    q.emplace(x, y);
    notVisit--;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        map[y][x] = -1;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isInMap(nx, ny)) {
                if (map[ny][nx] == 0) {
                    q.emplace(ny, nx);
                    notVisit--;
                } else if (map[ny][nx] != check && map[ny][nx] != INT_MAX) { // 아직 방문 전이라면
                    notVisit--;
                }
                map[ny][nx] = check;
            }
        }
    }
}


void init() {
    for (auto &i: map)
        memset(i, 0, sizeof(int) * 300);
    notVisit = 0;
    click = 0;
}


bool getMineNum(int x, int y) {
    int mine = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isInMap(nx, ny)) continue;
        if (map[ny][nx] == INT_MAX) mine++;
    }
    return mine;
}



bool isInMap(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}