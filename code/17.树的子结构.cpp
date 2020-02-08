/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution{
	public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if(pRoot1==nullptr || pRoot2==nullptr){
			return false;
		}

		return (DFS(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2));
	}

	bool DFS(TreeNode * pRoot1 ,TreeNode * pRoot2){
		if(pRoot1==nullptr){
			return false;
		}
		if(pRoot2==nullptr){
			return true;
		}

		/*
		注意：因为节点的值为int类型，所以可以直接判断两个数相不相等；如果是double的话，就不能直接判断相不相等了！
		*/
		if(pRoot1->val!=pRoot2->val){
			return false;
		}
		/*
		//比如，如果是double类型的话，需要先定义一个Equal函数，来判断两者是否相等。
		bool Equal(double num1,double num2){
			if((num1-num2>-0.0000001) && *(num1-num2<0.0000001)){
				return true;
			}
			else{
				return false;
			}
		}
		if(!Equal(pRoot1->val,pRoot2->val)){
			return false;
		}
		*/

		return (DFS(pRoot1->left,pRoot2->left) && DFS(pRoot1->right, pRoot2->right));
	}
};

int main(){
	return 0;
}

