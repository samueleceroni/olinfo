#include <fstream>
#include <vector>

#define MAX 1e9

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int distruggi(vector<int> &v, int first, int last){
    int sol=0;
    for (int i = first; i <= last; i++)
        sol += v[i];
    return sol;
}

int main(){

    int n, temp, costomin;

    fin >> n;
    n++;

    vector<int> alt(n), cos(n), dp(n);

    alt[0] = MAX;
    cos[0] = MAX;
    dp[0] = MAX;

    for (int i=1; i<n; i++)
        fin >> alt[i] >> cos[i];

    for (int i = n-1; i >= 0; i--){
        
        costomin = MAX;

        for (int j = i+1; j < n; j++){
            if(alt[i] > alt[j]){
                temp = dp[j] + distruggi(cos, i+1, j-1);
                if (temp < costomin)
                    costomin = temp;
            }
        }

        if (costomin == MAX)
            costomin = distruggi(cos, i+1, n-1);

        dp[i] = costomin;
    }

    fout << dp[0];
}