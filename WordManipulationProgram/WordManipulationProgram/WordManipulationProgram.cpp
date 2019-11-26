// WordManipulationProgram.cpp 
// This word manipulation program will take a word or sentence, check if any are palindromes, count
// the number of words and reverses the word or words if they aren't. It then prints all this
// information out to the console
// By: Henry Sagehorn

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> wordList;

string sentenceReader(string sentence) {
	
	string temp = "";
	for (int i = 0; i < sentence.size(); i++) {
		if (sentence[i] != ' ') {
			temp += sentence[i];
		}
		else if(sentence[i]==' '){
			wordList.push_back(temp);
			temp = "";
		}
		
	}
	if (temp != "") {
		wordList.push_back(temp);
		temp = "";
	}
	return sentence;
}

bool palindromeChecker(string word) {
	int start = 0, end = word.length() - 1;
	while (start < end) {
		if (word[start++] != word[end--])
			return false;
	}
	return true;
}

string wordReverse(string word) {
	int start = 0, end = word.length() - 1;
	string temp = "";
	for (int i = end; i >= start; i--) {
			temp += word[i];
	}
	return temp;
}


int main()
{
	bool flag = true;
	

	while (flag) {
		string entry="";
		string finalOutput;
		int counter=0;

		cout << "Enter a word to be checked: ";

		getline(cin, entry);

		sentenceReader(entry);

		
		for each (string var in wordList)
		{
			palindromeChecker(var);

			if (palindromeChecker(var) == true) {
				counter++;
			}
			else {
				string tempReverse = wordReverse(var) + " ";
				finalOutput += tempReverse;
				continue;
			}
		}
		string counterString = to_string(counter);
		string outPut = "You had " + counterString;
		outPut += " palindromes";

		string numberOfWords = to_string(wordList.size());

		string outPutTwo = "There were " + numberOfWords;
		outPutTwo += " words in this sentence.";

		string outPutThree = "This is the reversed sentence without the palindromes: ";
		outPutThree += finalOutput;

		cout << outPut << endl;
		cout << outPutTwo << endl;
		cout << outPutThree << endl;


		string choice;

		cout << "Enter Y to continue or any key to exit. ";
		getline(cin, choice);

		
		if (choice == "Y" || choice == "y") {
			flag = true;
			wordList.clear();
		}
		else {
			flag = false;
		}

	}
    return 0;
}

