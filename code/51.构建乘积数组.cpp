/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
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
	方法一：这是最直观的想法。时间复杂度：O(n^2).
	*/
	vector<int> multiply(const vector<int>& A) {
		if(A.size()==0){
			vector<int> B;
			return B;
		}

		vector<int> B(A.size(),1);
		for(int i=0;i<A.size();i++){
			for(int j=0;j<i;j++){
				B[i]*=A[j];
			}
			for(int k=i+1;k<A.size();k++){
				B[i]*=A[k];
			}
		}

		return B;

	}

	/*
	方法二：分成两部分。时间复杂度为O(n).
	*/
	vector<int> multiply2(const vector<int>& A) {
		if(A.size()==0){
			vector<int> B;
			return B;
		}

		vector<int> B1(A.size(),1);
		vector<int> B2(A.size(),1);

		for(int i=1;i<A.size();i++){
			B1[i]=B1[i-1]*A[i-1];
		}

		for(int j=A.size()-2;j>=0;j--){
			B2[j]=B2[j+1]*A[j+1];
		}

		for(int k=0;k<A.size();k++){
			B1[k]=B1[k]*B2[k];
		}

		return B1;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> A;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		A.push_back(x);
	}

	Solution so1;
	vector<int> B=so1.multiply2(A);
	for(int i=0;i<B.size();i++){
		printf("%d ",B[i]);
	}
	printf("\n");
	return 0;
}