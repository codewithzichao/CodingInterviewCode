/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution{
	public:
	/*
	方法一：排序。这是最直观的思路。时间复杂度为:O(nlogn).不推荐，能这样做的话，还做个锤子的算法题！
	*/
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if(input.size()==0 || k==0 || k>input.size()){
			vector<int> ans;
			return ans;
		}

		vector<int> ans;
		sort(input.begin(),input.end());
		for(int i=0;i<k;i++){
			ans.push_back(input[i]);
		}

		return ans;
	}

	/*
	方法二：使用set或者multiset。在这道题里，需要使用multiset，因为有可能会有重复元素。
	时间复杂度：O(nlogk).
	*/
	vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
		if(input.size()==0 || k<=0 || k>input.size()){
			vector<int> ans;
			return ans;
		}

		multiset<int,greater<int> > s;//greater表示s中的元素是从大到小排序的，因为红黑树具有自动排序功能。
		for(int i=0;i<input.size();i++){
			if(s.size()<k){//首先插入k个元素
				s.insert(input[i]);
			}
			else{
				multiset<int,greater<int> >::iterator it=s.begin();//接下来，如果元素小于集合中最大的元素，那么删除最大的元素，插入该元素
				if(*it>input[i]){
					s.erase(it);
					s.insert(input[i]);
				}
			}
		}

		vector<int> ans(s.begin(),s.end());
		return ans;


	}
};

int main(){
	int n,k;
	scanf("%d%d ",&n,&k);
	vector<int> input;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		input.push_back(x);
	}

	Solution so1;
	vector<int> ans=so1.GetLeastNumbers_Solution2(input,k);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}