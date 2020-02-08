/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution{
	public:
	void Mirror(TreeNode *pRoot) {
		if(pRoot==nullptr || (pRoot->left==nullptr && pRoot->right==nullptr)){//边界条件
			return;
		}

		TreeNode * pTemp=pRoot->left;
		pRoot->left=pRoot->right;
		pRoot->right=pTemp;

		if(pRoot->left){
			Mirror(pRoot->left);
		}
		if(pRoot->right){
			Mirror(pRoot->right);
		}
	}
};

int main(){
	return 0;
}