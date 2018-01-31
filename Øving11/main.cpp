#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string container[6] = { "Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
	vector<string> myVector;
	for (int i = 0; i < sizeof(container); i++) {
		myVector.push_back(container[i]);
	}
	for (auto it = myVector.begin(); it != myVector.end(); it++) {
		cout << *it << endl;
	}
	for (auto it = myVector.rbegin(); it != myVector.rend(); it--) {

	}
	return 0;
}