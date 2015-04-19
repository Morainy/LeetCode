/*
 * =====================================================================================
 *
 *       Filename:  187RepeatedDNASequences.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月18日 15时38分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
	public:
		vector<string> findRepeatedDnaSequences(string s);
		int toInt(char ch)
		{
			if (ch == 'A') return 0;
			if (ch == 'C') return 1;
			if (ch == 'G') return 2;
			else return 3;
		}

		string toString(int n); 
};

string Solution::toString(int n)
{
	string str;
	int i;
	for(i = 0 ; i < 10 ; i++){
		char c = 'T';
		int tmp = n % 4;
		n = n >> 2;
		if(tmp == 0) c = 'A';
		if(tmp == 1) c = 'C';
		if(tmp == 2) c = 'G';
		str.insert(0 ,1,c);
	}
	return str;
}
vector<string> Solution::findRepeatedDnaSequences(string s)
{
	vector<string> res;
	map<int , int> m;
	int length = s.length();
	if(length <= 10){
		return res;
	}

	int tmp = 0;
	for(int i = 0 ; i < 10; i++){
		tmp = tmp<<2;
		tmp = tmp | toInt(s.at(i));
	}
	m.insert(pair<int, int>(tmp , 1));
	for(int j = 10 ; j < length ; j++){
		tmp = ((tmp & 0x3FFFF)<<2) | toInt(s.at(j));
		if(m.count(tmp)){
			m[tmp]++;
		}
		else{
			m.insert(pair<int, int>(tmp , 1));
		}
	}

	map<int, int>::iterator it;
	for(it = m.begin() ; it != m.end(); it++){
		if(it->second > 1){
			res.push_back(toString(it->first));
		}
	}
	return res;
}
int main(int argc ,char * argv[])
{
	Solution s;
	vector<string> res(s.findRepeatedDnaSequences("GAGAGAGAGAGA"));
	vector<string>::iterator it;
	for (it = res.begin(); it != res.end(); it++){
		cout<<*it<<endl;
	}

}
