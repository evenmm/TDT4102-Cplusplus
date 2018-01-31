#include <iostream>
#include <iomanip>
using namespace std;

void inputAndPrintInteger() {
	int dittTall = 0;
	cout << "Skriv inn et heltall" << endl;
	cin >> dittTall;
	cout << "Du skrev " << dittTall << endl;
}
	
int inputInteger() {
	int dittTall = 0;
	cout << "Skriv inn et heltall" << endl;
	cin >> dittTall;
	return dittTall;
}

void inputIntegersAndPrintSum() {
	int TallA = inputInteger(); //returnsNumber er den eneste som lar meg ta vare på et tall
	int TallB = inputInteger();
	cout << "Summen av tallene: " << TallA + TallB << endl;
}

bool  isOdd(int provetall) {
	if ((provetall % 2) == 0) { //heltallsrest
		return 0;
	}
	return 1;
}

void printHumanReadableTime(int sekundhaug) { 
	int timemultiplum = sekundhaug - (sekundhaug % 3600);
	sekundhaug -= timemultiplum; //Trekker fra alle hele timer;
	int minuttmultiplum = sekundhaug - (sekundhaug % 60);
	sekundhaug -= minuttmultiplum; //Trekker fra alle hele minutter;
	cout << (timemultiplum / 3600) << " timer, "
		<< (minuttmultiplum / 60) << " minutter og "
		<< (sekundhaug) << " sekunder." << endl;
}

// OPPGAVE 2

void inputIntegersUsingLoopAndPrintSum() {
	int sum = 0;
	int temp = 0;
	cout << "Skriv inn tall, skriv 0 for å slutte" << endl;
	do {
		temp = inputInteger();
		sum += temp;
	} while (temp != 0); // do ... while er bra her, sjekker etterpå. Kan holde på evig.
	cout << "Sum: " << sum << endl; //Den andre bør ha for-løkke fordi den bryter selv og er godt leselig.
}

void secondInputIntegerLoopSum() {
	int sum = 0;
	int antall = 0;
	cout << "Hvar mange tall?" << endl;
	cin >> antall;
	for (int i = 0; i < antall;i++) {
		sum += inputInteger();
	}
	cout << "Sum: " << sum << endl;
}

double inputDouble() {
	double dittTall = 0;
	cout << "Skriv inn et tall med punktum som evt komma" << endl;
	cin >> dittTall;
	return dittTall;
}

void konverterNOKtilEUR() {
	double nok = inputDouble();
	while (nok < 0) {
		cout << "Skriv et positivt tall." << endl;
		nok = inputDouble();
	}
	double eur = (nok / 9.64);
	cout << setprecision(3) << eur << '\n';
}

//Må ha double eller float fordi desimaltall og muligens negativt. Returtypen må tilsvare.

void gangetabell() {
	cout << "Gangetabell!" << endl;
	int hoyde = 0;
	int bredde = 0;
	cout << "Skriv inn hoyde" << endl;
	cin >> hoyde;
	cout << "Skriv inn bredde" << endl;
	cin >> bredde;
	for (int i = 1; i < hoyde+1; i++) {
		for (int j = 1; j < bredde+1; j++) {
			if (j*i<10) {
				cout << " " << i * j << " ";
			}
			else {
				cout << i * j << " ";
			}
		}
		cout << "\n";
	}
}
#include<cmath>
double diskriminant(double &a, double &b, double &c) {
	return a,b,c,(pow(b, 2.0) - (4*a*c));
}
// Losning ved bruk av call-by-reference

void printRealRoots() {
	cout << "Skriv inn koeffisienter fra ax^2 + bx + c." << endl;
	cout << "a: ";
	double a = inputDouble();
	cout << "b: ";
	double b = inputDouble();
	cout << "c: ";
	double c = inputDouble();
	double disk = diskriminant(a, b, c);
	if (disk < 0) {
		cout << "Ingen reelle røtter" << endl;
		return;
	}
	cout << "Forste rot: " << (-b + sqrt(disk)) / (2 * a) << endl;
	cout << "Andre rot: " << (-b - sqrt(disk)) / (2 * a) << endl;
}
// Losning ved bruk av Array

