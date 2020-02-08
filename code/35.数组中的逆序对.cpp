/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5

*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


class Solution{
	public:
	//方法一：暴力解。时间复杂度:O(n^2).无法AC！
	int InversePairs(vector<int> data) {
		if(data.size()==0){
		return 0;
		}

		int count=0;
		for(int i=0;i<data.size()-1;i++){
			int temp=data[i];
			for(int j=i+1;j<data.size();j++){
				if(temp>data[j]){
					count++;
				}
			}
		}

		return count%1000000007;
	}

	//方法二：采用归并排序的思想。这道题有意思！
	int InversePairs2(vector<int> data) {
		if(data.size()==0){//边界条件
			return 0;
		}

		vector<int> copydata;//创建辅助数组
		for(int i=0;i<data.size();i++){
			copydata.push_back(data[i]);
		}

		long long count=InversePairsCore(data,copydata,0,data.size()-1);//得到所有的逆序数
		return count%1000000007;//按要求返回
	}

	long long InversePairsCore(vector<int> &data,vector<int> &copydata,int start,int end){
		if(start==end){//当start==end的时候，把copydata的数据赋给data
			data[start]=copydata[start];
			return 0;
		}

		int length=(end-start)/2;//将数组分为两半，length表示数组长度的一半
		int i=start+length;//指针左半边数组的最后一个数的位置
		int j=end;//指针指向右半边数组的最后一个数的位置
		int indexCopy=end;//指针指向辅助数组的最后一个数的位置
		long long count=0;//统计左半边数组与右半边数组之间的逆序数总数
		long long left=InversePairsCore(data,copydata,start,start+length);//左半边数组的逆序数总数
		long long right=InversePairsCore(data,copydata,start+length+1,end);//右半边数组的逆序数总数

		while(i>=start && j>=start+length+1){//统计左半边数组与右半边数组之间的逆序数总数
			if(data[i]>data[j]){//如果左半边数组的元素>右半边数组的元素，那么将左半边数组的数复制到辅助数组中，并且count增加j-(start+length+1)+1。
				copydata[indexCopy--]=data[i--];
				count=count+j-(start+length+1)+1;
			}
			else{
				copydata[indexCopy--]=data[j--];//如果左半边数组的元素<=右半边数组的元素，那么将右半边数组的元素加入辅助数组中，count不变
			}
		}

		for(;i>=start;i--){//如果左半边数组还没有遍历完，即没有全部加入到辅助数组中，那么就将剩余的元素全部加入辅助数组中
			copydata[indexCopy--]=data[i];
		}
		for(;j>=start+length+1;j--){//如果右半边数组还没有遍历完，即没有全部加入到辅助数组中，那么就将剩余的元素全部加入辅助数组中
			copydata[indexCopy--]=data[j];
		}

		for(int k=start;k<=end;k++){//这一步非常关键，一定要将辅助数组中的元素全部赋给原来的数组，这样的话，递归才不会出错
			data[k]=copydata[k];
		}

		return left+right+count;//返回逆序数总数
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> data;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		data.push_back(x);
	}

	Solution so1;
	int ans=so1.InversePairs2(data);
	printf("%d\n",ans);
	return 0;
}