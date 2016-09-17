#include "headers.hpp"

using namespace std;

Person::Person(string name1, string name2, string id, string date, string note, string time_in1, string time_out1, string time_in2, string time_out2, string paid, string time1, string time2, string total_time, string line, vector<string> * headers) {
	this->name.assign(name1 + ' ' + name2);
	this->emp_id1.assign(id);
	this->date.assign(date);
	this->day_note.assign(note);
	this->time_in1.assign(time_in1);
	this->time_out1.assign(time_out1);
	this->time_in2.assign(time_in2);
	this->time_out2.assign(time_out2);
	this->total_day_paid.assign(paid);
	this->time_worked1.assign(time1);
	this->time_worked2.assign(time2);
	this->time_worked_total.assign(total_time);
	this->time_worked_total.erase(time_worked_total.length() - 1);
	this->line.assign(line);
	this->line.erase(line.length() - 1);
	this->headers.resize((*headers).size());
	for (unsigned int i = 0; i < (*headers).size(); i++)
		this->headers[i] = (*headers)[i];
}

void Person::calcLunchTime() {
	double lunch = 0;
	if (stoi(this->time_in2) > stoi(this->time_out1))
		lunch = stoi(this->time_in2) - stoi(this->time_out1);
	else
		lunch = 2400 + (stoi(this->time_in2) - stoi(this->time_out1));
	if ((stoi(this->time_in2) % 100) < (stoi(this->time_out1) % 100))
		lunch -= 40;
	double hours = floor(lunch/100);
	int down = (int)lunch;
	double minutes = (double) (down % 100) / 60;
	this->lunch_time = to_string(hours + minutes);
}

string Person::getName() {
	return this->name;
}

string Person::getWorked() {
	return this->time_worked_total;
}

string Person::getPaid() {
	return this->total_day_paid;
}

string Person::getLunch() {
	return this->lunch_time;
}

string Person::getTimeIn1() {
	return this->time_in1;
}

string Person::getTimeOut1() {
	return this->time_out1;
}

string Person::getTimeIn2() {
	return this->time_in2;
}
string Person::getTimeOut2() {
	return this->time_out2;
}
string Person::getLine() {
	return this->line;
}

void Person::print() {
	cout << "Name: " << this->name << endl;
	cout << "Date: " << this->date << endl;
	cout << "Time worked: " << this->time_worked_total << endl;
	cout << "Time paid: " << this->total_day_paid << endl;
}
