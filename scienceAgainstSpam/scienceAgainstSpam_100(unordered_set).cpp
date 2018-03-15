#include <fstream>
#include <unordered_set>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

unordered_set<string> USgood;
unordered_set<string> USbad;

int main(){

    int b, g, e, numWords, good = 0, bad = 0; //bad words, good words, numer of email, temporary number of words
    string wordTemp;

    //INPUT
    fin >> b;

    for (int i=0; i<b; i++){
        fin >> wordTemp;
        USbad.insert(wordTemp);
    }

    fin >> g;


    for (int i=0; i<g; i++){
        fin >> wordTemp;
        USgood.insert(wordTemp);
    }

    b=0;
    g=0;

    fin >> e;

    //OUTPUT

    for (int i=0; i<e; i++){
        fin >> numWords;
        good = 0;
        bad = 0;
        for (int j=0; j<numWords; j++){
            fin >> wordTemp;
            if (USgood.count(wordTemp)>0)
                good=1;
            if (USbad.count(wordTemp)>0)
                bad=1;
        }

        if(bad && !good)
            b++;
        if(good && !bad)
            g++;
    }

    fout << b << ' ' << g;
}