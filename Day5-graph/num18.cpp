#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#include <iostream>
using namespace std;

static unsigned int seed = 12345;

static unsigned int pseudo_rand(int max) {
    seed = ((unsigned long long) seed * 1103515245 + 12345) & 0x7FFFFFFF;
    return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

extern void dfs_init(int N, int path[MAX_N][2]);

extern int dfs(int k);

static int p[MAX_K + 2];
static int c[MAX_K + 2];
static int path[MAX_N][2];

static void makeTree(int n) {
    for (int i = 1; i < MAX_K + 2; ++i) {
        p[i] = c[i] = -1;
    }
    c[pseudo_rand(MAX_K + 1) + 1] = 0;
    for (int i = 0; i < n; ++i) {
        int pi = pseudo_rand(MAX_K + 1) + 1;
        while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
            ++pi;
            if (pi == MAX_K + 2)
                pi = 1;
        }
        int ci = pseudo_rand(MAX_K + 1) + 1;
        while (c[ci] >= 0) {
            ++ci;
            if (ci == MAX_K + 2)
                ci = 1;
        }
        p[ci] = pi;
        ++c[pi];
        c[ci] = 0;
    }
    bool check[MAX_K + 2] = {false};
    for (int i = 0; i < n; ++i) {
        int e = pseudo_rand(MAX_K + 1) + 1;
        while (check[e] || c[e] < 0 || p[e] == -1) {
            ++e;
            if (e == MAX_K + 2)
                e = 1;
        }
        check[e] = true;
        path[i][0] = p[e];
        path[i][1] = e;
    }
}

int main() {
    setbuf(stdout, NULL);
    int T;
    freopen("num18.txt", "r", stdin);
    scanf("%d", &T);

    int totalScore = 0;
    for (int tc = 1; tc <= T; tc++) {
        int n, q;

        scanf("%d %d %d", &n, &q, &seed);

        makeTree(n - 1);
        dfs_init(n, path);

        bool check[MAX_K + 2] = {false};
        int score = 100;
        for (int i = 0; i < q; ++i) {
            int k, ret, correct;

            scanf("%d", &k);

            ret = dfs(k);

            scanf("%d", &correct);
            //cout << "king : " << k <<" /ret : " << ret << " /correct : " << correct << endl;

            if (ret != correct)
                score = 0;
        }
        printf("#%d : %d\n", tc, score);
        totalScore += score;
    }
    printf("#total score : %d\n", totalScore / T);

    return 0;
}

#include <iostream>
using namespace std;

int childList[100][5];
int childSize[100];
int top;

void dfs_init(int N, int path[100][2]) {

    // reset memory
    for (auto & i : childList) {
        for (int &j: i) { j = 0; }
    }
    for(int i = 0 ; i < 100; i++){
        childSize[i] = 0;
    }


    for (int i = 0; i < N-1; i++) {
        int parent = path[i][0];
        int child = path[i][1];
        int childN = childSize[parent];
        childList[parent][childN] = child;
        childSize[parent]++;
    }
}

int dfs(int n) {
    int stack[100];
    bool visited[101] = {false};
    top = -1;
    stack[++top] = n;
    while(top != -1){
        int curr = stack[top--];
        if (!visited[curr]){
            visited[curr] = true;
            if (curr > n) {
                return curr;
            }

            for (int next = childSize[curr] - 1; next >= 0; next--){
                int child = childList[curr][next];
                if(!visited[child]){
                    stack[++top] = child;
                }
            }
        }
    }
    return -1;
}
