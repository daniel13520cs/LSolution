// Copyright 2022 <CHIHCHIEN>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
 private:    
    string cur;
    string res;
    vector<vector<string>> possibleStrings;
 public:
    // Example: {good, dog, doog, xyhhdgy} --> dogoodoog
    string longestLength(vector<string>& candidates){
        vector<string> chosen;
        backtracking(candidates, 0, ' ', chosen);
        for (auto v : possibleStrings) {
            for (auto str : v) {
                cout << str << " ";
            }
            cout << "\n";
        }
        return "";
    }
        
    void backtracking(vector<string>& candidates, int start, char validStart, vector<string>& chosen) {

        for (int i = start; i < candidates.size(); ++i) {
            if (validStart != ' ' && validStart != candidates[i][0]) {
                                    //cout << "valid:" << string(1, validStart) << " ";
                continue;
            }
            swap(candidates[i], candidates[start]);
            chosen.push_back(candidates[start]);
            possibleStrings.push_back(chosen);
            //cout << "back=" << candidates[start].back() << " ";
            backtracking(candidates, start + 1, candidates[start].back(), chosen);
            swap(candidates[i], candidates[start]);
            chosen.pop_back();
        }
    }
};

int main() {
    Solution s = Solution();
    vector<string> candidates = {"good", "dog", "doog", "xyhhdgy"};
    vector<string> candidates2 = {"ab", "b", "bc", "cg"};
    cout << s.longestLength(candidates);
    return 0;
}
