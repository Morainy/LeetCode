/*
 * =====================================================================================
 *
 *       Filename:  133cloneGraph.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月09日 10时15分44秒
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
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x):label(x){}
};

class Solution{
	public:
		UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node);
};

UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode* node)
{
	if(!node){
		return NULL;
	}
	queue<UndirectedGraphNode*> q;
	map<int , UndirectedGraphNode*> nodes;

	q.push(node);
	while(!q.empty()){
		UndirectedGraphNode* tmp = q.front();
		q.pop();
		if(nodes.find(tmp->label) == nodes.end()){
			UndirectedGraphNode* new_node = new UndirectedGraphNode(tmp->label);
			nodes[tmp->label] = new_node;
			for(int i = 0 ; i < tmp->neighbors.size() ; i++){
				q.push(tmp->neighbors[i]);
			}
		}
	}

	
	q.push(node);
	while(!q.empty()){
		UndirectedGraphNode* tmp = q.front();
		q.pop();
		UndirectedGraphNode* exiting = nodes[tmp->label];
		if( exiting->neighbors.empty() && !tmp->neighbors.empty()){
			for(int i = 0 ; i < tmp->neighbors.size() ; i++){
				exiting->neighbors.push_back(nodes[tmp->neighbors[i]->label]);
				q.push(tmp->neighbors[i]);
			}
		}
	}
	return nodes[node->label];
}

int main(int argc , char* argv[])
{

}
