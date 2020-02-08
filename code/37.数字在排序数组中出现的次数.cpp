/*
题目描述
统计一个数字在排序数组中出现的次数。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//方法一：暴力解。时间复杂度为：O(n).
	int GetNumberOfK(vector<int> data ,int k) {
		int number=0;
		for(int i=0;i<data.size();i++){
			if(data[i]==k){
				number++;
			}
		}

		return number;
	}

	//方法二：二分查找，时间复杂度为:O(logn).
	int GetNumberOfK2(vector<int> data ,int k) {
		if(data.size()==0) return 0;//边界条件

		int position=binarySearch(data,0,data.size()-1,k);//输出二分查找找到的k的位置
		if(position==-1) return 0;//如果没找到，直接返回0
		int count=1;//如果找到的话，count为最终要返回的值
		int left=position-1,right=position+1;
		while(left>=0 && data[left]==k){//向position左边遍历，统计等于k的元素的个数
			count++;
			left--;
		}
		while(right<=data.size()-1 && data[right]==k){//向position右边遍历，统计等于k的元素的个数
			count++;
			
			right++;
		}

		return count;//返回最终结果

	}

	int binarySearch(vector<int> &data,int low, int high, int k){//标准的二分查找模板！
		while(low<=high){
			int mid=low+(high-low)/2;
			if(data[mid]==k){
				return mid;
			}
			else if(data[mid]>k){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		return -1;
	}
};

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> data;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		data.push_back(x);
	}

	Solution so1;
	int ans=so1.GetNumberOfK2(data,k);
	printf("%d\n",ans);
	return 0;
}