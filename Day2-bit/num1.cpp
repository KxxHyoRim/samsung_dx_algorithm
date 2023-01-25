/* bit연산
 * num1. 새로운 불면증 치료법
 * */

#include <iostream>

using namespace std;

int main() {
    freopen("num1.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n;
        int bit = 0b0;
        int mul = 1;
        int kN;
        while (bit < 0b1111111111) {
            kN = 0b1 * n * mul++;
            while(kN != 0){
                int num = kN%10;
                kN /= 10;
                bit |= (1<<num);
            }
        }
        cout << "#" << t << " " << 0b1 * n * (mul-1) << "\n";
    }

    return 0;
}
