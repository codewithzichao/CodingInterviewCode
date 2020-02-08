/*
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//典型的回溯
	int movingCount(int threshold, int rows, int cols){
		if(threshold<0 || rows<0 || cols<0) return 0;
		bool * flag=new bool[rows*cols];
		for(int i=0;i<rows*cols;i++){
			flag[i]=false;
		}

		int count=BFS(threshold,rows,cols,0,0,flag);

		delete[] flag;
		return count;
	}

	int BFS(int threshold,int rows,int cols,int i,int j,bool * &flag){
		int count=0;
		if(ischeck(threshold,rows,cols,i,j,flag)){
			flag[i*cols+j]=true;
			count+=1+BFS(threshold,rows,cols,i+1,j,flag)+BFS(threshold,rows,cols,i-1,j,flag)
			+BFS(threshold,rows,cols,i,j+1,flag)+BFS(threshold,rows,cols,i,j-1,flag);
		}

		return count;
	}

	bool ischeck(int threshold ,int rows,int cols,int i,int j,bool * &flag){
		if(i>=0 && i<rows && j>=0 && j<cols && flag[i*cols+j]==false && getSum(i)+getSum(j)<=threshold){
			return true;
		}
		else{
			return false;
		}

	}

	int getSum(int number){
		int sum=0;
		while(number!=0){
			sum+=(number%10);
			number/=10;
		}
		return sum;
	}
};

int main(){
	int threshold,rows,cols;
	scanf("%d%d%d",&threshold,&rows,&cols);
	Solution so1;
	int ans=so1.movingCount(threshold,rows,cols);
	printf("%d\n",ans);
	return 0;
}