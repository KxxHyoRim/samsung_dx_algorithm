#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int V[101];
int C[101];
int dp[101][1001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num21.txt", "r", stdin);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        memset(dp, 0, sizeof(dp)); // DP 배열 초기화

        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            cin >> V[i] >> C[i];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                if (j >= V[i]) {
                    dp[i][j] = max(dp[i-1][j-V[i]] + C[i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout << "#" << t << " " << dp[N][K] << endl;
    }

    return 0;
}
