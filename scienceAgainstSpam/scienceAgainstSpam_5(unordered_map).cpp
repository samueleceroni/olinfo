#include <fstream>
#include <vector>
#include <unordered_map>
//#include <unordered_set>
//#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

unordered_map <string, int> UM;
//unordered_set<string> US;

int main(){

    int b, g, e, numWords, sol; //bad words, good words, numer of email 
    string wordTemp;

    //INPUT
    fin >> b;

    for (int i=0; i<b; i++){
        fin >> wordTemp;
        UM[wordTemp] = -1;
    }

    fin >> g;

    for (int i=0; i<g; i++){
        fin >> wordTemp;
        if(UM[wordTemp]==-1)
            UM[wordTemp]=2;
        else
            UM[wordTemp] = 1;
    }

    b=0;
    g=0;

    int good = 0, bad = 0;

    fin >> e;

    //OUTPUT

    for (int i=0; i<e; i++){
        fin >> numWords;
        good = 0;
        bad = 0;
        for (int j=0; j<numWords; j++){
            fin >> wordTemp;
            if(UM.count(wordTemp)){
                if (UM[wordTemp]==2){
                    bad=1;
                    good=1;
                    break;
                }
                if(UM[wordTemp]==-1)
                    bad = 1;
                else
                    good = 1;
            }
        }

        if(bad && !good)
            b++;
        if(good && !bad)
            g++;
    }

    fout << b << ' ' << g;
}