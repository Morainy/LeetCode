/*
 * =====================================================================================
 *
 *       Filename:  49anagrams.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月25日 11时22分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution{
	public:
		vector<string> anagrams(vector<string>& strs);
};

vector<string> Solution::anagrams(vector<string>& strs)
{
	vector<string> res;
	if(strs.size() <= 1){
		return res;
	}
	map<string , int> map;
	string s;
	for(int i = 0 ; i < strs.size() ; i++){
		s = strs[i];
		sort(s.begin() , s.end());
		if(map.find(s) == map.end()){
			map[s] = i;
		}else{
			if(map[s] >= 0){
				res.push_back(strs[map[s]]);
				map[s] = -1;
			}
			res.push_back(strs[i]);
		}
	}
	return res;
}

int main(int argc , char * argv[])
{
	Solution sol;
	vector<string> vstrs;
	vstrs.push_back("");
	vstrs.push_back("");

	vector<string> res;
	res = sol.anagrams(vstrs);

	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<endl;
	}
}

