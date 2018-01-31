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

int Meeting::getDay() {
	return day;
}
int Meeting::getStartTime() {
	return startTime;
}
int Meeting::getEndTime() {
	return endTime;
}
Campus Meeting::getLocation() {
	return location;
}
string Meeting::getSubject() {
	return subject;
}
const Person* Meeting::getLeader() {
	return leader;
}

ostream& operator<<(ostream& os, const Campus& c) { //Har overlagra << til å printe Campus!
	switch (c)
	{
	case TRH:
		os << "TRH";
		break;
	case GJO:		os << "GJO";		break;	case AAL:		os << "AAL";		break;
	default:
		os << "Ugyldig";		break;	}	return os;}

void Meeting::addParticipant(const Person* newPerson) {
	bool inserted = false;
	if (participants.size() == 0) { participants.push_back(newPerson); }
	else {
		for (auto it = participants.begin(); it != participants.end(); it++) {
			if (*newPerson < **it) { //it er en peker til elementer *it i participants, somer pekere til personer
				participants.insert(it, newPerson);
				inserted = true;
				break; //Gjør break med en gang så iterator OK
			}
		}
		if (!inserted) { participants.push_back(newPerson); }
	}
}

vector<const Meeting*> Meeting::meetings;
Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader) {
	this->day = day;
	this->startTime = startTime;
	this->endTime = endTime;
	this->location = location;
	this->subject = subject;
	this->leader = leader;
	addParticipant(leader);
    meetings.push_back(this); //this legger til møtet i meetings!!
}

Meeting::~Meeting() {
	auto it = meetings.begin();
	while (it != meetings.end() && *it != this) { it++; } //Bryter på this meeting
	meetings.erase(it);
}

vector<string> Meeting::getParticipantList() const { //Kall: education.getParticipantList()
	vector<string> participantList;
	for (unsigned i = 0; i < participants.size(); i++) {
			participantList.push_back(participants[i]->getName());
	}
	return participantList;
}

ostream& operator<<(ostream& os, Meeting& m) { //Fjernet const
	os << m.getSubject() << "\n" << m.getLocation() << "\n"
		<< to_string(m.getStartTime()) << "-" << to_string(m.getEndTime())
		<< "\nLeder " << m.getLeader()->getName()
		<< "\nAlle Deltakere: \n";
	for (unsigned i = 0; i < (m.getParticipantList()).size(); i++) {
		os << (m.getParticipantList())[i] << endl; //Gir ingenting
	}
	return os;
} //Subject er string, har overlagra << til å printe Campus og Person (leader)!

vector<const Person*> Meeting::findPotentialCoDriving() { //Kun const-funksjoner!
	vector<const Person*> potentialCodrivers;
	const vector<const Meeting*> meetingsCopy = meetings; //Shallow copy
	for (auto it = meetingsCopy.begin(); it != meetingsCopy.end(); it++) { //Møter
		for (auto it2 = (*it)->participants.begin(); it2 != (**it).participants.end(); it2++) { //PAX
			if ((**it2).hasAvailableSeats()) {
				if ( ! (find(potentialCodrivers.begin(), potentialCodrivers.end(), (*it2)) != potentialCodrivers.end())) {
					potentialCodrivers.push_back(*it2); //Legger til Person-peker
				}
				//((**it2).getCar()).reserveFreeSeat; // Skal ikke med
			}
		}
	}
	return potentialCodrivers;
}
