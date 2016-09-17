#include "headers.hpp"

double quarterRounded(double time) {
	return (floor((time*4)+0.5)/4);
}

bool roundingError(Person * person) {
	double worked = stod(person->getWorked());
	double paid = stod(person->getPaid());
	if((floor((worked*4)+0.5)/4) != paid)
		return true;
	return false;
}

double netWorkVsPay(Person * person) {
	if (stoi(person->getTimeOut1()) == 0 || 
		stoi(person->getTimeIn2()) == 0 ||
		stoi(person->getTimeOut2()) == 0)
		return -1;
	double worked = stod(person->getWorked());
	double paid = stod(person->getPaid());
	double rounded = floor((worked*4)+0.5)/4;
	double result = rounded - paid;
	return result;
}

bool hasLunch(Person * person) {
	if (stoi(person->getTimeIn1()) != 0 && 
		stoi(person->getTimeOut1()) != 0 && 
		stoi(person->getTimeIn2()) != 0 && 
		stoi(person->getTimeOut2()) != 0)
		return true;
	return false;
}

bool workedOverSixHours(Person * person) {
	if((stod(person->getWorked()) + stod(person->getLunch())) <= 6 )
		return false;
	if(stoi(person->getTimeIn1()) == 0 ||
		stoi(person->getTimeOut1()) == 0 ||
		stoi(person->getTimeIn2()) == 0 ||
		stoi(person->getTimeOut2()) == 0)
		return false;
	return true;
}

double calcAutoDeduct(Person * person) {
	double work_and_lunch = 0;
	if (stoi(person->getTimeOut2()) > stoi(person->getTimeIn1()))
		work_and_lunch = stoi(person->getTimeOut2()) - stoi(person->getTimeIn1());
	else
		work_and_lunch = 2400 - (stoi(person->getTimeIn1()) - stoi(person->getTimeOut2()));
	if ((stoi(person->getTimeOut2()) % 100) < (stoi(person->getTimeIn1()) % 100))
		work_and_lunch -= 40;
	double hours = floor(work_and_lunch/100);
	int down = (int)work_and_lunch;
	double minutes = (double)(down % 100) / 60;
	return quarterRounded(hours + minutes - 0.5) - stod(person->getPaid());
}
