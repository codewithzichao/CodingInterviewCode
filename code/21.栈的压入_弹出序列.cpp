/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Solution{
	public:

	/*
	思路：其实很简单。建立一个辅助栈。依次将pushV中的元素压入栈中；
	每次压入一个元素的时候，判断栈顶的元素是否等于popV的元素；
	如果等于，就弹出栈顶元素，并且j指向popV中的下一个元素，直到不相等为止；
	最后，如果辅助栈中没有元素的话，那么就说明，popV是一个出栈顺序；如果不为空，那么就说明不是一个出栈顺序。
	over～
	*/
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		if(pushV.size()==0 || popV.size()==0){
			return false;
		}

		stack<int> st1;
		int j=0;
		for(int i=0;i<pushV.size();i++){
			st1.push(pushV[i]);
			while(st1.empty()==false && st1.top()==popV[j]){
				st1.pop();
				j++;
			}
		}

		return st1.empty()==true;

	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> pushV,popV;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		pushV.push_back(x);
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		popV.push_back(x);
	}

	Solution so1;
	bool ans=so1.IsPopOrder(pushV,popV);
	if(ans) printf("true\n");
	else printf("false\n");
	return 0;

}