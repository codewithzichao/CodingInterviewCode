/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//思路：双指针。需要注意的是，最后要求的是乘积最小的两个数，由于数组是有序的，所以使用双指针，得到的第一个和等于目标值的两个数就是乘积最小的！
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		if(array.size()==0){
			vector<int> ans;
			return ans;
		}

		vector<int> ans;
		int low=0;
		int high=array.size()-1;

		while(low<high){
			int cursum=array[low]+array[high];
			if(cursum<sum){
				low++;
			}
			else if(cursum>sum){
				high--;
			}
			else{
				ans.push_back(array[low]);
				ans.push_back(array[high]);
				return ans;
			}
		}

		return ans;
	}
};

int main(){
	int n,sum;
	scanf("%d%d",&n,&sum);
	vector<int> array;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		array.push_back(x);
	}

	Solution so1;
	vector<int> ans=so1.FindNumbersWithSum(array,sum);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
