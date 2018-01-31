#include<iostream>
using namespace std;
/*
int main() {
	char binary[30] = {};
	long num;
	int bitno = 0;
	cin >> num;
	while (num > 0) {
		if ((num % 2) == 1)
			binary[bitno] = '1';
		else
			binary[bitno] = '0';
		bitno++;
		num = num / 2; //eventuelle halve rundes ned
	}
	long newnum = 0;
	int j = 0;
	while (j < bitno) {
		newnum *= 2;
		if (binary[j] == '1')
			newnum = newnum + 1;
	}
}
*/
int main() {
	int tall = 13;
	cout << tall << endl;
	while (tall > 0) {
		tall = tall / 2;
		cout << tall << endl;
	}	
}
//Muligens bedre med booline operatorer