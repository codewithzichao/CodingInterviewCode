/*
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）

输出描述:
输出答案。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	/*
	https://www.nowcoder.com/profile/868514962/codeBookDetail?submissionId=61612794
	*/
	int cutRope(int number) {
		if(number<=1) return 0;
		if(number==2) return 1;
		if(number==3) return 2;
		
		vector<int> vec={0,1,2,3};
		/*
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		*/

		for(int i=4;i<=number;i++){
			int j=i/2;
			vec.push_back(vec[j]*vec[i-j]);
		}

		return vec[number];
	}
};

int main(){
	int number;
	scanf("%d",&number);
	Solution so1;
	int ans=so1.cutRope(number);
	printf("%d\n",ans);
	return 0;
}