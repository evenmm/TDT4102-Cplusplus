#include "Meeting.h"
#include "Person.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() { 
	Car car1(1);
	Car car2 = Car(4);
	Car car3(2);
	Person Fjodor("Fjodor", "fjofjo@hotmail.com", &car1);
	Person Knut("Knut", "k@gmail.com", &car2);
	Person Ivan("Ivan", "vanja@gmail.com", &car3);
	Person Dmitri("Dmitri", "dimm@rmail.ru");
	Person Dmitrill("Dmitrill", "dimmuborgir@rmail.ru");
	Person Raskolnikov("Raskolnikov", "forbrytelse@straff.com");
	
	Meeting globalization = Meeting(2, 1400, 1600, TRH, "Globalization and Norway", &Fjodor);
	globalization.addParticipant(&Dmitrill);
	globalization.addParticipant(&Raskolnikov); //Blir ikke lagt til...
	globalization.addParticipant(&Knut);
	globalization.addParticipant(&Ivan);
	cout << globalization << endl;
	
	Meeting lastMeeting = Meeting(3, 1700, 1730, GJO, "lastMeeting", &Raskolnikov);
	lastMeeting.addParticipant(&Ivan);
	cout << lastMeeting << endl;
	cout << "Printer alle personer med ledige seter" << endl;
	vector<const Person*> coDrivers = globalization.findPotentialCoDriving();
	for (auto it = coDrivers.begin(); it != coDrivers.end(); it++) {
		cout << **it << endl;
	}
	return 0;
}

//Meeting funmeeting = Meeting(3, 1700, 1730, AAL, "Funmeeting", &Dmitrill);
//cout << funmeeting << endl;
//Meeting genderAndSexuality = Meeting(3, 1700, 1730, AAL, "Gender and sexuality", &Dmitrill);
//cout << genderAndSexuality<< endl;
