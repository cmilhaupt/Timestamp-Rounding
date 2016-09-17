#include "headers.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Usage: \n\t" << argv[0] << " <file.txt> -[options]" << endl;
		cout << "\t" <<  argv[0] << " <file.csv> -[options]" << endl;
		cout << "Options: \n\t" << "--net-pay\n\t--get-lunch\n\t--auto-deduct\n\t--piles\n" << endl;
		return 1;
	}
	Sort a(argv[1]);
	for(Person * person : a.people)
		person->calcLunchTime();

	string path_out = "/home/Colin/timestamp_rounding/out/";
	//net pay option	
	if(strcmp(argv[2], "--net-pay") == 0) {
		cout << "Calculating net pay distribution for each line." << endl;
		ofstream file;
		file.open(path_out + "net_pay_distribution.txt", ios::out | ios::app);
		double rounded = 0;
		for(Person * person : a.people) {
			rounded = netWorkVsPay(person);
			if (rounded == -1)
				continue;
			file << person->getLine() << ", " << rounded << endl;
		}
		file.close();
	} 

	//lunch option
	else if(strcmp(argv[2], "--get-lunch") == 0) {
		cout << "Calculating people with punch data." << endl;
		ofstream file;
		file.open(path_out + "people_with_lunch.txt", ios::out | ios::app);
		for(Person * person : a.people) {
			if(hasLunch(person))
				file << person->getLine() << endl;
		}
		file.close();	
	}

	//auto-deduct
	else if(strcmp(argv[2], "--auto-deduct") == 0) {
		cout << "Checking all entries with four timestamps for auto-deduct on employees who worked over six hours." << endl;
		ofstream file;
		file.open(path_out + "auto_deduct_ovr_six_hours2.txt", ios::out | ios::app);
		for(Person * person : a.people) {
			double overpaid = 0;
			if(workedOverSixHours(person) && hasLunch(person))
				overpaid = calcAutoDeduct(person);
				file << person->getLine() << "," << overpaid << endl;
		}
		file.close();
	}	
	
	//split into piles and do x
	else if(strcmp(argv[2], "--piles") == 0) {
		ofstream file1, file2;
		file1.open(path_out + "lunch_less_than_31_min_table.txt", ios::out);
		file2.open(path_out + "lunch_31_min_or_higher_table.txt", ios::out);
		for(Person * person : a.people) {
			if(hasLunch(person)) {
				if(stod(person->getLunch()) <= 0.5) {
					file1 << person->getLine() << endl;
				}
				else {
					file2 << person->getLine() << endl;
				}
			}
		}
		Sort b(path_out + "lunch_less_than_31_min_table.txt");
		Sort c(path_out + "lunch_31_min_or_higher_table.txt");
		file1.close();
		file2.close();
		
		ofstream file3, file4;
		file3.open(path_out + "lunch_less_than_31_min_calc.txt", ios::out);
		file4.open(path_out + "lunch_31_min_or_higher_calc.txt", ios::out);
		for(Person * person : b.people) {
			double overpaid = 0;
			if(workedOverSixHours(person))
				overpaid = calcAutoDeduct(person);
				file3 << person->getLine() << "," << overpaid << endl;
		}
		for(Person * person : c.people) {
			double overpaid = 0;
			if(workedOverSixHours(person))
				overpaid = calcAutoDeduct(person);
				file4 << person->getLine() << "," << overpaid << endl;
		}	
		file3.close();
		file4.close();
	}

	//intersection
	else if(strcmp(argv[2], "--intersect") == 0) {
		cout << "Calculating intersections for all headers between the universal and error set." << endl;
		ofstream file;
		file.open("error_set.txt");
		for(Person * person : a.people) {
			if(roundingError(person))
				file << person->getLine() << endl;
		}
		file.close();

		Sort b("error_set.txt");
		remove("error_set.txt");	
		intersectHeaders(&a, &b);
	}
	
	//tesing
	else if(strcmp(argv[2], "-test") == 0) {
		/*cout << "Testing Stats.cpp" << endl;
		vector<double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		vector<double> y = {1, 2, 4, 5, 7, 8, 10, 11, 13, 14};
		cout << "R value is:    " << getR(&x, &y) << endl;
		cout << "R^2 value is:  " << getR2(&x, &y) << endl;
		*/
		cout << "Testing String to Double/Int" << endl;
		/*
		double work_and_lunch = (a.people[81]->getTimeOut2() - a.people[81]->getTimeIn1());
		cout << work_and_lunch << endl;
		if ((floor(a.people[81]->getTimeOut2()/100)) != (floor(a.people[81]->getTimeIn1()/100)))
			work_and_lunch -= 40;
		cout << work_and_lunch << endl;
		double hours = floor(work_and_lunch/100);
		cout << hours << endl;
		int down = (int)work_and_lunch;
		cout << down << endl;
		double minutes = (double)(down % 100) / 60;
		cout << minutes << endl;
		cout << (hours + minutes) - a.people[81]->getPaid() << endl;
		*/
		for(int i = 0; i < 10; i++) {
			cout << a.people[i]->getLine() << endl;
			cout << "Worked: " <<  a.people[i]->getWorked() << endl;
			cout << "Paid: " << a.people[i]->getPaid() << endl;
		}
	}
	else {
		cout << "Invalid option." << endl;
		return 1;
	}
	return 0;
}
