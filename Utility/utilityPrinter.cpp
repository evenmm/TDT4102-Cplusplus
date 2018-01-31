#include "utilityPrinter.h"
#include <string>
using namespace std;

void utilityPrinter(string words[],int range) {
	for (int i = 0; i < range; i++) {
		int shalala = 0;
		cout << "case " << words[i] << ":\nreturn '" << tolower(words[i]) << ";\nbreak;\n" << endl;
	}
//Skeleton:
//	cout << "" << words[i] << "" << endl;
}