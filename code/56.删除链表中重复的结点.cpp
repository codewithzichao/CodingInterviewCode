/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode * createListNode(int arr[],int n){
	ListNode *dummy=new ListNode(0);
	ListNode * pre=dummy;
	for(int i=0;i<n;i++){
		ListNode * node=new ListNode(arr[i]);
		pre->next=node;
		pre=node;
	}

	return dummy->next;
}

class Solution{
	public:
	/*
	方法一：迭代。步骤如下：
	1.我们创建一个附加头节点，以防止碰到第一个与第二个节点就相同的情况；
	2.设置 pre ，last 指针， pre指针指向当前确定不重复的那个节点，而last指针相当于工作指针，一直往后面搜索。
	over～
	*/
	ListNode* deleteDuplication(ListNode* pHead){
		if(pHead==nullptr || pHead->next==nullptr) return pHead;//边界条件
		
		ListNode * dummy=new ListNode(0);//创建附加头节点
		ListNode * pre=dummy;
		dummy->next=pHead;
		ListNode * last=pre->next;
		while(last!=nullptr){
			if(last->next!=nullptr && last->val==last->next->val){
				while(last->next!=nullptr && last->val==last->next->val){
					last=last->next;
				}
				pre->next=last->next;
				last=last->next;
			}
			else{
				pre=pre->next;
				last=last->next;
			}
		}

		return dummy->next;
	}

	/*
	递归：主要就是分为两种情况：
	1.当第一个节点与第二个节点相同的时候，那么，需要找到与第一个节点不相同的节点，然后递归调用deleteDuplication2；
	2.当第一个节点与第二个节点不相同的时候，那么，直接递归调用deleteDuplication2。
	over～
	*/
	ListNode* deleteDuplication2(ListNode* pHead){
		if(pHead==nullptr || pHead->next==nullptr) return pHead;

		if(pHead->val==pHead->next->val){
			ListNode * pNode=pHead->next;
			while(pNode!=nullptr && pHead->val==pNode->val){
				pNode=pNode->next;
			}
			return deleteDuplication2(pNode);
		}
		else{
			pHead->next=deleteDuplication2(pHead->next);
			return pHead;
		}
	}
};

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i]=x;
	}

	ListNode * pHead=createListNode(arr,n);
	Solution so1;
	ListNode * ans=so1.deleteDuplication2(pHead);
	while(ans!=nullptr){
		printf("%d",ans->val);
		ans=ans->next;
		if(ans!=nullptr){
			printf("->");
		}
	}
	printf("\n");
	return 0;
}