#include <iostream>
#include <list>

using namespace std;

int main() {

    freopen("num5.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, L, input, idx, num;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        string inst;
        list<int> list;
        auto iter = list.begin();

        cin >> N >> M >> L;

        for (int i = 0; i < N; i++) {
            cin >> input;
            list.push_back(input);
        }

        for (int i = 0; i < M; i++) {
            cin >> inst;
            if (inst == "I") {
                cin >> idx >> num;
                iter = list.begin();
                for(int j = 0 ; j < idx; j++) iter++;
                list.insert(iter, num);
            } else if (inst == "D") {
                cin >> idx;
                iter = list.begin();
                for(int j = 0 ; j < idx; j++) iter++;
                list.erase(iter);
            } else if (inst == "C") {
                cin >> idx >> num;
                iter = list.begin();
                for(int j = 0 ; j < idx; j++) iter++;
                iter = list.erase(iter);
                list.insert(iter, num);
            }
        }

        cout << "#" << t << " ";

        if (list.size() <= L){
            cout << "-1\n";
        }else {
            iter = list.begin();
            for(int j = 0 ; j < L; j++) iter++;
            cout << *iter << "\n";
        }
    }

    return 0;
}
