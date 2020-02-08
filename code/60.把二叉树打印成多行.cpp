/*
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
	//典型的层序遍历！
	vector<vector<int> > Print(TreeNode* pRoot) {
		if(pRoot==nullptr){
			vector<vector<int> > vec;
			return vec;
		}

		vector<vector<int> > vec;
		queue<TreeNode*> q;
		q.push(pRoot);

		while(q.empty()==false){
			vector<int> temp;
			int size=q.size();
			while(size--!=0){
				TreeNode * node=q.front();
				q.pop();
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
				temp.push_back(node->val);
			}
			vec.push_back(temp);
		}

		return vec;

	}
};

int main(){
	return 0;