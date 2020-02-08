/*
题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//方法一：使用排序。
	bool duplicate(int numbers[], int length, int* duplication) {
		if(numbers==nullptr || length==0) return false;
		for(int i=0;i<length;i++){
			if(numbers[i]<0 || numbers[i]>=length) return false;
		}
		sort(numbers,numbers+length);
		for(int i=0;i<length-1;i++){
			if(numbers[i]==numbers[i+1]){
				*duplication=numbers[i];
				return true;
			}
		}
		return false;
	}

	//方法二。很巧妙。
	bool duplicate2(int numbers[], int length, int* duplication) {
		if(numbers==nullptr || length==0) return false;
		for(int i=0;i<length;i++){
			if(numbers[i]<0 || numbers[i]>=length) return false;
		}

		for(int i=0;i<length;i++){
			while(numbers[i]!=i){
				if(numbers[i]==numbers[numbers[i]]){
					*duplication=numbers[i];
					return true;
				}
				else{
					swap(numbers[i],numbers[numbers[i]]);
				}
			}
		}

		return false;
	}
};

int main(){
	int n;
	printf("请输入数组长度:");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i]=x;
	}

	int num=0;
	int *duplication=&num;
	Solution so1;
	bool ans=so1.duplicate2(arr,n,duplication);
	if(ans) printf("true\n");
	else printf("false\n");
	return 0;
}