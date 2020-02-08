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
	ListNode * dummy=new ListNode(0);
	ListNode * pre=dummy;
	for(int i=0;i<n;i++){
		ListNode * node=new ListNode(arr[i]);
		pre->next=node;
		pre=node;
	}
	return dummy->next;
}

class Solution {
	public:
	//方法一：迭代。时间复杂度为:O(2*min{p1,p2}).p1是链表1的长度，p2是链表2的长度
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2){
        if(pHead1==nullptr){
            return pHead2;
        }
        if(pHead2==nullptr){
            return pHead1;
        }
        
        ListNode * head=new ListNode(0);
        ListNode *cur=head;
        
        while(pHead1!=nullptr && pHead2!=nullptr){
            if(pHead1->val >= pHead2->val){
                cur->next=pHead2;
                cur=cur->next;
                pHead2=pHead2->next;
            }
            else{
                cur->next=pHead1;
                cur=cur->next;
                pHead1=pHead1->next;
            }
        }
        
		if(pHead1==nullptr && pHead2==nullptr){
			return head->next;
		}

		if(pHead1==nullptr){
			if(pHead2!=nullptr){
				cur->next=pHead2;
			}
		}
		if(pHead2==nullptr){
			if(pHead1!=nullptr){
				cur->next=pHead1;
			}
		}

		return head->next;
    }

	//方法二：递归。
	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2){
		if(pHead1==nullptr){
			return pHead2;
		}
		if(pHead2==nullptr){
			return pHead1;
		}

		ListNode * head=nullptr;
		if(pHead1->val>=pHead2->val){
			head=pHead2;
			head->next=Merge2(pHead1,pHead2->next);
		}
		else{
			head=pHead1;
			head->next=Merge2(pHead1->next,pHead2);
		}

		return head;
	}

};

int main(){
	int n1,n2;
	printf("请输入两个数组长度:");
	scanf("%d%d",&n1,&n2);
	int arr1[n1];
	int arr2[n2];
	for(int i=0;i<n1;i++){
		int x;
		scanf("%d",&x);
		arr1[i]=x;
	}
	for(int i=0;i<n2;i++){
		int x;
		scanf("%d",&x);
		arr2[i]=x;
	}

	ListNode *pHead1=createListNode(arr1,n1);
	ListNode *pHead2=createListNode(arr2,n2);

	Solution so1;
	ListNode * head=so1.Merge2(pHead1,pHead2);
	while(head!=nullptr){
		printf("%d",head->val);
		if(head->next!=nullptr){
			printf("->");
		}
		head=head->next;
	}
	printf("\n");
	return 0;
}