#include <algorithm>
#include <cmath>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	string name;
	string emp_id1;
	string date;
	string day_note;
	string time_in1;
	string time_out1;
	string time_in2;
	string time_out2;
	string total_day_paid;
	string time_worked1;
	string time_worked2;
	string time_worked_total;
	string line;
	string lunch_time; //calculate
	
	public:
	Person(string, string, string, string, string, string, string, string, string, string, string, string, string, string, vector<string>*);
	void calcLunchTime();
	string getName();
	string getWorked();
	string getPaid();
	string getLunch();
	string getTimeIn1();
	string getTimeOut1();
	string getTimeIn2();
	string getTimeOut2();
	string getLine();
	void print();
	vector<string> headers;
};

class Sort
{
	public:
	vector<Person*> people;
	int size;
	vector<string> headers;
	Sort(string);
	~Sort();
};

extern struct sets {
	string type;
	vector<string> members;
} Sets;

bool roundingError(Person * person);
bool hasLunch(Person * person);
double netWorkVsPay(Person * person);
bool workedOverSixHours(Person * person);
double calcAutoDeduct(Person * person);

double getR(vector<double> * x, vector<double> * y);
double getR2(vector<double> * x, vector<double> * y);

void intersectHeaders(Sort*, Sort*);
