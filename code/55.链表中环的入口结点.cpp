/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
	思路看代码。
	
	假设x为环前面的路程，a为环入口到相遇点的路程， c为环的长度
	当快慢指针相遇的时候：
	此时慢指针走的路程为Sslow = x + m * c + a
	快指针走的路程为Sfast = x + n * c + a
	2 Sslow = Sfast
	2 * ( x + m*c + a ) = (x + n *c + a)
	从而可以推导出：
	x = (n - 2 * m )*c - a
	= (n - 2 *m -1 )*c + c - a
	即环前面的路程 = 数个环的长度（为可能为0） + c - a
	什么是c - a？这是相遇点后，环后面部分的路程。
	环前面的路程=数个环的长度+相遇点后环部分的路程
	也就是说，我们让一个指针从链头开始遍历，一个指针从相遇点开始遍历，足后一定能在环入口相遇！
	证明完毕
	over～
	*/
	ListNode* EntryNodeOfLoop(ListNode* pHead){
		if(pHead==nullptr) return nullptr;
		ListNode * low=pHead,*fast=pHead;
		while(fast!=nullptr && fast->next!=nullptr){//首先判断是否有环
			fast=fast->next->next;
			low=low->next;
			if(low==fast){
				break;
			}
		}

		if(fast==nullptr || fast->next==nullptr) return nullptr;//如果没有环，返回false

		//如果有环，那么low指针从pHead开始遍历，fast从相遇点开始遍历，两者一定在环入口相遇。
		low=pHead;
		while(low!=fast){
			low=low->next;
			fast=fast->next;
		}

		return low;
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
	ListNode * ans=so1.EntryNodeOfLoop(pHead);
	printf("%d\n",ans->val);
	return 0;
}

