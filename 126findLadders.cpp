/*
 * =====================================================================================
 *
 *       Filename:  126findLadders.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月29日 16时55分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*class Solution{
	public:
		vector<vector<string> > findLadders(string start , string end , unordered_set<string>& dict);
};

vector<vector<string> > Solution::findLadders(string start , string end , unordered_set<string>& dict)
{
	vector<vector<string> > res;
	queue<string> q;
	q.push(start);
	q.push("");
	int finalCnt = -1;
	int cnt = 1;
	while(!q.empty()){
		string str = q.front();
		q.pop();
		vector<string> tmp;
		if(str != ""){
			tmp.push_back(str);
			for(int i = 0 ; i < str.length() ; i++){
				char tmpCh = str[i];
				for(char c = 'a'; c <= 'z' ; c++){
					if(c == tmpCh){
						continue;
					}
					str[i] = c;
					if(str == end){
						if(finalCnt == -1){
							finalCnt = cnt + 1;
						}else{
							if(cnt > finalCnt){
								return res;
							}
						}
						tmp.push_back(str);
						res.push_back(tmp);
						continue;
					}
					if(dict.find(str) != dict.end()){
						q.push(str);
						dict.erase(str);
					}
					str[i] = tmpCh;
				}
			}
		}else if(!q.empty()){
			cnt++;
			q.push("");
		}
	}
	return res;
}*/

class Solution{
	public:
		unordered_map<string , vector<string> > mp;
		vector<vector<string> > res;
		vector<string> path;

		void findDict2(string str , unordered_set<string>& dict , unordered_set<string>& next_lev);
		void output(string& start , string last);
		vector<vector<string> > findLadders(string start , string end , unordered_set<string>& dict);
};

void Solution::findDict2(string str , unordered_set<string>& dict , unordered_set<string>& next_lev)
{
	int sz = str.size();
	string s = str;
	for(int i = 0 ; i < sz ; i++){
		s = str;
		for(char j = 'a' ; j <= 'z' ; j++){
			s[i] = j;
			if(dict.find(s) != dict.end()){
				next_lev.insert(s);
				mp[s].push_back(str);
			}
		}
	}
}

void Solution::output(string& start , string last)
{
	if(last == start){
		reverse(path.begin() , path.end());
		res.push_back(path);
		reverse(path.begin() , path.end());
	}else{
		for(int i = 0 ; i < mp[last].size() ; i++){
			path.push_back(mp[last][i]);
			output(start , mp[last][i]);
			path.pop_back();
		}
	}
}

vector<vector<string> > Solution::findLadders(string start , string end , unordered_set<string>& dict)
{
	mp.clear();
	res.clear();
	path.clear();

	dict.insert(start);
	dict.insert(end);

	unordered_set<string> cur_lev;
	cur_lev.insert(start);
	unordered_set<string> next_lev;
	path.push_back(end);

	while(true){
		for(auto it = cur_lev.begin() ; it != cur_lev.end() ; it++){
			dict.erase(*it);
		}
		for(auto it = cur_lev.begin() ; it != cur_lev.end() ; it++){
			findDict2(*it , dict , next_lev);
		}
		if(next_lev.empty()){
			return res;
		}
		if(next_lev.find(end) != dict.end()){
			output(start , end);
			return res;
		}
		cur_lev.clear();
		cur_lev = next_lev;
		next_lev.clear();
	}
	return res;
}

int main(int argc , char* argv[])
{
	Solution sol;
	string start("hit");
	string end("cog");
	unordered_set<string> wordDict;
	wordDict.insert("hot");
	wordDict.insert("dot");
	wordDict.insert("dog");
	wordDict.insert("lot");
	wordDict.insert("log");

	vector<vector<string> >res;
	res = sol.findLadders(start , end , wordDict);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
