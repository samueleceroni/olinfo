#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int main(){
    long long int n, sol;
    fin >> n;
    if (n%2){   // odd case
        sol = (((n+1)/2)+1)*(((n-1)/2)+1);
    }
    else{       // even case
        sol = ((n/2)+1)*((n/2)+1);
    }
    fout << sol;
}