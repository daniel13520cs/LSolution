// Copyright 2022 <CHIHCHIEN>
#include <vector>
using namespace std;
class Solution {
 private:    
    vector<int> coins;
    vector<vector<int>> res;
    vector<int> chosen;
 public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->coins = candidates;
        vector<int> chosen;
        backtracking(0, target);
        return res;
    }
        
    void backtracking(int start, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(chosen);
            return;
        }
        for (int i = start; i < coins.size(); ++i) {
            chosen.push_back(coins[i]);
            backtracking(i, target - coins[i]);
            chosen.pop_back();
        }
        int a=1;
    }
};