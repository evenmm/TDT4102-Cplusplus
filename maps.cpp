#include<iostream>
#include<string>
#include<map>
#include<utility>
using namespace std;
int main() {
	//Her skal vi mappe strenger til karakterer
	map<string, char> studMap;
	string name = "Pareli";
	studMap["Bjarne"] = 'C'; //Skilles på "streng" og 'char'!!!!!
	studMap["Blaise"] = 'B';
	studMap["Ada"] = 'A';
	cout << studMap["Bjarne"] << "." << endl;
	cout << studMap[name] << endl; //gir blank hvis elementet ikke finnes
	name = "Sergej";
	if (studMap.find(name) == studMap.end()) {
		cout << name << " is not in map." << endl;
	}
	name = "Blaise";
	if (studMap.find(name) == studMap.end()) {
		cout << name << " is in map with grade " 
			<< studMap.find(name)->second << endl;
		cout << studMap[name];
	}
	//To måter å putte ting inn i tabellen på. Hvem er raskest?
	name = "Donald";
	studMap[name] = 'D';
	studMap.insert(make_pair("Hillary", 'C'));
	for (auto it = studMap.begin(); it != studMap.end(); it++) {
		cout << it->first << " " << it->second << endl; 
	}
}
