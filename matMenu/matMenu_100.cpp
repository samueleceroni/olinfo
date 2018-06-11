#include <fstream>
#include <vector>

#define MAX 5010

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int> > memo (MAX, vector<int>(MAX, 0));
vector<vector<bool> > memo1 (MAX, vector<bool>(MAX, 0));
vector<int> arr;

int n;

int main(){
    int k, temp, tempa, tempb;

    fin >> n;
    fin >> k;

    for (int i = 0; i < n; i++){
        fin >> temp;
        arr.push_back(temp);
    }

    for (int i = n-1; i>=0; i--){
        for (int j = 0; j < k; j++){
            // non prendo
            if (i+1 < n)
                memo[i][j] = memo [i+1][j];
            // provo a prendere
            if (j >= arr[i]){
                tempa = memo[i][j];
                tempb = arr[i] + memo[i+1][j-arr[i]];
                memo [i][j] = max(tempa, tempb);
                if (memo [i][j] == tempb){
                    memo1[i][j] = 1;
                }
            }
        }
    }

    temp = k;

    for (int i = 0; i<n && temp>0; i++){
        if(memo1[i][temp] == 1){
            fout << arr[i] << endl;
            temp = temp-arr[i];
        }
    }
}