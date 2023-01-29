#include <iostream>
#include<sstream>
#include <vector>

using namespace std;

int n;
string bt[1001];

vector<string> split(string str, char delimiter);
int inorder(int idx);
bool isOperator(const string& s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num10.txt", "r", stdin);

    int idx;
    string ch, line;

    for (int tc = 1; tc <= 10; tc++) {
        bt->clear();
        cin >> n;
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            vector<string> result = split(line, ' ');
            idx = stoi(result[0]);
            bt[idx] = result[1];
            cout << idx << " : " << bt[idx] << endl;
        }
         cout << "#" << tc << " " << inorder(1) << "\n";
    }
    return 0;
}

int inorder(int idx) {
    if (isOperator(bt[idx])) {
        string op = bt[idx];
        int left = idx * 2;
        int right = idx * 2 + 1;
        // cout << "op : " << op << endl;
        int lv = inorder(left);
        int rv = inorder(right);
        if (op == "+")
            return lv + rv;
        if (op == "-")
            return lv - rv;
        if (op == "/")
            return lv / rv;
        if (op == "*")
            return lv * rv;
    }

    if (bt[idx] == ""){
        cout << "Exception : " <<  idx << endl;
        return 0;
    }

    // cout <<"-" << bt[idx]  << "-"<< endl;
    return stoi(bt[idx]);
}

bool isOperator(const string& s) {
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
