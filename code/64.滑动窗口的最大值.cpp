/*
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， 
{2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

class Solution{
	public:

	/*
	
	滑动窗口应当是队列，但为了得到滑动窗口的最大值，队列需要可以从两端删除元素，因此使用双端队列。
      原则：
      对新来的元素k，将其与双端队列中的元素相比较
      1）前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,
      2）前面比k大的X，比较两者下标，判断X是否已不在窗口之内，不在了，直接移出队列
      队列的第一个元素是滑动窗口中的最大值
	*/
	vector<int> maxInWindows(const vector<int>& num, unsigned int size){
		if(num.size()==0 || size<=0){//边界条件
			vector<int> vec;
			return vec;
		}

		vector<int> vec;//存放每一个滑动窗口的最大值
		deque<int> dq;//双端队列，表示华东窗口，存放可能是最大值的值的下标

		for(int i=0;i<num.size();i++){//遍历每一个元素
			while(dq.size() && num[dq.back()]<=num[i]){//当队列最后一个元素小于当前元素的时候，弹出
				dq.pop_back();
			}
			if(dq.size() && i-dq.front()+1>size){
				dq.pop_front();
			}
			dq.push_back(i);

			if(i+1>=size){
				vec.push_back(num[dq.front()]);
			}
		}

		return vec;
	}
};

int main(){
	int n,size;
	scanf("%d%d",&n,&size);
	vector<int> num;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num.push_back(x);
	}

	Solution so1;
	vector<int> ans=so1.maxInWindows(num,size);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);

	}

	printf("\n");
	return 0;
}