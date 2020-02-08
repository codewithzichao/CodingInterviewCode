/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
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
	/*
	方法一：使用递归。
	*/
	bool isSymmetrical(TreeNode* pRoot){
		return isSymmentrical(pRoot,pRoot);
	}

	bool isSymmentrical(TreeNode * pRoot1,TreeNode * pRoot2){
		if(pRoot1==nullptr && pRoot2==nullptr) return true;
		if(pRoot1==nullptr || pRoot2==nullptr) return false;
		if(pRoot1->val!=pRoot2->val) return false;

		return isSymmentrical(pRoot1->left,pRoot2->right) && isSymmentrical(pRoot1->right,pRoot2->left);
	}

	/*
	方法二：使用BFS。（DFS也可）
	*/
	 bool isSymmetrical2(TreeNode* pRoot)
    {
        if(pRoot==nullptr) return true;
        queue<TreeNode*> q;
        q.push(pRoot->left);
        q.push(pRoot->right);
        
        while(q.empty()!=false){
            TreeNode *left1=q.front();
            q.pop();
            TreeNode * right1=q.front();
            q.pop();
            if(left1==nullptr && right1==nullptr) continue;
            if(left1==nullptr || right1==nullptr) return false;
            if(left1->val!=right1->val) return false;
            q.push(left1->left);
            q.push(right1->right);
            q.push(left1->right);
            q.push(right1->left);
        }
        
        return true;
    }
};

int main(){
	return 0;
}