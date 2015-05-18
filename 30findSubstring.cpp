/*
 * =====================================================================================
 *
 *       Filename:  30findSubstring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月17日 20时41分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution{
	public:
		vector<int> findSubstring(string s, vector<string>& words);
};

/*vector<int> Solution::findSubstring(string s , vector<string>& words)
{
	int wordLen = words[0].length();
	int totalLen = wordLen * words.size();
	const int size = words.size();
	vector<int> res;
	

	//先排序，然后去掉words中的重复元素
	sort(words.begin() , words.end());
	//words.erase(unique(words.begin() , words.end()) , words.end());

	if(s.length() < totalLen){
		return res;
	}
	int i , j , st , en;
	bitset<1024> bs;
	for(i = 0 ; i <= s.length()-totalLen ; i++){
		bs.reset();
		for(j = 1 ; j <= words.size() ;j++){
			string strTmp = s.substr(i+(j-1)*wordLen , wordLen);
			bool flag = false;
			for(k = 0 ; k < words.size() ;k++){
				if(strTmp == words[k]){
					if(!bs.test(k)){
						bs.set(k);
						flag = true;
						break;
					}else{
						continue;
					}
				}
			}
			st = 0;
			en = words.size();
			while(st < en){
				int mid = (st+en)/2;
				if(words[mid] < strTmp){
					st = mid+1;
				}
				else if(words[mid] > strTmp){
					en = mid;
				}
				else{
					int start = mid , end = mid , pos;
					while(start>0 && words[start-1] == words[start]){
						start--;
					}
					while(end+1<words.size() && words[end] == words[end+1]){
						end++;
					}
					for(pos = start ; pos <= end ; pos++){
						if(!bs.test(pos)){
							bs.set(pos);
							flag = true;
							break;
						}
					}
					if(flag){
						break;
					}
				}
			}
			if(!flag){
				break;
			}
		}
		if(j == words.size()+1 && bs.count() == words.size()){
			res.push_back(i);
		}
	}
	return res;
}*/

vector<int> Solution::findSubstring(string s , vector<string>& words)
{
	int wordLen = words[0].length();
	int totalLen = wordLen * words.size();
	
	vector<int> res;
	if(s.length() < totalLen){
		return res;
	}
	map<string , int> m;
	
	int i , j , k;			//循环变量
	//初始化m
	for(k = 0 ; k < words.size() ; k++){
		m[words[k]]++;
	}
	for(i = 0 ; i <= s.length() - totalLen ; i++){
		map<string , int> mTmp;
		for(j = 0 ; j < words.size() ; j++){
			string strTmp = s.substr(i + j*wordLen , wordLen);
			mTmp[strTmp]++;
			if(mTmp[strTmp] > m[strTmp]){
				break;	
			}
		}
		if(j == words.size()){
			res.push_back(i);
		}
	}
}
int main(int argc ,char * argv[])
{
	Solution sol;
	string str("abababab");
	vector<int> res;
	vector<string> words;
	words.push_back("ab");
	words.push_back("ba");
	//words.push_back("a");
	//words.push_back("barr");
	//words.push_back("wing");
	//words.push_back("ding");
	//words.push_back("wing");
	res = sol.findSubstring(str , words);

	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

