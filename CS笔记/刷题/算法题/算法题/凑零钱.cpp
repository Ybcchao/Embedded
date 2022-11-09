#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> memo(amount + 1, 0); //��amount+1��0������memo.
		return dp(memo, amount, coins);
	}
private:
	int dp(vector<int>& memo, int amount, vector<int>& coins) {
		if (amount == 0) return 0;
		if (amount < 0) return -1;
		if (memo[amount] != 0) return memo[amount]; //�鱸��¼����ֹ�ظ����㡣
		int res = amount + 1;
		for (auto coin : coins) {
			if (amount - coin < 0) continue;
			int subproblem = dp(memo, amount - coin, coins);//����������Ľ��
			if (subproblem == -1) continue; //�������޽�������
			res = min(res, 1 + subproblem); //����������ѡ�����Ž⣬Ȼ���һ��

		}
		memo[amount] = res == (amount + 1) ? -1 : res; //�Ѽ��������뱸��¼��
		return memo[amount];
	}
};

