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
using namespace std;

ostream& operator<<(ostream& os, const CourseCatalog& catalog) {
	for (auto p : catalog.subjects) {
		os << p.first << " " << p.second << endl;
	}
	return os;
}
//Denne [] overskriver, mens insert ikke gjør noe om elementet finnes fra før
//void CourseCatalog::addCourse(string emnekode, string emnenavn) {
//	this->subjects[emnekode] = emnenavn;
//}
void CourseCatalog::addCourse(string emnekode, string emnenavn) {
	pair<string, string> aPair(emnekode, emnenavn);
	this->subjects.insert(aPair);
}
void CourseCatalog::removeCourse(string emnekode) {
	this->subjects.erase(emnekode);
}
string CourseCatalog::getCourse(string emnekode) const {
	//Opprett ny variabel i stedet!
	if (this->subjects.find(emnekode) != this->subjects.end()) {
		return this->subjects.find(emnekode)->second;
	}
	return "Course not in catalog";
}

//Filhåndtering
void writeCatalogToFile(const CourseCatalog& myCatalog) {
	ofstream outStream("catalogFile.txt");
	outStream << myCatalog;
	outStream.close();
}
void readCatalogFile(CourseCatalog& myCatalog) {
	ifstream inStream("catalogFile.txt");
	if (inStream.fail()) {
		cout << "Åpning feilet. Bryter funksjonen" << endl;
		return;
	}
	string temp;
	while (getline(inStream, temp) && (temp != "\n")) {
		string emnenavn = temp.substr(8,temp.length());
		//cout << temp.substr(0, 7) << " " << emnenavn << endl;
		myCatalog.addCourse(temp.substr(0, 7), emnenavn);
	}
	inStream.close();
}