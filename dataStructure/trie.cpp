#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct dicTrieSaveSpace {
    private:
    // declaration of internal structures needed
    	unordered_map <char, dicTrieSaveSpace*> nextLetter;
    	string currentWord;
    public:
	// declaration of constructor functions
    	dicTrieSaveSpace(){}
    	dicTrieSaveSpace(vector<string> &newStrings){
    		for(auto currentString : newStrings){
    			insWord(currentString);
    		}
    	}
    	dicTrieSaveSpace(string oneString){
    		insWord(oneString);
    	}
    private:
    // declaration of internal functions, not publicly available
    	string firstLetters(string & wholeWord, int lastIndex){
    		string newPartWord;
    		for(int i=0; i<=lastIndex; i++){
    			newPartWord.push_back(wholeWord[i]);
    		}
    		return newPartWord;
    	}
    public:
    // declaration of external functions, publicly available
    	void insWord(string &newWord){
    		dicTrieSaveSpace *currentTrie = this;
    		for(char c : newWord){
    			if(currentTrie->nextLetter.count(c) == 0){
    				currentTrie->nextLetter[c] = new dicTrieSaveSpace();
    			}
    			currentTrie = currentTrie->nextLetter[c];
    		}
    	}

    	bool searchWord(string wordToFind){
    		dicTrieSaveSpace *currentTrie = this;
    		bool found = true;
    		for(char c : wordToFind){
    			if (currentTrie->nextLetter.count(c)){
    				currentTrie = currentTrie->nextLetter[c];
    			} else { return false;}
    		}
    		return true;
    	}
};
