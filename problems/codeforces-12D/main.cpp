#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <map>
#include <iostream>

#define INF 10e8

using namespace std;

// ifstream fin("input.txt");
// ofstream fout("output.txt");

struct lady{
	int x;
	int y;
	int z;
};

void compression (vector<lady> &arr){
	map <int, int> m;
	int cont=0;
	// populate the map
	for(auto &i : arr) m[i.y]=0;
	//init the map
	for (auto &i : m){
		i.second = cont;
		cont++;
	}
	//convert the array
	for(auto &i : arr) i.y = m[i.y];
}

bool checkForwardIfGreater(vector<int> arr, int index, int value){
	for (int i = index; i<arr.size(); i++){
		if (arr[i] > value)
			return true;
	}
	return false;
}


int main(){
	cin.tie(0), cin.sync_with_stdio(0);
	int n, sol=0;


	cin >> n;
	vector <lady> arr(n);
	for(auto &i : arr) cin >> i.x;
	for(auto &i : arr) cin >> i.y;
	for(auto &i : arr) cin >> i.z;

	sort(arr.begin(), arr.end(), [](lady a, lady b){
		if(a.x == b.x){
			if(a.y == b.y)
				return a.z < b.z;
			return a.y < b.y;
		}
		return a.x > b.x;
	});
	
	compression (arr);

	vector <int> arrSup (n, -INF);

	for (auto &i : arr){
		//change with rmq
		if(checkForwardIfGreater(arrSup, i.y+1, i.z)){ // pos, val
			sol++;
		}
		else{
			if(arrSup[i.y] < i.z){
				arrSup[i.y] = i.z;
				//add update pos tree
			}
		}
	}
	
	cout << sol;
}