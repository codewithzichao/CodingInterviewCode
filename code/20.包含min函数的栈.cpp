/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
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

	//思路：定义两个栈，st1存放数据，st2存放最小值。
	void push(int value) {
		st1.push(value);
		if(st2.empty()){
			st2.push(value);
		}
		else if(value<=st2.top()){
			st2.push(value);
		}
	}

	void pop(){
		if(st1.top()==st2.top()){
			st2.pop();
		}
		st1.pop();
	}

	int top(){
		return st1.top();
	}

	int min(){
		return st2.top();
	}

	private:
	stack<int> st1;
	stack<int> st2;
};

int main(){
	Solution so1;
	for(int i=0;i<10;i++){
		so1.push(i);
	}

	printf("%d\n",so1.min());
	return 0;
}