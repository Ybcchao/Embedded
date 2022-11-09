#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> memo(amount + 1, 0); //将amount+1个0拷贝给memo.
		return dp(memo, amount, coins);
	}
private:
	int dp(vector<int>& memo, int amount, vector<int>& coins) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;
		if (memo[amount] != 0) return memo[amount]; //查备忘录，防止重复计算。
		int res = amount + 1;
		for (auto coin : coins) {
			if (amount - coin < 0) continue;
			int subproblem = dp(memo, amount - coin, coins);//计算子问题的结果
			if (subproblem == -1) continue; //子问题无解则跳过
			res = min(res, 1 + subproblem); //在子问题中选择最优解，然后加一。

		}
		memo[amount] = res == (amount + 1) ? -1 : res; //把计算结果存入备忘录中
		return memo[amount];
	}
};

