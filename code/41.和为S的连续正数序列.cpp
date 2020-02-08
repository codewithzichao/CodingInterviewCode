/*
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//双指针的思路。之前没有练过，赶紧在leetcode上刷双指针！
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > ans;//最后的返回值
		int low=1,high=2;//定义两个指针

		while(low<high){//循环条件，当low=high的时候，结束循环
			int cursum=(high-low+1)*(low+high)/2;//计算当前序列的和
			if(cursum<sum){//如果小于目标值，那么high指针+1
				high++;
			}
			else if(cursum>sum){//如果大于目标值，low+1
				low++;
			}
			else{//如果等于目标值，那么就把[low,high]之间的数存入ans中
				vector<int> temp;
				for(int i=low;i<=high;i++){
					temp.push_back(i);
				}
				ans.push_back(temp);
				low++;
			}
		}

		return ans;//返回
	}
};

int main(){
	int sum;
	scanf("%d",&sum);
	Solution so1;
	vector<vector<int> > ans=so1.FindContinuousSequence(sum);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}