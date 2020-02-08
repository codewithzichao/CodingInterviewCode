/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//动态规划
	int jumpFloor1(int number) {
		vector<int> dp(number+1,0);
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=number;i++){
			dp[i]=dp[i-1]+dp[i-2];
		}

		return dp[number];
	}
};

int main(){
	int number;
	scanf("%d",&number);
	Solution so1;
	int ans=so1.jumpFloor(number);
	printf("%d\n",ans);
	return 0;
}