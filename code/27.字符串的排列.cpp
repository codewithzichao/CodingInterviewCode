/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
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
	//对于求解全排列问题，使用回溯+DFS。时间复杂度为:O(n!).
	vector<string> Permutation(string str) {
		if(str.size()==0){
			vector<string> ans;
			return ans;
		}

		vector<string> vec;
		DFS(str,vec,0);
		sort(vec.begin(),vec.end());//注意，因为题目要求按字典序打印，所以需要排序，这一步必不可少！
		return vec;
	}

	void DFS(string str,vector<string> &vec,int n){
		if(n==str.size()-1){
			if(find(vec.begin(),vec.end(),str)==vec.end()){//因为题目里有说str中的字符可以重复，所以必须增加一步判断
				vec.push_back(str);
				return;
			}
		}
		else{
			for(int i=n;i<str.size();i++){
				swap(str[i],str[n]);
				DFS(str,vec,n+1);
				swap(str[i],str[n]);
			}
		}

	}
};

int main(){
	string str;
	getline(cin,str);
	Solution so1;
	vector<string> ans=so1.Permutation(str);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}