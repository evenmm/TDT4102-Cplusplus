#include "CourseCatalog.h"
#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <utility>
//#include <ctime>
#include <algorithm>
#include <sstream>
using namespace std;

void writeToFile() {
	ofstream outStream;
	outStream.open("outFile.txt"); //Kobler outStream til ei fil
	cout << "Skriv inn ord som lagres til fil, ett om gangen\n"
		<< "skriv quit for å avslutte" << endl;
	string word = "";
	cin >> word;
	while (word != "quit") {
		outStream << word << "\n";
		cin >> word;
	}
	outStream.close();
}
void readFile() {
	ifstream inStream("outFile.txt");
	if (inStream.fail()) {
		cout << "Åpning feilet. Bryter funksjonen" << endl;
		return;
	}
	inStream.close();
}
void readAndCreateCopy() {
	ifstream inStream("outFile.txt");
	if (inStream.fail()) {
		cout << "Åpning feilet. Bryter funksjonen" << endl;
		return;
	}
	ofstream outStream("newFile.txt");
	string tempString = "";
	int i = 1;
	while (getline(inStream, tempString)) {
		outStream << i << " " << tempString << "\n";
		i++;
	}
	inStream.close();
	outStream.close();
}
void charStatistics() {
	ifstream inStream("potterFile.txt");
	if (inStream.fail()) {
		cout << "Åpning feilet. Bryter funksjonen" << endl;
		return;
	}
	char nextChar;
	int numberOfChars = 0;
	vector<int> charCount(26); //evt charCounter(26,0) samme?
	while (inStream.get(nextChar)) { //Macho
		if (isalpha(nextChar)) {
			numberOfChars++;
			charCount[tolower(nextChar) - 'a']++;
		}
	}
	cout << "Character statistics:" << endl;
	cout << "Total number of characters:" << numberOfChars << endl;
	for (int i = 0; i < charCount.size(); i++) {
		cout << static_cast<char>('a'+i) << ": " << charCount[i] << "\t";
		if (i && !((i+1) % 4)) { cout << endl; }
	}
	cout << endl;
	inStream.close();
}
bool myPredicate(char c) {
	return (!isalpha(c));
}
bool IsNonAlpha(char c)
{
	switch (c)
	{
	case '(':
	case ')':
	case '-':
	case '\'':
	case 'æ':
	case 'ø':
	case 'å':
	case '.':
	case ',':
	case '!':
	case '?':
	case '"':
	case '`':
	case '´':
		return true;
	default:
		return false;
	}
}
void wordStatistics() {
	ifstream inStream("potterFile.txt");
	if (inStream.fail()) {
		cout << "Åpning feilet. Bryter funksjonen" << endl;
		return;
	}
	int numberOfWords = 0;
	int numberOfLines = 0;
	int maxWordLength = 0;
	int averagewordlength = 0;
	string longestWord = "n/a";
	string nextLine;
	string nextWord;
	map<string, int> wordCount; //Her er map-en som teller for oss
	char chars[] = ",.-æøå!\"#¤%&/)=?";
	while (getline(inStream,nextLine)) { //Lagrer linje i nextLine
		numberOfLines++;
		stringstream ss(nextLine); //Lagrer linje i ss
		while (!ss.eof()) {
			ss >> nextWord; //Sender ord for ord til nextWord
			cout << "1 " << nextWord << endl;
			transform(nextWord.begin(), nextWord.end(), nextWord.begin(), ::tolower);
			cout << "2 " << nextWord << endl; //funker
			string cleanWord = "";
			for (auto& it : nextWord) //Kolon med iterator gir objekt, ikke peker
			{						//& for effektivitet
				if (isalpha(it)) { cleanWord += it; }
			}
			nextWord = cleanWord;
			//for (unsigned int i = 0; i < strlen(chars); i++) {
			//	nextWord.erase(remove(nextWord.begin(), nextWord.end(), isalpha));
			//}
			/*nextWord.erase(remove_if(nextWord.begin(), nextWord.end(), &IsNonAlpha, nextWord.end()));
			nextWord.erase(remove_if(nextWord.begin(), nextWord.end(), (int(*)(int))isalpha,nextWord.end()));
			nextWord.erase(remove_if(nextWord.begin(), nextWord.end(), not(ptr_fun((int(*)(int))isalpha)), nextWord.end()));
			*/
			cout << "3 " << nextWord << endl;
			if (nextWord.length()) {
				numberOfWords++;
				wordCount[nextWord]++;
				averagewordlength += nextWord.length();
				if (nextWord.length() > maxWordLength) {
					maxWordLength = nextWord.length();
					longestWord = nextWord;
				}
			}
		}
	}
	cout << "Word statistics:" << endl;
	cout << "Total number of words:" << numberOfWords << endl;
	cout << "Total number of lines:" << numberOfLines << endl;
	averagewordlength /= numberOfWords;
	cout << "Longest word: " << longestWord << " " << maxWordLength << endl;
	cout << "Average word length: " << averagewordlength << endl;
//	for (auto p : wordCount) {cout << p.first << ": " << p.second << endl; }
	cout << endl;
	inStream.close();
}

int main() {
	setlocale(LC_ALL, "norwegian");
	//writeToFile();
	//readAndCreateCopy();
	//charStatistics();
	CourseCatalog ntnuCat;
	//ntnuCat.addCourse("TMA4102","Livet");
	//ntnuCat.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
	//ntnuCat.addCourse("TDT4102", "Prosedyre - og objektorientert programmering");
	//ntnuCat.addCourse("TMA4100", "Matematikk 1");
	//cout << ntnuCat << endl;
	//ntnuCat.addCourse("TDT4102", "C++");
	//cout << ntnuCat << endl;
	//writeCatalogToFile(ntnuCat);
	readCatalogFile(ntnuCat);
	cout << ntnuCat << endl;
	//wordStatistics();
	return 0;
}
//Potensielt problem med at en linje har flere ord. Får ikke være macho?

//ifstream inStream("catalogFile.txt");
//if (inStream.fail()) {
//	cout << "Åpning feilet. Bryter funksjonen" << endl;
//	return 0;
//}
//string temp;
//while (getline(inStream, temp) && (temp != "\n")) {
//	string emnenavn = temp.substr(8);
//	//cout << temp.substr(0, 7) << " " << emnenavn << endl;
//	ntnuCat.addCourse(temp.substr(0, 7), emnenavn);
//}
//inStream.close();
