#include <fstream>
#include <algorithm>
#include <vector>

#define MAX 5010

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int> > memo (MAX, vector<int>(MAX, -1));
vector<int> arr;
int n;

int felicitaNonna(int i, int k){
    if (i == n && k > 0)
        return 10e5;
    else if (i == n || k <= 0)
        return 0;
    else if (memo[i][k] != -1)
        return memo[i][k];
    else{
        memo[i][k] = min(felicitaNonna(i+1, k-arr[i]) + arr[i], felicitaNonna(i+1, k));
        return memo[i][k];
    }
}

int main(){
    int k, temp;

    fin >> n;
    fin >> k;

    for (int i = 0; i < n; i++){
        fin >> temp;
        arr.push_back(temp);
    }

    fout << felicitaNonna(0, k);
}