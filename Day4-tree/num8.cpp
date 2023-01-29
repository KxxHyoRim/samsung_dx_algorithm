#include <iostream>
#include<sstream>
#include <vector>

using namespace std;

int n;
string bt[100];

vector<string> split(string str, char delimiter);
void inorder(int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num8.txt", "r", stdin);


    int idx;
    string ch, line;

    for (int tc = 1; tc <= 10; tc++) {
        cout << "#" << tc << " ";

        cin >> n;
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            vector<string> result = split(line, ' ');
            idx = stoi(result[0]);
            bt[idx] = result[1];
        }
        inorder(1);
        cout << "\n";
    }
    return 0;
}
void inorder(int idx){
    int left = idx * 2;
    int right = idx * 2 + 1;
    if (left <= n)
        inorder(left);
    cout << bt[idx];
    if (right <= n)
        inorder(right);
}
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}
