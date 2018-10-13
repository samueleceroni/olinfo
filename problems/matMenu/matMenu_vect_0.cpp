#include <fstream>
#include <algorithm>
#include <vector>

#define MAX 5010

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

//Doesn't work, i still have to check why
//vector<vector<pair <int, vector <int> > > > memo (MAX, vector<pair<int, vector<int> > > (MAX, (-1,(0) ) ) );
vector<vector<pair <int, vector <int> > > > memo (MAX, vector<pair<int, vector<int> > >(MAX, pair<int, vector<int>>(-1, vector<int>(0,0) ) ) );
vector<int> arr;

int n;

pair<int,vector<int> > findMenu(int i, int k){
    int temp;
    pair<int, vector<int> > a, b, ret;
    if (i == n && k > 0){
        ret.first = 10e5;
    }
    else if (i == n || k <= 0)
        ret.first = 0;
    else if (memo[i][k].first != -1){
        ret = memo[i][k];
    }
    else{
        a = findMenu(i+1, k-arr[i]);
        a.first += arr[i];
        b = findMenu(i+1, k);
        // memo[i][k] = min(a.first, b.first);
        ret = a.first < b.first ? a : b;
        if(ret.first == a.first){
            ret.second.insert(ret.second.end(), a.second.begin(), a.second.end());
            ret.second.push_back(arr[i]);
        }
        else
            ret.second.insert(ret.second.end(), b.second.begin(), b.second.end());

        memo[i][k] = ret;
    }
    return ret;
}

int main(){
    int k, temp;
    pair<int, vector<int> > ret;

    fin >> n;
    fin >> k;

    for (int i = 0; i < n; i++){
        fin >> temp;
        arr.push_back(temp);
    }

    ret = findMenu(0, k);
    fout << ret.first << endl;
    for(int i=0; i<ret.second.size(); i++){
        fout << ret.second[i] << '\t';
    }
}