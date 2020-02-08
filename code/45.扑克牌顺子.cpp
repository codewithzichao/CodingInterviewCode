/*
题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。
为了方便起见,你可以认为大小王是0。
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
	思路：具体步骤如下：
	1.排序。这里使用快速排序，因为n最大就是取54，所以O(n)与O(nlogn)区别不大。
	2.统计数组中0的个数
	3.统计空格数
	4.如果0的个数>=空格数，那么返回true；否则，返回false
	Attention：如果存在对子，也就是有两个数字相等，那么就不可能构成顺子，直接返回false
	over～
	*/
	bool IsContinuous( vector<int> numbers ) {
		if(numbers.size()==0) return false;

		sort(numbers.begin(),numbers.end());

		int numberOfZero=0;
		int numberOfGap=0;

		for(int i=0;i<numbers.size() && numbers[i]==0;i++){
			numberOfZero++;
		}

		int low=numberOfZero;
		int high=low+1;

		while(high<numbers.size()){
			if(numbers[low]==numbers[high]) return false;
			numberOfGap+=numbers[high]-numbers[low]-1;
			low=high;
			high++;
		}

		return numberOfZero>=numberOfGap?true:false;
    }
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> numbers;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		numbers.push_back(x);
	}

	Solution so1;
	bool ans=so1.IsContinuous(numbers);
	if(ans) printf("true\n");
	else printf("false\n");
	return 0;
}