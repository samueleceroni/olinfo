#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>

//#include <algorithm>
#include <map>
#include <unordered_set>
//#include <iostream>
//#include <queue>

#define INF 1e18
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


using namespace std;
//Segment tree per range-sum su liste di interi con point update.
struct MaxSegmentTree {
    private:
    vector<int> v; // vettore che contiene l'albero
    vector<int> u; // vettore di update
    int n; //numero nodi interni
    const int NULL_VALUE = 0; //zero dell'operazione
    public:
    MaxSegmentTree(int num) {
        v.resize((1 << (int)(ceil(log2(num))+1))-1, NULL_VALUE);//completo bilanciato
        u.resize(v.size(), NULL_VALUE);
        n = v.size() / 2;
    }

    MaxSegmentTree(vector<int> &source) {
        v.resize((1 << (int)(ceil(log2(source.size()))+1))-1, NULL_VALUE);//completo bilanciatoų
        u.resize(v.size(), NULL_VALUE);
        n = v.size() / 2;
        for (int i = 0; i < source.size(); i++) {
            v[i + n] = source[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            updateNode(i);
        }
    }
    private:
    int left(int i) {
        return i*2+1;
    }

    int right(int i) {
        return i*2+2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int mergeValues(int v1, int v2) {
        return v1>v2?v1:v2;
    }

    void updateNode(int i) {
        v[i] = mergeValues(v[left(i)], v[right(i)]);
    }

    void lazyUpdate(int i) {
        if (u[i] != 0) {
            v[i] += u[i];
            if (i < v.size() / 2) {
                u[left(i)] += u[i];
                u[right(i)] += u[i];
            }
            u[i] = 0;
        }
    }

    int rangeQuery(int i, int l, int r, int a, int b) {
        lazyUpdate(i); //Aggiornamento in lettura

        if (l >= a && r <= b) {
            return v[i];
        }
        if (r < a || l > b) {
            return NULL_VALUE;
        }
        int m = (l + r) / 2;
        return mergeValues(rangeQuery(left(i), l, m, a, b), rangeQuery(right(i), m + 1, r, a, b));
    }

    void updateToRoot(int i) {
        updateNode(i);
        if (i != 0) {
            updateToRoot(parent(i));
        }
    }

    void rangeAdd(int i, int a, int b, int l, int r, int off) {
        lazyUpdate(i);

        if (l >= a && r <= b) {
            u[i] += off;
            lazyUpdate(i);

        } else if (!(r < a || l > b)) { //overlap parziale
            int m = (l + r) / 2;
            rangeAdd(left(i), a, b, l , m, off);
            rangeAdd(right(i), a, b, m + 1, r, off);
            updateNode(i);
        }
    }
    int rangeGetMaxIndex(int me, int l, int r){
        lazyUpdate(me);
        if(l==r){return l;}
        int m = (l + r) / 2;
        if(v[me] == v[left(me)]) {
            return rangeGetMaxIndex(left(me), l, m);
        }
        else {
            return rangeGetMaxIndex(right(me), m, r);
        }
    }


    public:

    int getMaxIndex(){
        return rangeGetMaxIndex(0, 0, n);
    }

    int rangeMax(int a, int b) {
        return rangeQuery(0, 0, n, a, b);
    }

    void update(int index, int value) {
        int i = n + index;
        v[i] = value;
        updateToRoot(parent(i));
    }

    void rangeUpdate(int a, int b, int offset) {
        rangeAdd(0, a, b, 0, n, offset);
    }

    void print() {
        int i = 0;
        int livNum = 1;
        while (i < v.size()) {
            for (int j = 0; j < livNum; j++) {
                cout << v[i] << "(" << u[i] << ")" << " ";
                i++;
            }
            livNum *= 2;
            cout << "\n";
        }
    }
};

int main() { // main di test della struttura
    
    int n;
    vector < pair <int,int> > powerUnits;
    int spaceShipSize=0;
    int killedPowerUnits=0;

    fin >> n; // number of powerUnits

    for (int i = 0; i < n; i++){
        pair <int,int> newPowerUnit;
        fin >> newPowerUnit.first >> newPowerUnit.second;
        if (newPowerUnit.second>spaceShipSize){
            spaceShipSize = newPowerUnit.second;
        }
        powerUnits.push_back(newPowerUnit);
    }

    vector <int> spaceShip(spaceShipSize,0);

    MaxSegmentTree segSpaceShip(spaceShip);
    
    //segSpaceShip.print();

    for(auto x : powerUnits){
        segSpaceShip.rangeUpdate(x.first, x.second, 1);

    }
    segSpaceShip.print();

    int maxIndex = segSpaceShip.getMaxIndex();
    fout << maxIndex; // firstShot

    for(auto x : powerUnits){
        if(x.first <= maxIndex && x.second >= maxIndex){
            segSpaceShip.rangeUpdate(x.first, x.second, -1);
            killedPowerUnits++;
        }
    }

    maxIndex = segSpaceShip.getMaxIndex();
    fout << maxIndex; // secondShot
    
    return 0;
}
