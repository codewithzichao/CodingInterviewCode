/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution{
	public:
	//主要是要确定排序的规则。
	string PrintMinNumber(vector<int> numbers) {
		if(numbers.size()==0){
			return "";
		}

		string ans;
		sort(numbers.begin(),numbers.end(),cmp);//排序之后，numbers中的顺序就是最小的顺序
		for(int i=0;i<numbers.size();i++){
			ans+=to_string(numbers[i]);
		}

		return ans;
	}

	//排序规则
	static bool cmp(int a,int b){
		string stringA=to_string(a)+to_string(b);
		string stringB=to_string(b)+to_string(a);
		return stringA<stringB;
	
	}
};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> numbers;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		numbers.push_back(x);
	}

	Solution so1;
	string ans=so1.PrintMinNumber(numbers);
	cout<<ans<<endl;
	return 0;
}