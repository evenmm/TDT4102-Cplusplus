#include <iostream>
#include "utilities.h"
#include "tests.h"
#include "playMastermind.h"
#include <ctime>
using namespace std;

/*Oppgave 1 a)
v0 vil ha verdien 5, ogs� n�r den printes, fordi det kun er startValue som endres. 
startValue starter p� v0 men ingenting gj�res for � endre v0.

1e) 
swapNumbers b�r bruke pekere, forutsatt at det vi vil gj�re er � ta vare p� de byttede selvf�lgelig.
*/

int main() {
	srand((unsigned int)time(nullptr));
	int valg = 0;
	int a = 2;
	int b = 3;
	do {
		char reply = 'a';
		cout << "0) Avslutt \n"
			<< "1) Test call-by-value \n" 
			<< "2) Test call-by-pointer \n" 
			<< "3) Bytt to tall \n"
			<< "4) Test tables-sorting \n"
			<< "5) Test C-string \n"
			<< "6) Play MASTERMIND"
			<< endl;
		cin >> valg;
		switch (valg) {
		case 1:
			testCallByValue();
			break;
		case 2:
			testCallByPointer();
			break;
		case 3:
			cout << "a: " << a << ", b: " << b << endl;
			swapNumbers(&a, &b);
			cout << "Byttet: \na: " << a << ", b: " << b << endl;
			break;
		case 4:
			testTablesSorting();
			break;
		case 5:
			testCStrings();
			break;
		case 6:
			while (reply != 'n') {
				playMastermind();
				cout << "Vil du spille p� nytt? j/n" << endl;
				cin >> reply;
				while ((reply != 'j') && (reply != 'n')) {
					cout << "Skriv inn enten j eller n" << endl;
					cin >> reply;
				}
			}
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		}
	} while (valg != 0);
	return 0;
}