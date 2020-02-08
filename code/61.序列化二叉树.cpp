/*
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，
序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

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
	/*
	vector<int> vec;
	char* Serialize(TreeNode *root) {
		vec.clear();
		DFS1(root);
		int size=vec.size();
		int * ans=new int[size];
		for(int i=0;i<size;i++){
			ans[i]=vec[i];
		}

		return (char*)ans;
	}

	void DFS1(TreeNode * root){
		if(root==nullptr){
			vec.push_back(0xFFFFFFFF);
		}
		else{
			vec.push_back(root->val);
			DFS1(root->left);
			DFS1(root->right);
		}
	}

	TreeNode* Deserialize(char *str) {
		int *p=(int*)str;
		return DFS2(p);
	}

	TreeNode*DFS2(int * &p){
		if(*p==0xFFFFFFFF){
			p++;
			return nullptr;
		}
		TreeNode * node=new TreeNode(*p);
		p++;
		node->left=DFS2(p);
		node->right=DFS2(p);

		return node;
	}*/
	
	 char* Serialize(TreeNode *root) {    
        if(root==nullptr) return nullptr;
        string str;
        DFS1(root,str);
        char * ans=new char[str.size()+1];
        for(int i=0;i<str.size();i++){
            ans[i]=str[i];
        }
        ans[str.size()]='\0';
        return ans;
    }
    
    void DFS1(TreeNode * root,string &str){
        if(root==nullptr){
            str+='#';
            return;
        }
        else{
            string temp=to_string(root->val);
            str+=temp;
            str+=',';
            DFS1(root->left,str);
            DFS1(root->right,str);
        }
    }
    TreeNode* Deserialize(char *str) {
        if(str==nullptr) return nullptr;
        TreeNode * root=DFS2(str);
        return root;
    }
    
    TreeNode * DFS2(char * &str){
        if(*str=='#'){
            str++;
            return nullptr;
        }
        else{
            int num=0;
            while(*str!='\0' && *str!=','){
                num=num*10+(*str-'0');
                str++;
            }
            
            TreeNode * root=new TreeNode(num);
            if(*str=='\0'){
                return root;
            }
            else{
                str++;
                
                root->left=DFS2(str);
                root->right=DFS2(str);
                return root;
            }
        }
    }


};