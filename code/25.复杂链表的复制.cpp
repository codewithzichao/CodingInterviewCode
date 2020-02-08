/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution{
	public:
	RandomListNode* Clone(RandomListNode* pHead){
		if(pHead==nullptr){
			return nullptr;
		}

		CloneList(pHead);
		CloneRandom(pHead);
		RandomListNode * ans=SplitList(pHead);
		return ans;
	}

	//复制节点，并将节点插入到当前节点的后面
	void CloneList(RandomListNode * pHead){
		RandomListNode * cur=pHead;
		while(cur!=nullptr){
			RandomListNode * node=new RandomListNode(cur->label);
			node->next=cur->next;
			cur->next=node;
			cur=node->next;
		}
	}

	//复制节点的random指针
	void CloneRandom(RandomListNode * pHead){
		RandomListNode * cur=pHead;
		while(cur!=nullptr){
			RandomListNode * node=cur->next;
			if(cur->random){
				node->random=cur->random->next;
			}
			cur=node->next;
		}
	}

	//拆分链表
	RandomListNode * SplitList(RandomListNode * pHead){
		RandomListNode * cur=pHead;
		RandomListNode * result=pHead->next;
		while(cur!=nullptr){
			RandomListNode * node=cur->next;
			cur->next=node->next;
			cur=cur->next;
			if(cur!=nullptr){
				node->next=cur->next;
			}
		}
		
        return result;
	}
};

int main(){
	return 0;
}