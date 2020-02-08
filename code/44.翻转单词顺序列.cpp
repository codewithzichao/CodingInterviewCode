/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
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
	/*
	思路其实挺简单的。对于输入的字符串，一旦遇到空格，那么就反转当个单词；最后，反转整个句子。over～
	*/
	string ReverseSentence(string str) {
		if(str.size()==0){//边界条件，其实可以不要
			return str;
		}

		str+=" ";//为了反转最后一个单词，必须要加空格
		int low=0;
		for(int i=0;i<str.size();i++){
			if(str[i]==' '){
				reverseWord(str,low,i-1);
				low=i+1;
			}
		}

		str=str.substr(0,str.size()-1);//把空格去掉
		reverseWord(str,0,str.size()-1);//反转真个单词

		return str;
	}

	void reverseWord(string &str,int low,int high){//反转单个单词
		for(int i=low,j=high;i<j;i++,j--) swap(str[i],str[j]);
		return;
	}
};

int main(){
	string str;
	getline(cin,str);//由于输入有空格，所以得用getline，不能直接用cin
	Solution so1;
	string ans=so1.ReverseSentence(str);
	cout<<ans<<endl;
	return 0;
}