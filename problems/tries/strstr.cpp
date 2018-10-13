#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int strstr(string ,string);
int main()
{
    int t;
    
    fin>>t;
    while(t--)
    {
        string a;
        string b;
        fin>>a;
        fin>>b;
        fout<<strstr(a,b)<<endl;
    }
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
    if(x.length()>s.length()){return -1;}
    int indX=0, prevS,found=0;
    for (int indS=0; indS<s.length(); indS++){
        prevS = indS;
        while(s[indS]==x[indX] && indS<s.length() && indX<x.length()){
            indS++;
            indX++;
        }
        if(indX==x.length()){
            found = 1;
            break;
        } else{
            indS = prevS;
            indX = 0;
        }
    }

    if(found){
        return prevS;
    } else {
        return -1;
    }
}