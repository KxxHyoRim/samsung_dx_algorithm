#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int n;
bool isPossible = true;
string bt[100];

vector<string> split(string str, char delimiter);

void inorder(int idx);

bool isOperator(string s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("num9.txt", "r", stdin);
    string line;
    int idx;

    for (int tc = 1; tc <= 10; tc++) {
        cout << "#" << tc << " ";
        isPossible = true;
        cin >> n;
        getline(cin, line); // "\n" 제거용
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            vector<string> result = split(line, ' ');
            idx = stoi(result[0]);
            bt[idx] = result[1];
        }
        inorder(1);
        if (isPossible) cout << "1\n";
        else cout << "0\n";
    }


    return 0;
}

void inorder(int idx) {
    int left = idx * 2;
    int right = idx * 2 + 1;

    // isLeaf -> must be digit
    if (left > n && isOperator(bt[idx])) {
        isPossible = false;
    }

    if (left <= n)
        inorder(left);

    if (right <= n)
        inorder(right);
}

bool isOperator(string s) {
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return true;
    return false;
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
