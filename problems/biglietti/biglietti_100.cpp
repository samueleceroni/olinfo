#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main (){
    float n, m, a, b;       //n_travels, carnet_n_travels, single_price, carnet_price
    int sol=0;

    fin >> n >> m >> a >> b;

    if (a < b/m)
        sol = a * n;
    else{
        while (n > m){
            sol += b;
            n -= m;
        }
        if (n*a < b)
            sol += n*a;
        else
            sol += b; 
    }

    fout << sol;


}