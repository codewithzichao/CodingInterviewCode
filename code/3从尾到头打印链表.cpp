/*
题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

//定义ListNode
struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(nullptr){}
};

//使用后插法创建链表
ListNode *bulidList(int *arr,int n){
		ListNode * dummy=new ListNode(0);;
		ListNode *head=dummy;
		for(int i=0;i<n;i++){
			ListNode * node=new ListNode(arr[i]);
			head->next=node;
			head=head->next;
		}
		return dummy->next;
	}


class Solution{
	public:
	/*
	方法一：使用栈。
	*/
	vector<int> printListFromTailToHead1(ListNode* head) {
		vector<int> ans;
		if(head==nullptr){
			return ans;
		}

		stack<int> st;
		while(head!=nullptr){
			st.push(head->val);
			head=head->next;
		}

		while(st.empty()==false){
			ans.push_back(st.top());
			st.pop();
		}

		return ans;
	}

	//方法二：递归。
	vector<int> printListFromTailToHead2(ListNode* head) {
		if(head==nullptr){
			vector<int> ans;
			return ans;
		}

		vector<int> ans=printListFromTailToHead2(head->next);
		ans.push_back(head->val);
		return ans;

	}

};

int main(){
	int arr[]={1,2,3,4,5};
	int *arr1=&arr[0];
	ListNode * head=bulidList(arr1,5);
	
	Solution so1;
	vector<int> ans=so1.printListFromTailToHead2(head);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
