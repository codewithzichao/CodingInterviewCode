/*
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
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
	思路：典型的层序遍历。但是加入奇偶的判断即可。
	*/
	vector<vector<int> > Print(TreeNode* pRoot) {
		if(pRoot==nullptr){
			vector<vector<int> > ans;
			return ans;
		}

		vector<vector<int> > vec;
		queue<TreeNode*> q;
		q.push(pRoot);
		bool flag=true;

		while(q.empty()==false){
			vector<int> temp;
			int size=q.size();
			while(size--!=0){
				TreeNode * node=q.front();
				q.pop();
				temp.push_back(node->val);
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			}
			if(flag==false) reverse(temp.begin(),temp.end());
			vec.push_back(temp);
			flag=!flag;
		}

		return  vec;
	}

	/*
	思路：使用两个栈来完成遍历。栈st1来存放奇数层的节点；栈st2来存放偶数层的节点。
	*/
	vector<vector<int> > Print2(TreeNode* pRoot) {
		if(pRoot==nullptr){
			vector<vector<int> > vec;
			return vec;
		}

		vector<vector<int> > vec;
		stack<TreeNode*> st1,st2;
		st1.push(pRoot);

		while(st1.empty()==false || st2.empty()==false){
			vector<int> ret1,ret2;
			TreeNode * cur=nullptr;
			while(st1.empty()==false){
				cur=st1.top();
				if(cur->left) st2.push(cur->left);
				if(cur->right) st2.push(cur->right);
				ret1.push_back(st2.top()->val);
			}
			if(ret1.size()) vec.push_back(ret1);

			while(st2.empty()==false){
				cur=st2.top();
				if(cur->right) st1.push(cur->right);
				if(cur->left) st1.push(cur->left);
				ret2.push_back(st2.top()->val);
			}
			if(ret2.size()) vec.push_back(ret2);
		}
		return vec;


	}
};

int main(){
	return 0;
}