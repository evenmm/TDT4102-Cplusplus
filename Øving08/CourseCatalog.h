#pragma once
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

class CourseCatalog
{
public:
	void addCourse(string emnekode, string emnenavn);
	void removeCourse(string emnekode);
	string getCourse(string emnekode) const;
	map<string, string> subjects;
private:
};

ostream& operator<<(ostream& os, const CourseCatalog& catalog);
void writeCatalogToFile(const CourseCatalog& myCatalog);
void readCatalogFile(CourseCatalog& myCatalog);