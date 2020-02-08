/*
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

class Solution{
	public:
	//方法一：首先计算每一个数字中的1的个数，然后加总求和。
	int NumberOf1Between1AndN_Solution(int n){
		
		int count=0;
		for(int i=1;i<=n;i++){
			count+=numberOf1(i);
		}
		
		return count;
	}

	int numberOf1(int number){
		int count=0;
		while(number!=0){
			if(number%10==1){
				count++;
			}
			number/=10;
		}
		return count;
	}

	//方法二：归纳。https://www.nowcoder.com/profile/3371548/codeBookDetail?submissionId=16319486
	int NumberOf1Between1AndN_Solution2(int n){
		
		int count=0;
		for(int i=1;i<=n;i*=10){
			int divider=i*10;
			int temp=n%divider-i+1;
			count+=(n/divider)*i+min(max(temp,0),i);
		}
		
		return count;
		

	}
};

int main(){
	int n;
	scanf("%d",&n);
	Solution so1;
	int ans=so1.NumberOf1Between1AndN_Solution2(n);
	printf("%d\n",ans);
	return 0;
}