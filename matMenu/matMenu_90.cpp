#include <fstream>
#include <vector>

#define MAX 5010

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int> > memo (MAX, vector<int>(MAX, -1));
vector<vector<bool> > memo1 (MAX, vector<bool>(MAX, 2));
vector<int> arr;

int n;

int createSol(int i, int k){
    int a, b, ret;
    
    if (i == n && k >= 0)
        ret = 0;
    
    else if (i == n || k < 0)
        ret = -10e5;

    else if (memo[i][k] != -1)
        ret = memo[i][k];

    else{
        a = createSol(i+1, k-arr[i])+ arr[i];
        b = createSol(i+1, k);

        ret = a >= b ? a : b;
        
        if(ret == a)
            memo1[i][k] = 1;
        else
            memo1[i][k] = 0;

        memo[i][k] = ret;
    }
    return ret;
}

void printSol(int i, int k){
    if (i<n && k>=0){
        if (memo1[i][k] == 1){
            fout << arr[i] << endl;
            printSol(i+1, k-arr[i]);}
        else
            printSol(i+1, k);
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

    createSol(0, k);
    printSol(0,k);
}