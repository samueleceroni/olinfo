#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int main(){
    priority_queue<int, vector<int>, greater<int> > PQ;

    int n, temp, temp2, sum, costo = 0;

    fin >> n;

    for (int i=0; i<n; i++){
        fin >> temp;
        PQ.push(temp);
    }

    while(PQ.size()>1){
        temp=PQ.top();
        PQ.pop();
        temp2=PQ.top();
        PQ.pop();
        costo+=(temp+temp2);
        sum=(temp+temp2);
        PQ.push(sum);

    }

    fout << costo;
    
    return 0;
}