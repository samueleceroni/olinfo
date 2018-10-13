// not tested, trusting FILIPPOS
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct edge {
	int to, weight;
};

void dfs(vector < vector < edge > > &graph, vector <int> &longestSubBranch, vector <int> &longestSubTrip){
	int currentNode;
	stack <int> toVisit;
	toVisit.push(0);
	while(!toVisit.empty()){
		currentNode = toVisit.top();
		longestSubBranch[currentNode] = -1; // visited
		longestSubTrip[currentNode] = -1;
		int maxSubBranch = 0, maxSecondSubBranch = 0, allVisited = 1;
		// se sono tutti >= 0 calcolo max subbranch e secondMaxSubBranch
		for(auto x:graph[currentNode]){
			if(longestSubBranch[x.to]<-1){allVisited=0;}
			if(longestSubBranch[x.to] == -2 && longestSubTrip[x.to] == -2){ // not visited yet
				toVisit.push(x.to);
			}
		}

		if(allVisited){
			for(auto x:graph[currentNode]){
				if(longestSubBranch[x.to] >=0 && longestSubBranch[x.to] + x.weight > maxSubBranch){
					maxSecondSubBranch = maxSubBranch;
					maxSubBranch = longestSubBranch[x.to] + x.weight;
				}
			}
			longestSubBranch[currentNode] = maxSubBranch;
			longestSubTrip[currentNode] = maxSubBranch + maxSecondSubBranch;
			toVisit.pop();
		}

	}
}


int main(){

	int n, from, to, weight, totalWeight=0;
	edge edgeToGo, edgeToReturn;

	fin>>n;
	vector < vector < edge > > graph(n);
	vector <int> longestSubBranch(n,-2), longestSubTrip(n,-2);

	for (int i=0; i < n-1; i++){
		fin >> from >> to >> weight;
		edgeToGo.to = to;
		edgeToGo.weight = weight;
		edgeToReturn.to = from;
		edgeToReturn.weight = weight;
		graph[from].push_back(edgeToGo);
		graph[to].push_back(edgeToReturn);
		totalWeight += weight;
	}

	int max = 0;
	dfs(graph, longestSubBranch, longestSubTrip);

	for (int i=0; i<n; i++){
		if (longestSubTrip[i]>max){max = longestSubTrip[i];}
	}



	fout << (totalWeight*2 - max);

}