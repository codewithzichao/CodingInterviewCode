/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//方法一：暴力。不能AC，时间复杂度过大。
	int GetUglyNumber_Solution(int index) {
		if(index<=0){
			return 0;
		}

		int curCount=0;
		int number=0;
		while(curCount<index){
			number++;
			if(isUgly(number)){
				curCount++;
			}
			
		}

		return number;
	}

	bool isUgly(int number){
		if(number<=0){
			return false;
		}

		while(number%2==0){
			number/=2;
		}
		while(number%3==0){
			number/=3;
		}
		while(number%5==0){
			number/=5;
		}

		return number==1?true:false;

	}

	//方法二：从丑数的定义可知，所有的丑数都可从2、3、5得到。维护3个队列，设置三个指针，记录每一个队列到哪一步了。
	//参考链接：https://www.nowcoder.com/profile/5810633/codeBookDetail?submissionId=16629921
	int GetUglyNumber_Solution2(int index) {
		if(index<7){
			return index;
		}

		vector<int> arr;
		int p2=0,p3=0,p5=0;
		int newNum=1;
		arr.push_back(newNum);
		while(arr.size()<index){
			newNum=min(min(arr[p2]*2,arr[p3]*3),arr[p5]*5);
			if(arr[p2]*2==newNum) p2++;
			if(arr[p3]*3==newNum) p3++;
			if(arr[p5]*5==newNum) p5++;
			arr.push_back(newNum);
		}

		return newNum;
	}
};

int main(){
	int index;
	scanf("%d",&index);
	Solution so1;
	int ans=so1.GetUglyNumber_Solution2(index);
	printf("%d\n",ans);
	return 0;
}