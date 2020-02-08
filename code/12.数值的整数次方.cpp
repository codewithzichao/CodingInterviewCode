/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//这道题看似简单，但是要考虑的情况有很多。
	/*
	当分母为0的时候，如果分子>=0，那么结果为0；如果分子为负数，那么要抛出异常；
	之后，要考虑分子是正数还是负数，来进行计算。
	*/
	double Power1(double base, int exponent) {
		if(base==0.0){
			if(exponent>=0){
				return 0.0;
			}
			else{
				throw "计算出错！";
			}
		}
		else{
			double ans=1.0;
			for(int i=0;i<abs(exponent);i++){
				ans*=base;
			}
			return exponent<0?1.0/ans:ans;
		}
	}

	//这一种无法AC？

	double Power2(double base, int exponent) {
		if(base==0.0){
			if(exponent>=0){
				return 0.0;
			}
			else{
				throw "计算出错！";
			}
		}
		else{
			if(exponent==0){
				return 1.0;
			}
			if(exponent==1){
				return base;
			}

			double ans=Power2(base,exponent>>1);
			ans*=ans;
			if((exponent & 0x1) == 1){
				ans*=base;
			}
			return ans;
		}
	}
};

int main(){
	double base;
	int exponent;
	scanf("%lf%d",&base,&exponent);
	Solution so1;
	double ans=so1.Power2(base,exponent);
	printf("%lf\n",ans);
	return 0;
}

