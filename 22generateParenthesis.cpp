/*
 * =====================================================================================
 *
 *       Filename:  22generateParenthesis.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月08日 09时14分41秒
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
using namespace std;

class Solution{
	public:
		vector<string> generateParenthesis(int n);
		void generate(int n , string s , int lnum , int rnum , vector<string>& res);
};

vector<string> Solution::generateParenthesis(int n)
{	
	vector<string> res;
	if(n>0){
		generate(n , "" , 0 , 0 , res);
	}
	return res;
}

void Solution::generate(int n , string s , int lnum , int rnum , vector<string>& res)
{
	if(lnum == n){
		res.push_back(s.append(n - rnum , ')'));
		return;
	}
	generate(n , s+"(" , lnum+1 , rnum , res);
	if(lnum>rnum){
		generate(n , s+")" , lnum , rnum+1 , res);
	}

}
int main(int argc ,char * argv[])
{
	Solution sol;
	vector<string> res;
	res = sol.generateParenthesis(4);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<endl;
	}
	cout<<"res.size() = "<<res.size()<<endl;
}
