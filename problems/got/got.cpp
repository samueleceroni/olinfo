#include <fstream>
#include <queue>
#include <string.h>
using namespace std;

#define INF 1e9

ifstream fin("input.txt");
ofstream fout("output.txt");


struct state{
	int index;
	int weight;
	int tickets;
	bool operator <(const state& other) {
		return this.weight < other.weight;
	}
}

struct edge{
	int dest;
	int weight;
	bool isBus;
	int people;
}

bool dijkstra(vector<vector<edge> > &graph, int start, int end, int k, int got, int maxDist){

	priorty_queue <state> q;
	int distance [graph.size()][k];
	memset(distance, INF, sizeof(distance));

	q.push({start,0,k});

	while(!q.empty()){
		state currentState = q.top();
		if(currentState.index == end){
			return currentState.distance < maxDist;
		}

		q.pop();
		for (edge currentEdge : graph[currentState.index]){
			if(currentEdge.people <= got){
				if(currentEdge.isBus){
					if(currentState.tickets > 0 &&
						distance[currentEdge.dest][currentState.tickets-1]>currentState.weight+currentEdge.weight){
						distance[currentEdge.dest][currentState.tickets-1] = currentState.weight+currentEdge.weight;
						q.push({currentEdge.dest, currentState.weight+currentEdge.weight,
							currentState.tickets -1});
					}
				} else {
					if(distance[currentEdge.dest][currentState.tickets]>currentState.weight+currentEdge.weight){
						distance[currentEdge.dest][currentState.tickets] = currentState.weight+currentEdge.weight;
						q.push({currentEdge.dest, currentState.weight+currentEdge.weight,
							currentState.tickets});
					}

				}
			}

			
		}
	}

	return false;
}

int binarySearch(int k,vector<vector<edge> > &graph,int s, int e, int t){
	 int a=0, b=INF, m;
	 while(a!=b){
	 	m = (a+b)/2;
	 	if(dijkstra(graph, s,e,k,m,t)){
	 		b=m;
	 	} else { a = m;}
	 }
	 return a;
}


int main(){

	int n, m, k, s, e, t, minResult;

	fin >> n >> m >> k >> s >> e >> t;

	vector <edge> graph[n];

	for (int i=0; i<m; i++){
		int start, end, weightFoot, weightBus, people;
		fin >> start >> end >> weightFoot >> weightBus >> people;
		edge byFoot = {end, weightFoot, false, people};
		edge byBus = {end, weightBus, true, 0};
		edge byFootBack = {start, weightFoot, false, people};
		edge byBusBack = {start, weightBus, true, 0};
		
		graph[start].push_back(byFoot);
		graph[start].push_back(byBus);
		graph[end].push_back(byFootBack);
		graph[end].push_back(byBusBack);
	}

	minResult = binarySearch(k,graph,s,e,t);

}