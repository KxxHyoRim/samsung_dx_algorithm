#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << pow(8, 10000);

    freopen("num3.txt", "r", stdin);

    int tc, result = 0;
    string represent;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> represent;
//        for(int i = 0; i < represent.length() - 1; i++){
//            char today = represent[i];
//            char tomm = represent[i+1];
//
//            if (today == tomm){
//                result *= 8;
//                result %= 1000000007;
//            } else {
//                // 다음날 대표가 나오는 경우
//                result
//            }
    }

    // 마지막날 아직 계산안함
    // # 형태로 출력



    return 0;
}
