#include<iostream>
#include<vector>
using namespace std;
int main()
 {
  int t;
  cin >> t;
  while(t--){
     int n;
     cin >> n;
     vector<int>num(n);
     for(int i=0; i<n;i++){
         cin >> num[i];
     }
     int minInd=0, maxInd=-1, currSum = 0, maxSum=num[0];
     while(maxInd < n-1){
         maxInd++;
         currSum += num[maxInd];
         if(currSum > maxSum){maxSum = currSum;}
         if(currSum < 0){
             currSum = 0;
             minInd = maxInd+1;
         }
     }
     cout << maxSum<<endl;
     
  }
  return 0;
}