#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int board(int tempNumber, int* firstFree, vector<int>&train){
	int tempSol=0;
	if (tempNumber>=*firstFree){// a priority queue is useful in order to keep saved the smaller free

		while(train[(*firstFree)] != -1){
			(*firstFree)++;
		}

		train[(*firstFree)]=tempNumber;

		(*firstFree)++;

		while(train[(*firstFree)] != -1){
			(*firstFree)++;
		}
	}
	else{
		tempSol+=1;
		if (train[tempNumber]!=-1)
			tempSol+=board(train[tempNumber], firstFree, train);
		train[tempNumber]=tempNumber;
	}
	return tempSol;
}

void leaveTrain(int tempNumber, int* firstFree, vector<int>&train){ // Not good. I have to free the position occupied by the person which has the reservetion for tempNumber! An unordered_map is useful
	if (tempNumber<*firstFree){
		(*firstFree)=tempNumber;
		train[(*firstFree)]=-1;
	}
}


int main(){
	int n, q, firstFree=0, sol = 0;
	char tempAction;
	int tempNumber;
	fin >> n >> q;
	vector<int>train(n, -1);
	for (int i=0; i<n; i++){
		fin >> tempAction >> tempNumber;
		if (tempAction=='b'){
			sol+=board(tempNumber, &firstFree, train);
		}
		else leaveTrain(tempNumber, &firstFree, train);
	}
	fout << sol;
	return 0;
}