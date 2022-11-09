#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>coins, int amount) {
	// �����СΪ amount + 1����ʼֵҲΪ amount + 1
	vector<int> dp(amount + 1, amount + 1);
	// base case
	dp[0] = 0;
	// ��� for ѭ���ڱ�������״̬������ȡֵ
	for (int i = 0; i < dp.size(); i++) {
		// �ڲ� for ѭ����������ѡ�����Сֵ
		for (int coin : coins) {
			// �������޽⣬����
			if (i - coin < 0) {
				continue;
			}
			dp[i] = min(dp[i], 1 + dp[i - coin]);
		}
	}
	return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

