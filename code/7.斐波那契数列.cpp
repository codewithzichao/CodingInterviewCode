/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//方法一：递归，最蠢的办法！面试这样写，必挂！时间复杂度：O(2^n)
	int Fibonacci1(int n) {
		if(n==0){
			return 0;
		}
		if(n==1){
			return 1;
		}

		int ans1=Fibonacci1(n-2);
        int ans2=Fibonacci1(n-1);
        int ans=ans1+ans2;
        return ans;
	}

	//循环。时间复杂度：O(n)
	int Fibonacci2(int n) {
		int result[2]={0,1};
		if(n<2){
			return result[n];
		}

		int fibOne=0;
		int fibTwo=1;
		int fibN=0;
		for(int i=2;i<=n;i++){
			fibN=fibOne+fibTwo;
			fibOne=fibTwo;
			fibTwo=fibN;
		}

		return fibN;
	}
	//还有时间复杂度为logn以及1的解法

};

int main(){
	int n;
	scanf("%d",&n);
	Solution so1;
	int ans=so1.Fibonacci2(n);
	printf("%d\n",ans);
	return 0;
}