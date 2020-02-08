/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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
	方法一：另建一个vector，空间换时间。时间复杂度为O(n),空间复杂度为O(n).
	*/
	void reOrderArray1(vector<int> &array) {
		vector<int> vec;
		for(int i=0;i<array.size();i++){
			if((array[i] & 0x1)==1){
				vec.push_back(array[i]);
			}
		}

		for(int j=0;j<array.size();j++){
			if((array[j] & 0x1)==0){
				vec.push_back(array[j]);
			}
		}
		array=vec;
	}

	//类似于插入排序。
	void reOrderArray2(vector<int> &array) {
		for(int i=1;i<array.size();i++){
			int temp=array[i];
			if(temp%2==1){
				for(int j=i;j>0;j--){
					if(array[j-1]%2==0){
						int t=array[j-1];
						array[j-1]=array[j];
						array[j]=t;
					}
				}
			}
		}
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> array;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		array.push_back(x);
	}

	Solution so1;
	so1.reOrderArray2(array);
	for(int i=0;i<array.size();i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}