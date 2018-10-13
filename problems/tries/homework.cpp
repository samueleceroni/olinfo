#include <vector>
#include <cmath>
#include <fstream>
//#include <algorithm>
#include <map>
#include <unordered_set>
//#include <iostream>
//#include <queue>

#define INF 1e18
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector <int> primes;
map <int,int> mapSolution;
unordered_set <int> checkedNumbers;

void findmapSolution(int currentNumber){
	map <int,int> currentmapSolution;
	if (currentNumber == 1) {return;}
	if (checkedNumbers.find(currentNumber)!=checkedNumbers.end()) {return;}
	checkedNumbers.insert(currentNumber);
	int i = 0;
	while (currentNumber != 1 && i<primes.size()){
		if (currentNumber % primes[i] == 0){
			currentmapSolution[primes[i]]++;
			if (currentmapSolution[primes[i]] > mapSolution[primes[i]]) {
				mapSolution[primes[i]] = currentmapSolution[primes[i]];
			}
			currentNumber /= primes[i];
		}
		else {
			i++;
		}		
	}
}

int findNextPrime(int n);   //given a number n, find the next closest prime number above n
bool isPrime(int n);        //given a number n, determine if it is prime

//given a number n, find the next closest prime number above n
int findNextPrime(int n)
{
    int nextPrime = n;
    bool found = false;

    //loop continuously until isPrime returns true for a number above n
    while (!found)
    {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}

//given a number n, determine if it is prime
bool isPrime(int n)
{
    //loop from 2 to n/2 to check for factors
    int sqN = sqrt(n);
    for (int i = 2; i <= sqN; i++)
    {
        if (n % i == 0)     //found a factor that isn't 1 or n, therefore not prime
            return false;
    }

    return true;
}

void fillPrimes(int maxPrime){
	int i = 1, nextI;
	while(i<maxPrime){
		nextI = findNextPrime(i);
		primes.push_back(nextI);
		i = nextI;
	}
}

int main(){
	fillPrimes(1e6);

	int n, currentNumber;
	
	fin >> n;

	for (int i = 0; i<n; i++){
		fin >> currentNumber;
		findmapSolution(currentNumber);
	}

	vector<int>solution;
	for(auto x:mapSolution){
		for (int i=0; i<x.second; i++)
			solution.push_back(x.first);
	}
	fout << solution.size()<<endl;
	for(int i = 0; i<solution.size(); i++){
		fout << solution[i] << ' ';
	}

}

