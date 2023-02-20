#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
using namespace std;

extern void bfs_init(int N, int map[10][10]);

extern int bfs(int x1, int y1, int x2, int y2);

static int test_bfs() {
    int N;
    int map[10][10];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    bfs_init(N, map);
    int M;
    int score = 100;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = bfs(x1, y1, x2, y2);
        int dist;
        scanf("%d", &dist);
        cout << result << " /" << dist << endl;
        if (result != dist) score = 0;
    }
    return score;
}

int main() {
    setbuf(stdout, NULL);
    freopen("num19.txt", "r", stdin);
    printf("#total score : %d\n", test_bfs());

    return 0;
}

#include <queue>

int m[10][10]; // (0,0)이 기준
bool visited[10][10]; // (0,0)이 기준
int len[10][10]; // (0,0)이 기준
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;

void bfs_init(int map_size, int map[10][10]) {
    n = map_size;

    for (int y = 0; y < map_size; y++) {
        for (int x = 0; x < map_size; x++) {
            m[y][x] = map[y][x];
        }
    }
}

bool isInMap(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}


int bfs(int x1, int y1, int x2, int y2) {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            visited[y][x] = false;
            len[y][x] = 0;
        }
    }


    int fx = x1 - 1;
    int fy = y1 - 1;
    int tx = x2 - 1;
    int ty = y2 - 1;

    queue<pair<int, int>> q;
    q.emplace(fx, fy);
    visited[fy][fx] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == tx && y == ty){
            break;
        }

        for(int i = 0 ; i< 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!visited[ny][nx] && isInMap(nx, ny) && m[ny][nx] == 0) {
                q.emplace(nx,ny);
                len[ny][nx] = len[y][x] + 1;
                visited[ny][nx] = true;
            }
        }
    }
    return (len[ty][tx] == 0)? -1 : len[ty][tx];
}