#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num2.txt", "r", stdin);

    int tc, n, m;
    string result;

    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        int bn = 0b1 * (1 << n) - 1;
        int bm = 0b1 * m;
        int operateAnd = bn & bm;
        if (operateAnd == bn) result = "ON";
        else result = "OFF";
        cout << "#" << t << " " << result << "\n";
    }


    return 0;
}
