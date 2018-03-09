/*
Problem
    Poldo can only eat a sandwich whose weight is less of the previous one
    It is given an array of number which stands for the weight of the sandwiches
    Calculate the number of sandwhiches he can eat

Input data
    a sequence of number:
    - the first number is the dim of the array
    - other number form the array of the weight of the sandwiches

Output data
    the number of sandwich that Poldo can eat
*/

#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){

    int n, sol; // dim and temp solution (used later)

    fin >> n;

    vector<int> v(n), dp(n,1); // v is used to store input, dp stores solution for bottom up approach
    
    for (int i=0; i < n; i++)
        fin >> v[i];
    
    for (int i = n-2; i >= 0; i--){
        sol=1;
        for (int j = i+1; j < n; j++ ){     // I try with all the following ones
            if (v[j] < v[i]){               // if the next is smaller than the prev I try to use its solution increased by one
                if(1 + dp[j] > sol)         // if it's bigger than solution i store it in sol variable
                    sol = dp[j] + 1;
            }
        }
        dp[i] = sol;        // store sol in dp[i]
    }

    fout << *max_element(dp.begin(), dp.end());     // return the greater element in the vector
}