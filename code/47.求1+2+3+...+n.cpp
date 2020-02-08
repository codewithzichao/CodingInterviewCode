/*
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//思路：使用逻辑与。逻辑与操作，如果前半部分为假，那么后半部分不会执行。
	//over～
	int Sum_Solution(int n) {//不用加减乘除做加法
		int ans=n;
		ans&&(ans+=Sum_Solution(n-1));
		return ans;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	Solution so1;
	int ans=so1.Sum_Solution(n);
	printf("%d\n",ans);
	return 0;
}