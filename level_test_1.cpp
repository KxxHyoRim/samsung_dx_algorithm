#include <iostream>
#include <vector>
#include <set>

using namespace std;


int solution(vector<int> nums){
    int totalN= nums.size();
    int chooseN = totalN/2;

    vector<bool> tmp(nums.size(), true);
    for(int i = 0 ; i < chooseN; i++){
        tmp[i] = false;
    }

    set<int> pokemon;
    int answer = 0;

    do {
        for(int i = 0 ; i < totalN; i++ ){
            if (tmp[i])
                pokemon.emplace(nums[i]);
        }
        if (pokemon.size() > answer)
            answer = (int) pokemon.size();
        pokemon.clear();
    }while(next_permutation(tmp.begin(), tmp.end()));

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> num1 = {3,1,2,3};
    vector<int> num2 = {3,3,3,2,2,4};
    vector<int> num3 = {3,3,3,2,2,2,};

    cout << solution(num3);

    return 0;
}
