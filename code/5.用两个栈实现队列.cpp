/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
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
	void push(int node){
		stack1.push(node);
	}

	int pop1(){
	//这是最直观的想法，但是可以优化，这样太过于繁琐了
		 while(stack1.empty()==false){
            int temp1=stack1.top();
            stack2.push(temp1);
            stack1.pop();
        }
        int temp2=stack2.top();
        stack2.pop();
        while(stack2.empty()==false){
            int temp3=stack2.top();
            stack1.push(temp3);
            stack2.pop();
        }
        return temp2;
	}

	//优化之后的结果
	int pop2(){
		int a;
		if(stack2.empty()){
			while(stack1.empty()==false){
				a=stack1.top();
				stack2.push(a);
				stack1.pop();

			}
		}
		a=stack2.top();
		stack2.pop();
		return a;
	}

	private:
	stack<int> stack1;
	stack<int> stack2;
};