/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if(matrix.size()==0 || matrix[0].size()==0){
			vector<int> ans;
			return ans;
		}

		vector<int> result;
		int row=matrix.size();
		int col=matrix[0].size();

		int left=0,right=col-1,top=0,bottom=row-1;
		while(left<=right && top<=bottom){
			for(int i=left;i<=right;i++){
				result.push_back(matrix[top][i]);
			}

			if((++top)<=bottom){
				for(int i=top;i<=bottom;i++){
					result.push_back(matrix[i][right]);
				}
			}
			else{
				break;
			}

			if(left<=(--right)){
				for(int i=right;i>=left;i--){
					result.push_back(matrix[bottom][i]);
				}
			}
			else{
				break;
			}

			if(top<=(--bottom)){
				for(int i=bottom;i>=top;i--){
					result.push_back(matrix[i][left]);
				}
			}
			else{
				break;
			}

			left++;

		}

		return result;
	}
};

int main(){
	int row,col;
	scanf("%d%d",&row,&col);
	vector<vector<int> > matrix;
	for(int i=0;i<row;i++){
		vector<int> temp;
		for(int j=0;j<col;j++){
			int x;
			scanf("%d",&x);
			temp.push_back(x);
		}
		matrix.push_back(temp);
	}

	Solution so1;
	vector<int> ans=so1.printMatrix(matrix);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}