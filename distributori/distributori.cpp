#include <fstream>
//#include <algorithm>
//#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

//  1   31  45  50  80

int main(){
    int n, m, k, prev = 0, temp = 0, sol = 0, var;        // number of filling station, kilometres with full tank, trip lenght

    fin >> n >> m >> k;
    /*
    vector<int> v(n);

    for (int i=0; i<n; i++)
        fin >> v[i];
    n++;
    v[n-1] = k;
    */

    for(int i=0; i<n; i++){
        fin >> var;
        if (var > m + temp){
            sol++;
            temp=prev;
        }
        prev = var;
    }

    if (k > m + temp){
        sol++;
    }
    prev = var;



    fout << sol;

}