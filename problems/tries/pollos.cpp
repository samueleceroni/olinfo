#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <map>
#include <iostream>
#include <queue>

#define INF 1e18

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct arco{
	long long int from, to, t;
};

long long int dijkstra(vector<pair<long long int, long long int> > graph[], long long int s, long long int d, long long int n);

int main(){

	long long int n, m, s, d, t;
	map <long long int, vector<arco> > groups;


	fin >> n >> m >> s >> d >> t;

	vector<pair<long long int, long long int> > graph[n];
	long long int temps[n];

	for (long long int i=0; i<n;i++){
		fin >> temps[i];
	}

	for (long long int i=0; i<m; i++){
		long long int a, b, c;
		fin >> a >> b >> c;
		long long int diff = abs(temps[a] - temps[b]);
		groups[diff].push_back({a, b, c});
	}

	for(auto &i : groups){
		for (auto &j : i.second){
			graph[j.from].push_back({j.to, j.t});
			graph[j.to].push_back({j.from, j.t});
		}
		if(dijkstra(graph, s, d, n, t) <= t) { fout << i.first; return 0; }
	}

	fout << -1;
	return 0;

}

long long int dijkstra(vector<pair<long long int, long long int> > graph[], long long int s, long long int d, long long int n, long long int t){
	priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int> >, greater<pair<long long int,long long int> > > heap;
	long long int minDist[n];
	for (long long int i=0; i<n; i++){
		minDist[i] = INF;
	}

	heap.push({0, s});
	minDist[s] = 0;
	while(!heap.empty()){
		auto front = heap.top();
		heap.pop();
		if(front.first > t) return INF;
		if(front.second == d){
			return front.first;
		}
		if( front.first > minDist[front.second]) {continue;}
		for (auto &i : graph[front.second]){
			if(i.second+front.first < minDist[i.first]){
				heap.push({i.second + front.first, i.first});
				minDist[i.first] = i.second+front.first;
			}
		}
	}
	return INF;
}


// long long int dijkstra(vector<pair<long long int, long long int> > graph[], long long int s, long long int d, long long int n){
// 	priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int> >, greater<pair<long long int,long long int> > > heap;
// 	long long int minDist[n];
// 	for (long long int i=0; i<n; i++){
// 		minDist[i] = INF;
// 	}

// 	heap.push({0, s});
// 	minDist[s] = 0;
// 	while(!heap.empty()){
// 		auto front = heap.top();
// 		heap.pop();
// 		if(front.second == d){
// 			return front.first;
// 		}
// 		if( front.first > minDist[front.second]) {continue;}
// 		for (auto &i : graph[front.second]){
// 			if(i.second+front.first < minDist[i.first]){
// 				heap.push({i.second + front.first, i.first});
// 				minDist[i.first] = i.second+front.first;
// 			}
// 		}
// 	}
// 	return INF;
// }