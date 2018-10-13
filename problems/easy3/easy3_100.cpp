#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    int sol = -1, n, max_odd=-1, sec_odd=-1, max_eve=-1, sec_eve=-1, eve_max_sum = -1, odd_max_sum = -1;
    
    fin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        fin >> v[i];

    for (int i = 0; i < n; i++){
        if (v[i] % 2){              // odd case
            if (v[i] > sec_odd){
                if (v[i] > max_odd){
                    sec_odd = max_odd;
                    max_odd = v[i];
                }
                else{
                    sec_odd = v[i];
                }
            }
        }
        else{                       // even case
            if (v[i] > sec_eve){
                if (v[i] > max_eve){
                    sec_eve = max_eve;
                    max_eve = v[i];
                }
                else{
                    sec_eve = v[i];
                }
            }

        }          
    }

    if(max_eve!=-1 && sec_eve != -1)
        eve_max_sum = max_eve + sec_eve;
    if(max_odd!=-1 && sec_odd != -1)
        odd_max_sum = max_odd + sec_odd;

    if (eve_max_sum != -1 || odd_max_sum != -1)
        sol = max(eve_max_sum, odd_max_sum);
    fout << sol;
}