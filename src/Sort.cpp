#include "headers.hpp"

using namespace std;

Sort::Sort(string filename) {
	int count = 0;
	string line;
	vector<string> list;
	ifstream fd;
	
	//open file
	fd.open(filename);
	
	//put each line of the file into vector<string> list
	if(fd.is_open()) {
		while(getline(fd, line)) {
			list.push_back(line);
			count++;
		}
	} else {
		cout << "Invalid filename." << endl;
		return;
	}
	
	this->size = count;
	cout << count << " entries read...\nSorting..." << endl;
	fd.close();
	char split_char = ',';
	
	//create an object for each line of the file and store in this->people
	for(int i = 0; i < count; i++) {
		vector<string> b;
		if (i == 0) {
			istringstream split(list[i]);
			for(string each; getline(split, each, split_char); b.push_back(each));
			this->headers = b;
			continue;
		}

		//split each value of commas into vector<string> b
		istringstream split(list[i]);
		for(string each; getline(split, each, split_char); b.push_back(each));
		try {
			this->people.push_back(new Person(	b[0], 
							        b[1],
								b[2], 
							    	b[3], 
								b[4], 
								b[5], 
								b[6],
								b[7],
								b[8],
								b[9],
								b[10],
								b[11],
								b[12],
								list[i],
								&b
								));
		} catch (exception e) {
			cout << "Loading input file into memory failed." << endl;
			exit(0);
		}
	}
	cout << "All entries sorted." << endl;
}

Sort::~Sort() {
}
