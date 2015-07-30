/*
 * =====================================================================================
 *
 *       Filename:  127ladderLength.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月28日 08时49分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>
#include <vector>
//#include <limits>
using namespace std;

/*class Solution{
	public:
		int ladderLength(string beginWord , string endWord , unordered_set<string>& wordDict);
		bool editDistance(string &word1 , string &word2);
};

//判断两个单词之间的编辑距离是否为1
bool Solution::editDistance(string &word1 , string &word2)
{
	if(word1.length() != word2.length()){
		return false;
	}
	int distance = 0;
	for(int i = 0 ; i < word1.length() ; i++){
		if(word1[i] != word2[i]){
			distance++;
		}
		if(distance > 1){
			return false;
		}
	}
	if(distance == 1){
		return true;
	}else{
		return false;
	}
}
int Solution::ladderLength(string beginWord , string endWord , unordered_set<string>& wordDict)
{
	int setSize = wordDict.size();
	if(setSize < 1){
		return 0;
	}
	int matrixSize = setSize + 2;
	//以1024表示无穷大
	vector<vector<int> > matrix(matrixSize , vector<int>(matrixSize , 1024));
	vector<string> words;
	words.push_back(beginWord);
	unordered_set<string>::iterator it;
	for(it = wordDict.begin() ; it != wordDict.end() ; it++){
		words.push_back(*it);
	}
	words.push_back(endWord);

	//下面构建以单词为节点的图的邻接矩阵
	for(int i = 0 ; i < words.size() ; i++){
		for(int j = 0 ; j < words.size() ; j++){
			if(editDistance(words[i] , words[j])){
				matrix[i][j] = 1;
			}
		}
	}

	//调试信息   打印matrix矩阵的值
	cout<<"matrix:"<<endl;
	for(int i = 0 ; i < matrixSize ; i++){
		for(int j = 0 ; j < matrixSize; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	

	//有了邻接矩阵之后，应用floyd算法找出最短路径；
	//若没有这样的一条路径则返回0
	//vector<vector<int> > path(matrixSize , vector<int>(matrixSize , -1));
	Time limit Exceeded!!!
	for(int k = 0 ; k < matrixSize ; k++){
		for(int i = 0 ; i < matrixSize ; i++){
			for(int j = 0 ; j < matrixSize ; j++){
				if(i == j){
					continue;
				}
				if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
					matrix[i][j] = matrix[i][k]+matrix[k][j];
					//path[i][j] = k;
				}
			}
		}
	}

	//下面应用迪杰斯特拉算法进行计算
	vector<int> flag(matrixSize , 0);
	flag[0] = 1;
	//vector<int> dis(matrix[0]);
	int min , minIndex;
	for(int i = 0 ; i < matrixSize ; i++){
		min = 1025;
		for(int j = 0 ; j < matrixSize ; j++){
			if(flag[j] == 0 && matrix[0][j] < min){
				min = matrix[0][j];
				minIndex = j;
			}
		}
		flag[minIndex] = 1;
		for(int j = 0 ; j < matrixSize ; j++){
			if(matrix[minIndex][j] < 1024){
				if(matrix[0][j] > matrix[0][minIndex]+matrix[minIndex][j]){
					matrix[0][j] = matrix[0][minIndex] + matrix[minIndex][j];
				}
			}
		}
	}


	//调试信息：应用最短路径算法之后的矩阵
	cout<<"应用最短路径算法之后的邻接矩阵:"<<endl;
	for(int i = 0 ; i < matrixSize ; i++){
		for(int j = 0 ; j < matrixSize; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	if(matrix[0][matrixSize-1] == 1024){
		return 0;
	}else{
		return matrix[0][matrixSize-1] + 1;
	}
}*/

/**********************************************************************
 *下面这个方法会有bug
 *********************************************************************/
/*class Solution{
	public:
		int ladderLength(string start , string end , unordered_set<string>& dict);
};

int Solution::ladderLength(string start , string end , unordered_set<string>& dict)
{
	if(start.length() != end.length()){
		return 0;
	}
	if(start.empty() || end.empty()){
		return 1;
	}
	if(dict.size() == 0){
		return 0;
	}
	int res = 1;
	queue<string> q1 , q2;
	q1.push(start);
	while(dict.size() > 0 && !q1.empty()){
		while(!q1.empty()){
			string str(q1.front());
			q1.pop();
			int strLen = str.length();
			for(int i = 0 ; i < strLen ; i++){
				char tmp = str[i];
				for(char j = 'a' ; j <= 'z' ; j++){
					if(j == tmp){
						continue;
					}
					str[i] = j;
					if(str == end){
						return res + 1;
					}
					if(dict.find(str) != dict.end()){
						q2.push(str);
						dict.erase(str);
					}
				}
				str[i] = tmp;
			}
		}
		swap(q1 , q2);
		res++;
	}
	return 0;
}*/

class Solution{
	public:
		int ladderLength(string start , string end , unordered_set<string>& dict);
};

int Solution::ladderLength(string start , string end , unordered_set<string>& dict)
{
	if(start.length() != end.length()){
		return 0;
	}
	if(start.empty() || end.empty()){
		return 1;
	}
	if(dict.size() == 0){
		return 0;
	}

	int res = 1;
	queue<string> q;
	q.push(start);
	q.push("");
	while(!q.empty()){
		string str(q.front());
		q.pop();
		if(str != ""){
			for(int i = 0 ; i < str.length() ; i++){
				char tmp = str[i];
				for(char j = 'a' ; j <= 'z'; j++){
					if(j == tmp){
						continue;
					}
					str[i] = j;
					if(str == end){
						return res + 1;
					}
					if(dict.find(str) != dict.end()){
						q.push(str);
						dict.erase(str);
					}
				}
				str[i] = tmp;
			}
		}
		else if(!q.empty()){
			res++;
			q.push("");
		}
	}
	return 0;
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
	
	int res = sol.ladderLength(start , end , wordDict);
	cout<<"res = "<<res<<endl;
}

