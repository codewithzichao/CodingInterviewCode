/*
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/


#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:

	//动态规划，初级题。
	int FindGreatestSumOfSubArray(vector<int> array) {
		int cursum=array[0];
		int maxsum=array[0];
		
		for(int i=1;i<array.size();i++){
			cursum=max(array[i],cursum+array[i]);
			maxsum=max(maxsum,cursum);
		}

		return maxsum;
	}

	//动态规划，使用记忆化搜索。dp[i]表示前i个数组的最大子段和。
	int FindGreatestSumOfSubArray2(vector<int> array) {
		vector<int> dp(array.size()+1,0);
		dp[0]=0;
		dp[1]=array[0];
		for(int i=2;i<array.size();i++){
			dp[i]=max(dp[i-1]+array[i],array[i]);
		}

		return dp[array.size()];
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> array;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		array.push_back(x);
	}

	Solution so1;
	int ans=so1.FindGreatestSumOfSubArray(array);
	printf("%d\n",ans);
	return 0;
}