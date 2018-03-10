#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){

    int n, m, k, prev = 0, temp = 0, sol = 0, var;        // number of filling station, kilometres with full tank, trip lenght

    fin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        
        fin >> var;
        
        if (var > m + temp){
            sol++;
            temp = prev;
        }
        prev = var;
    }

    if (k > m + temp){
        sol++;
    }

    fout << sol;
}