void printRealRootsUsingArray() {
	cout << "Skriv inn koeffisienter fortløpende fra ax ^ 2 + bx + c." << endl;
	double eq[3] = { inputDouble(),inputDouble(),inputDouble() };
	double disk = diskriminant(eq[0], eq[1], eq[2]);
	if (disk < 0) {
		cout << "Ingen reelle røtter" << endl;
		return;
	}
	cout << "Forste rot: " << (-eq[1]+sqrt(disk)) / (2 * eq[0]) << endl;
	cout << "Andre rot: " << (-eq[1]- sqrt(disk)) / (2 * eq[0]) << endl;
}

// Losning ved bruk av Struct

void printRealRootsUsingStruct() {
	cout << "Skriv inn koeffisienter fortløpende fra ax ^ 2 + bx + c." << endl;
	struct equation {
		double a;
		double b;
		double c;
	};
	equation e1 = { inputDouble(),inputDouble(),inputDouble() };
	double disk = diskriminant(e1.a, e1.b, e1.c);
	if (disk < 0) {
		cout << "Ingen reelle røtter" << endl;
		return;
	}
	cout << "Forste rot: " << (-e1.b + sqrt(disk)) / (2 * e1.a) << endl;
	cout << "Andre rot: " << (-e1.b - sqrt(disk)) / (2 * e1.a) << endl;
}
void calculateLoanPayments() {
	cout << "Skriv inn Lånebeløp" << endl;
	const double totaltLaan = inputDouble();
	double lanebelop = totaltLaan;
	cout << "Skriv inn Rente i prosent" << endl;
	double rente = inputDouble();
	double totaleInnbetalinger = 0;
	cout << "År \t" << "Innbetaling: \t " << "Gjenstående lån: " << lanebelop << endl;
	for (int aar = 0; aar < 10; aar++) {
		double innbetaling = ((totaltLaan / 10) + (rente / 100)*lanebelop);
		lanebelop -= (totaltLaan/10);
		printf("Jeg skal skrive følgende tall %.2f %d".totaleInnbetalinger);
		cout << setprecision(4) << (aar +1) << "\t" << innbetaling << "\t \t" << lanebelop  << endl;
		totaleInnbetalinger += innbetaling;
	}
	printf("Jeg skal skrive følgende tall %.2f %d".totaleInnbetalinger);
	cout << setprecision(4) << "Totale innbetalinger: " << totaleInnbetalinger << endl;
	cout << "Hvordan kan jeg runde av på en penere maate? Og evt hoyrestille tekst?" << endl;
}
// 		cout << setprecision(4) << "År " << (aar +1) << ". Innbetaling: " << innbetaling << ". Gjenstående lån: " << lanebelop  << endl;

int main() {
	/*inputAndPrintInteger()
	cout << inputInteger() << endl;
	inputIntegersAndPrintSum();
	for (int i = 0; i < 10; i++) {
		if (isOdd(i)) {
			cout << i << " er odde" << endl;
		}
		else {
			cout << i << " er partall" << endl;
		}
	}
	cout << "10000 sekunder blir ";
	printHumanReadableTime(10000);
	cout << "4459 sekunder blir ";
	printHumanReadableTime(4459);
	// Oppgave 2
	cout << inputDouble() << endl; //Hvorfor vises ikke hele tallet i monitor? Auto-avrunding?
*/	int valg = 0;
	do {
		cout << "Velg funksjon: \n"
			<< "0) Avslutt \n"
			<< "1) Summer to tall \n"
			<< "2) Summer flere tall \n"
			<< "3) Konverter NOK til EURO. \n"
			<< "4) Print en gangetabell for å ha med på eksamen. \n"
			<< "5) Print røtter til 2. gradsligning ved bruk av Call-by-reference. \n"
			<< "6) Print røtter til 2. gradsligning ved bruk av Array. \n"
			<< "7) Print røtter til 2. gradsligning ved bruk av Struct. \n"
			<< "8) Beregn innskudd for lån over en tiårsperiode. \n"
			<< "Angi valg(0 - n) :" << endl;
		cin >> valg;
		switch (valg) {
		case 0:
			break;
		case 1:
			inputIntegersAndPrintSum();
			break;
		case 2:
			inputIntegersUsingLoopAndPrintSum();
			break;
		case 3:
			konverterNOKtilEUR();
			break;
		case 4:
			gangetabell();
			break;
		case 5:
			printRealRoots();
			break;
		case 6:
			printRealRootsUsingArray();
			break;
		case 7:
			printRealRootsUsingStruct();
			break;
		case 8:
			calculateLoanPayments();
			break;
		}
	} while (valg != 0);
	return 0;
}
