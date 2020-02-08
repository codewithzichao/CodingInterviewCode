/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//还是动态规划。
	int jumpFloorII1(int number) {
		vector<int> dp(number+1,1);//注意，初始值为1！也就是代表可以直接跳到n阶台阶的那种方法。
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=number;i++){
			for(int j=0;j<i;j++){
				dp[i]+=dp[j];
			}
		}

		return dp[number];
	}

	//还有更快的，找规律！
	int jumpFloorII2(int number) {
		if(number==0){
			return 0;
		}

		int a=1;
		return a<<(number-1);
	}
};

int main(){
	int number;
	scanf("%d",&number);
	Solution so1;
	int ans=so1.jumpFloorII2(number);
	printf("%d\n",ans);
	return 0;
}