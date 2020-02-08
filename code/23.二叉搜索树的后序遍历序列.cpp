/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
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
	思路：
	1.找到根节点root。由于sequence是后序遍历序列，所以最后一个元素就是根节点。
	2.找到左子树。从前往后遍历sequence，将每一个元素与root相比较，如果出现大于根节点的值，break，说明找到了左子树了，退出遍历；
	3.找到右子树。从刚刚break的点开始，到倒数第二个为止，就是右子树了。但是仍然需要遍历，如果出现小于root的节点，直接返回false，说明sequence不是二叉搜索树。
	4.对左子树递归。判断是不是二叉搜索树；对右子树递归，判断是不是二叉搜索树。
	5.当左子树和右子树均是二叉搜索树的时候，说明sequence是二叉搜索树；否则，就不是二叉搜索树。
	over～
	*/

	bool VerifySquenceOfBST1(vector<int> sequence) {
		if(sequence.size()==0){
			return false;
		}

		int root=sequence[sequence.size()-1];
		int i=0;
		for(;i<sequence.size()-1;i++){
			if(sequence[i]>root){
				break;
			}
		}

		int j=i;
		for(;j<sequence.size()-1;j++){
			if(sequence[j]<root){
				return false;
			}
		}

		bool left=true;
		if(i>0){
			vector<int>::iterator it1=sequence.begin();
			vector<int>::iterator it2=sequence.begin()+i;
			vector<int> s1(it1,it2);
			left=VerifySquenceOfBST1(s1);
		}

		bool right=true;
		if(j<sequence.size()-1){
			vector<int>::iterator it1=sequence.begin()+i;
			vector<int>::iterator it2=sequence.begin()+i+sequence.size()-1-i;
			vector<int> s2(it1,it2);
			right=VerifySquenceOfBST1(s2);
		}

		return left&&right;
	}

	//方法二：在牛客网上看到的一位大佬的解答，牛逼炸了！但是时间复杂度比递归版本要高，空间复杂度不变
	bool VerifySquenceOfBST2(vector<int> sequence) {
		int n=sequence.size();
		if(n==0){
			return false;
		}

		int i=0;
		while(--n){
			while(sequence[i++]<sequence[n]);//左子树
			while(sequence[i++]>sequence[n]);//右子树

			if(i<n){//如果i没有遍历到n，说明不是二叉搜索树，返回false
				return false;
			}

			i=0;//i归0，重新开始
		}

		return true;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> sequence;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		sequence.push_back(x);
	}

	Solution so1;
	bool ans=so1.VerifySquenceOfBST2(sequence);
	if(ans) printf("true\n");
	else printf("false\n");
	return 0;
}

