#include <iostream>
#include <vector>

using namespace std;

struct Soldier {
    int num, team, score;
    Soldier(int id, int team, int score)
            : num(id), team(team), score(score) {};

};

vector<Soldier> v;

void init() {
    vector<Soldier>().swap(v);
}

void hire(int mID, int mTeam, int mScore) {
    v.emplace_back(mID, mTeam, mScore);
}

void fire(int mID) {
    for(int i = 0 ; i < v.size(); i++){
        if (v[i].num == mID){
            v.erase(v.begin() + i);
        }
    }
}

void updateSoldier(int mID, int mScore) {
    for(int i = 0 ; i < v.size(); i++){
        if (v[i].num == mID){
            v[i].score = mScore;
            break;
        }
    }
}

void updateTeam(int mTeam, int mChangeScore) {
    for(int i = 0 ; i < v.size(); i++){
        if (v[i].team == mTeam){
            int sum = v[i].score + mChangeScore;
            if (sum > 5)
                v[i].score = 5;
            else if (sum < 1)
                v[i].score = 1;
            else
                v[i].score += mChangeScore;
        }
    }
}

int bestSoldier(int mTeam) {
    int max = 0;
    int sNum = -1;
    for(int i =0; i < v.size(); i++){
        if (v[i].team == mTeam){
            if (v[i].score > max){
                max = v[i].score;
                sNum = v[i].num;
            } else if (v[i].score == max){
                if (v[i].num > sNum){
                    sNum = v[i].num;
                }
            }
        }
    }

    return sNum;
}
