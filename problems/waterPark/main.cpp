#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_set>
using namespace std;

vector<double> foundLargestPool(const vector<vector<int> >&g, const vector<int> &topoSorted){
    double quantitySplitted;
    vector<double> sol(g.size());
    sol[0] = 1.0;
    for(int currNode : topoSorted){
        if(g[currNode].size() == 0){continue;}  //isPool
        quantitySplitted = sol[currNode] / (double) g[currNode].size();
        sol[currNode] = 0;
        for(auto nextNode : g[currNode]){
            sol[nextNode] += quantitySplitted;
        }
    }
    return sol;
}

bool visit(int currNode, const vector<vector<int> > & g, vector<int> &sol, vector<int> &marks){
    if(marks[currNode] == 2){return true;}
    if(marks[currNode] == 1){return false;} // not a DAG
    marks[currNode] = 1;
    for(auto nextNode : g[currNode]){
        bool ok = visit(nextNode, g, sol, marks);
        if(!ok){return false;}
    }
    marks[currNode] = 2;
    sol.push_back(currNode);
    return true;
}

vector<int> topoSort(const vector<vector<int> > &g){
    vector<int> marks(g.size(), 0);
    vector<int> sol;
    for(auto nextEl : marks){
        if(!visit(nextEl, g, sol, marks)){return vector<int>();}
    }
    reverse(sol.begin(), sol.end());
    return sol;
}

int main()
 {
    int n, e, p;
    int start, end;
    cin >> n >> e >> p;

    vector<vector<int> > g(n);
    for(int i = 0; i < e; i++){
        cin >> start >> end;
        g[start].push_back(end);
    }
    vector<int> topoSorted = topoSort(g);
    vector<double> sol = foundLargestPool(g, topoSorted);
    int maxPoolInd = n-p;
    for(int i = n - p + 1; i < n; i++){
        maxPoolInd = sol[maxPoolInd] < sol[i] ? i : maxPoolInd;
    }
    cout << maxPoolInd;
    return 0;
}