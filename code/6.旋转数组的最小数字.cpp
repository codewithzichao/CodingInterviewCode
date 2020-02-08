/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//思路：二分查找。
	int minNumberInRotateArray(vector<int> rotateArray) {
		if(rotateArray.size()==0){//边界条件
			return 0;
		}
		int left=0;
		int right=rotateArray.size()-1;
		if(rotateArray[right]>rotateArray[left] || rotateArray.size()==1){
			return rotateArray[left];
		}

		while(left<=right){
			int mid=left+(right-left)/2;
			int temp=rotateArray[mid];
			if(temp>rotateArray[mid+1]){
				return rotateArray[mid+1];
			}
			if(rotateArray[mid-1]>temp){
				return rotateArray[mid];
			}
			if(temp>rotateArray[left]){
				left=mid+1;
			}
			else if(temp<rotateArray[right]){
				right=mid-1;
			}
		}
		return 0;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> rotateArray;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		rotateArray.push_back(x);
	}

	Solution so1;
	int ans=so1.minNumberInRotateArray(rotateArray);
	printf("%d\n",ans);
	return 0;
}