#include <iostream>
#include<sstream>
#include <vector>

using namespace std;

struct Node {
    int idx;
    string data;
    int left, right;
};

Node nodeList[1001];

int inorder(int idx);

bool isOperator(const string &s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("num10.txt", "r", stdin);

    int n, idx, left, right;
    string ch, line;

    for (int tc = 1; tc <= 10; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> idx >> ch;
            if (isOperator(ch)) {
                cin >> left >> right;
            } else {
                left = -1;
                right = -1;
            }
            nodeList[idx] = Node{idx, ch, left, right};
        }
        cout << "#" << tc << " " << inorder(1) << "\n";
    }
    return 0;
}

int inorder(int idx) {
    Node node = nodeList[idx];
    if (isOperator(node.data)) {
        string op = node.data;
        int left = node.left;
        int right = node.right;
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
    return stoi(node.data);
}

bool isOperator(const string &s) {
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return true;
    return false;
}