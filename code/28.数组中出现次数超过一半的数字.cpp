/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
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
	方法一：使用排序。时间复杂度为:O(nlogn).不推荐，面试这样写，必挂！
	*/
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if(numbers.size()==0){
			return 0;
		}

		sort(numbers.begin(),numbers.end());
		int temp=numbers[numbers.size()/2];
		int count=0;
		for(int i=0;i<numbers.size();i++){
			if(numbers[i]==temp){
				count++;
			}
		}

		return count>numbers.size()/2?temp:0;
	}

	/*
	思路：要求出现次数超过数组长度一半的元素，也就是说该元素的次数比其他剩余的元素出现的次数都要多。那么，
	我们可以在遍历数组的时候，保存两个值：一个是数组中的数字，一个是次数。如果该元素与下一个遍历的元素相同，那么次数+1；否则的话，次数-1。
	当次数减为0的时候，就保存下一个数字，并将次数置为1.
	最后判断该元素出现的次数是否满足条件，满足则返回该元素；不满足返回0.
	时间复杂度：O(n).
	over～
	*/
	int MoreThanHalfNum_Solution2(vector<int> numbers) {
		if(numbers.size()==0){
			return 0;
		}

		int times=1;
		int result=numbers[0];
		for(int i=1;i<numbers.size();i++){
			if(times==0){//当数组元素的次数减为0的时候，保存下一个元素，并把次数置为1
				result=numbers[i];
				times=1;
			}
			else if(numbers[i]==result){//如果相等，次数+1
				times++;
			}
			else{//如果不相等，次数-1
				times--;
			}
		}

		times=0;
		for(int i=0;i<numbers.size();i++){//判断当前元素出现的次数是否大于数组长度的一半
			if(numbers[i]==result){
				times++;
			}
		}

		return times>numbers.size()/2?result:0;
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
	int ans=so1.MoreThanHalfNum_Solution2(numbers);
	printf("%d\n",ans);
	return 0;
}