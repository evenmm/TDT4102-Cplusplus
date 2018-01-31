#pragma once
#include "Person.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

enum Campus {TRH, GJO, AAL};

ostream& operator<<(ostream& os, const Campus& c);

class Meeting
{
private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	string subject;
	const Person* leader;
	vector<const Person*> participants; //vector av pekere til Personer
	static vector<const Meeting*> meetings;
public:
	Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader);
	~Meeting();
	int getDay();
	int getStartTime();
	int getEndTime();
	Campus getLocation();
	string getSubject();
	const Person* getLeader();
	void addParticipant(const Person* newPerson);
	vector<string> getParticipantList() const;
	vector<const Person*> findPotentialCoDriving();
};

ostream& operator<<(ostream& os, Meeting& m);
