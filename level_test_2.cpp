#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
    int size = s.length();
    vector<char> str(size);
    for(int i = 0 ; i <size; i++){
        str[i] = s[i];
    }

    sort(str.begin(), str.end());
    reverse(str.begin(), str.end());

    string answer;
    for(int i = 0 ; i < size; i++){
        cout << str[i];
        answer.push_back(str[i]);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution("Zbcdefg");
    return 0;
}
