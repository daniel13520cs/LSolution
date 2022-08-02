// Copyright 2022 <CHIHCHIEN>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            cout << "amount= " << i << "min from ";
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    cout << "dp["<< i-coins[j] <<"] =" << dp[i-coins[j]] << " ";
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
            cout << "\n";
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
    int main() {
        Solution s = Solution();
        vector<int> coins = {2,5,10,1}; // 1 2 5 10
        int amount = 27;
        s.coinChange(coins, amount);
        return 0;
    }
