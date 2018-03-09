#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

#define MAXT 1e4
#define INF 5*1e7
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int costoDistruzione(vector<int> &v, int first, int last){
    int sol=0;
    for(int i=first; i<=last; i++)
        sol += v[i];
    return sol;
}

int main(){
    //leggo N
    int n, costomin, temp;
    fin >> n;
    n++;
    vector<int> altezza (n), costo(n), dp(n, -1); //dichiaro un vettore di interi di grandezza n

    altezza[0] = MAXT;
    costo[0] = MAXT;

    for(int i = 1; i < n; i++)
        fin >> altezza[i] >> costo[i]; //inizializzo i valori

    for (int i = n - 1; i >= 0; i--){
        costomin = INF;
        for (int j = i + 1; j < n; j++){
            temp = 0;
            if(altezza[i]>altezza[j]){
                temp = dp[j] + costoDistruzione(costo, i+1, j-1);
                if(temp < costomin)
                    costomin = temp;
            }
        }
        if(costomin == INF)
            costomin = costoDistruzione(costo,i+1,n-1);

        dp[i] = costomin;
    }

    fout<<dp[0];

    return 0;
}
