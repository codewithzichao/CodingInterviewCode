/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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

//先序创建二叉树
TreeNode * createTree(){
	TreeNode * q;
	int data;
	scanf("%d",&data);
	if(data==0){
		q=nullptr;
	}
	else{
		q=new TreeNode(data);
		q->left=createTree();
		q->right=createTree();
	}

	return q;
}

class Solution{
	public:
	//层序遍历，标准模板！
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if(root==nullptr){
			vector<int> ans;
			return ans;
		}

		vector<int> vec;
		queue<TreeNode*> q;
		q.push(root);
		
		while(q.empty()==false){
			TreeNode * node=q.front();
			q.pop();
			vec.push_back(node->val);
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
		}

		return vec;

	}
};

int main(){
	printf("请输入数据：");
	TreeNode * root=createTree();
	Solution so1;
	vector<int> ans=so1.PrintFromTopToBottom(root);
	printf("层次遍历结果为：");
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}