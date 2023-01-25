#include <iostream>
#include <list>

using namespace std;

int main() {

    freopen("num4.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input, x, y, s;
    string inst;

    for (int t = 1; t <= 10; t++) {
        list<int> l;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> input;
            l.push_back(input);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> inst;
            if (inst == "I") { // x의 위치 바로 다음에 y개의 숫자를 삽입
                cin >> x >> y;
                auto iter = l.begin();
                for (int j = 0; j < x; j++) { iter++; }
                for (int j = 0; j < y; j++) {
                    cin >> s;
                    iter = l.insert(iter, s);
                    iter++;
                }
            } else if (inst == "D") { // 앞에서부터 x의 위치 바로 다음부터 y개의 숫자를 삭제
                cin >> x >> y;
                auto iter = l.begin();
                for (int j = 0; j < x; j++) { iter++; }
                for (int j = 0; j < y; j++){
                    iter = l.erase(iter);
                }
            } else if (inst == "A") {
                cin >> y;
                for (int j = 0; j < y; j++) {
                    cin >> s;
                    l.push_back(s);
                }
            }
        }

        // 출력
        cout << "#" << t << " ";
        auto iter = l.begin();
        for(int i = 0 ; i < 10; i++){
            cout << *iter << " ";
            iter++;
        }
        cout << "\n";
    }

    return 0;
}
