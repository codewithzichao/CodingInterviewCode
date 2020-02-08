/*
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
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
	典型的回溯，使用BFS。
	*/
	bool hasPath(char* matrix, int rows, int cols, char* str){
		int * flag=new int[rows*cols+1];
        memset(flag,0,sizeof(flag));
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(BFS(matrix,rows,cols,str,i,j,0,flag)){
					return true;
				}
			}
		}

		return false;
	}

	bool BFS(char * matrix,int rows,int cols,char * str,int i,int j,int k,int * &flag){
		int index=i*cols+j;
		if(i<0 || i>=rows || j<0 || j>=cols || matrix[index]!=str[k] || flag[index]==1){
			return false;
		}
		if(str[k+1]=='\0'){
			return true;
		}
		flag[index]=1;
		if(BFS(matrix,rows,cols,str,i+1,j,k+1,flag) || BFS(matrix,rows,cols,str,i-1,j,k+1,flag)
		 || BFS(matrix,rows,cols,str,i,j+1,k+1,flag) || BFS(matrix,rows,cols,str,i,j-1,k+1,flag)){
			return true;
		}
		flag[index]=0;
		return false;
	}
};


int main(){
	int rows,cols;
	scanf("%d%d",&rows,&cols);
	char matrix[rows*cols+1];
	for(int i=0;i<rows*cols+1;i++){
		char c;
		scanf("%c",&c);
		matrix[i]=c;
	}

	int n;
	scanf("%d",&n);
	char str[n+1];
	for(int i=0;i<n+1;i++){
		char c;
		scanf("%c",&c);
		str[i]=c; 
	}

	Solution so1;
	bool ans=so1.hasPath(matrix,rows,cols,str);
	if(ans) printf("true\n");
	else printf("false\n");

	return 0;
}