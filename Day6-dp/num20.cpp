#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1001;
int dp[MAX][MAX];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num20.txt", "r", stdin);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string s1, s2;
        cin >> s1 >> s2;

        int len1 = s1.length();
        int len2 = s2.length();

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout << "#" << t << " " << dp[len1][len2] << endl;
    }

    return 0;
}
