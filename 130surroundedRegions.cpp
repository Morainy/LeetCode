/*
 * =====================================================================================
 *
 *       Filename:  130surroundedRegions.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月31日 16时03分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct point;

class Solution{
	public:
		void solve(vector<vector<char> >& board);
		void explore(point start , vector<vector<char> >& board , vector<vector<char> >& flag);
};

struct point{
	int x;
	int y;
	point(int i , int j):x(i) , y(j){}
};

void Solution::explore(point start , vector<vector<char> >& board , vector<vector<char> >& flag)
{
	stack<point*> stk;
	stk.push(&start);
	while(!stk.empty()){
		point* top = stk.top();
		if(top->x -1 >= 0){
			if(board[top->x-1][top->y] == 'O'){
				if(flag[top->x-1][top->y] == '0'){
					stk.push(new point(top->x-1 , top->y));
					flag[top->x][top->y] = '1';
					board[top->x][top->y] = '#';
					continue;
				}
			}
		}

		if(top->y+1 < board[0].size()){
			if(board[top->x][top->y+1] == 'O'){
				if(flag[top->x][top->y+1] == '0'){
					stk.push(new point(top->x , top->y+1));
					flag[top->x][top->y] = '1';
					board[top->x][top->y] = '#';
					continue;
				}
			}
		}

		if(top->x+1 < board.size()){
			if(board[top->x+1][top->y] == 'O'){
				if(flag[top->x+1][top->y] == '0'){
					stk.push(new point(top->x+1 , top->y));
					flag[top->x][top->y] = '1';
					board[top->x][top->y] = '#';
					continue;
				}
			}
		}

		if(top->y-1 >= 0){
			if(board[top->x][top->y-1] == 'O'){
				if(flag[top->x][top->y-1] == '0'){
					stk.push(new point(top->x , top->y-1));
					flag[top->x][top->y] = '1';
					board[top->x][top->y] = '#';
					continue;
				}
			}
		}

		flag[top->x][top->y] = '1';
		board[top->x][top->y] = '#';
		stk.pop();
	}
}

void Solution::solve(vector<vector<char> >& board)
{
	if(board.size() <= 2){
		return;
	}
	vector<vector<char> > flag;
	//stack<point*> stk;
	for(int i = 0 ; i < board.size() ; i++){
		vector<char> tmp(board[i].size() , '0');
		flag.push_back(tmp);
	}
	for(int i = 0 ; i <board.size() ; i++){
		if(board[i][0] == 'O'){
			point tmp(i , 0);
			explore(tmp , board , flag);
		}
		if(board[i][board[0].size() - 1] == 'O'){
			point tmp(i , board[0].size() -1);
			explore(tmp , board , flag);
		}
	}

	for(int j = 0 ; j < board[0].size() ; j++){
		if(board[0][j] == 'O'){
			point tmp(0 , j);
			explore(tmp , board , flag);
		}
		if(board[board.size() - 1][j] == 'O'){
			point tmp(board.size()-1 , j);
			explore(tmp , board , flag);
		}
	}

	for(int i = 0 ; i < board.size() ; i++){
		for(int j = 0 ; j < board[i].size() ; j++){
			if(board[i][j] == 'O'){
				board[i][j] = 'X';
			}
			if(board[i][j] == '#'){
				board[i][j] = 'O';
			}
		}
	}
}

/*void Solution::solve(vector<vector<char> >& board)
{
	if(board.size() <= 2){
		return;
	}
	//vector<vector<char> > flag(board.size() , vector<char> tmp(board.size() , '0'));
	
	vector<vector<char> > flag;
	stack<point*> s;
	for(int i = 0 ; i < board.size() ; i++){
		vector<char> tmp(board[i].size() , '0');
		flag.push_back(tmp);
	}
	
	for(int i = 1 ; i < board.size()-1 ; i++){
		for(int j = 1 ; j < board[i].size()-1 ; j++){
			if(board[i][j] == 'O' && flag[i][j] == '0'){
				//flag[i][j] = 1;
				s.push(new point(i , j));
				while(!s.empty()){
					point* tmp = s.top();
					if(tmp->x-1 >= 0){
						if(board[tmp->x-1][tmp->y] == 'O'){
							if(flag[tmp->x-1][tmp->y] == '0'){
								s.push(new point(tmp->x-1 , tmp->y));
								flag[tmp->x][tmp->y] = '1';
								continue;
							}
						}
					}else{
						while(!s.empty()){
							point* top = s.top();
							flag[top->x][top->y] = '0';
							s.pop();
						}
						break;
					}
					if(tmp->y+1 < board[i].size()){
						if(board[tmp->x][tmp->y+1] == 'O'){
							if(flag[tmp->x][tmp->y+1] == '0'){
								s.push(new point(tmp->x , tmp->y+1));
								flag[tmp->x][tmp->y] = '1';
								continue;
							}
						}
					}else{
						while(!s.empty()){
							point* top = s.top();
							flag[top->x][top->y] = '0';
							s.pop();
						}
						break;
					}
					if(tmp->x+1 < board.size()){
						if(board[tmp->x+1][tmp->y] == 'O'){
							if(flag[tmp->x+1][tmp->y] == '0'){
								s.push(new point(tmp->x+1 , tmp->y));
								flag[tmp->x][tmp->y] = '1';
								continue;
							}
						}
					}else{
						while(!s.empty()){
							point* top = s.top();
							flag[top->x][top->y] = '0';
							s.pop();
						}
						break;
					}
					if(tmp->y-1 >= 0){
						if(board[tmp->x][tmp->y-1] == 'O'){
							if(flag[tmp->x][tmp->y-1] == '0'){
								s.push(new point(tmp->x , tmp->y-1));
								flag[tmp->x][tmp->y] = '1';
								continue;
							}
						}
					}else{
						while(!s.empty()){
							point* top = s.top();
							flag[top->x][top->y] = '0';
							s.pop();
						}
						break;
					}
					//如果程序进行到这里的话，说明已无路可走
					flag[tmp->x][tmp->y] = '1';
					s.pop();
				}
			}
		}
	}
	for(int m = 0 ; m < board.size() ; m++){
		for(int n = 0 ; n < board[m].size() ; n++){
			if(flag[m][n] == '1' && board[m][n] == 'O'){
				board[m][n] = 'X';
				//flag[m][n] = 0;
			}
		}
	}
}*/

int main(int argc , char* argv[])
{
	vector<vector<char> > board;
	/*vector<char>v1(3 , 'O');
	vector<char>v2(3 , 'O');
	vector<char>v3(3 , 'O');*/


	/*vector<char>v1(4 , 'X');
	vector<char>v2;
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('O');
	v2.push_back('X');

	vector<char> v3;
	v3.push_back('X');
	v3.push_back('X');
	v3.push_back('O');
	v3.push_back('X');

	vector<char> v4;
	v4.push_back('X');
	v4.push_back('O');
	v4.push_back('X');
	v4.push_back('X');*/


	vector<char> v1;
	v1.push_back('X');
	v1.push_back('O');
	v1.push_back('X');
	v1.push_back('O');
	v1.push_back('X');
	v1.push_back('O');

	vector<char> v2;
	v2.push_back('O');
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('X');

	vector<char> v3(v1);
	vector<char> v4(v2);


	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	cout<<"调用函数前："<<endl;
	for(int i = 0 ; i < board.size() ; i++){
		for(int j = 0 ; j < board[i].size() ; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	Solution sol;
	sol.solve(board);
	
	cout<<"调用函数后:"<<endl;
	for(int i = 0 ; i < board.size() ; i++){
		for(int j = 0 ; j < board[i].size() ; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
