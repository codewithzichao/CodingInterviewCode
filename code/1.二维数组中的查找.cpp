/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//关键在于怎么去找到切入点去和目标值相比较，从而缩小查找范围，选择右上角或者左下角就可以。
	//时间复杂度：O(row+col).
	bool Find1(int target, vector<vector<int> > array) {
		if(array.size()==0 || array[0].size()==0){
			return false;
		}

		int row=array.size();
		int col=array[0].size();
		int i=0;
		int j=col-1;

		while(i<row && j>=0){
			if(target==array[i][j]){
				return true;
			}
			else if(target<array[i][j]){
				j--;
			}
			else{
				i++;
			}
		}
		return false;

	}

	//使用二分查找。复杂度：O(nlogn).对每一行做二分查找。与leetcode74题一样，不知道为啥答案不一样......
	 bool Find2(int target, vector<vector<int> > array) {
		 if(array.size()==0 || array[0].size()==0){
            return false;
        }

        int row=array.size();
        int col=array[0].size();

        
       for(int i=0;i<row;i++){
           int left=0;
           int right=col-1;
           while(left<=right){
               int midIndex=left+(right-left)/2;
               int midElment=array[i][midIndex];
               if(target==midElment){
                   return true;
               }
               else if(target<midElment){
                   right=midIndex-1;
               }
               else{
                   left=midIndex+1;
               }
           }
       }
        return false;
	}
	
};

int main(){
	int row, col;
	vector<vector<int> > array;
 	scanf("%d%d",&row,&col);
	int target;
	scanf("%d",&target);
	for(int i=0;i<row;i++){
		vector<int> temp;
		for(int j=0;j<col;j++){
			int x;
			scanf("%d",&x);
			temp.push_back(x);
		}
		array.push_back(temp);
	}

	Solution so1;
	bool ans=so1.Find2(target,array);
	if(ans){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	return 0;
}