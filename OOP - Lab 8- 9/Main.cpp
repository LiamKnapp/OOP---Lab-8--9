/********************************************//**
 * @brief the main function where we find the label for orientations
 *
 * includes header .h and both class files
 * uses 2 files Data.txt and Test.txt
 *
 * @authors Liam
 * @date 2022-04-10
 ***********************************************/

#include "Header.h"
#include "Class.cpp"
#include "ClassUnkown.cpp"
#include "AnotherClass.h"

//declare the classes
Orient o;
UnkownOrient uo;

//used to read the file and find what label fits best
int FeatureMatrix(string line) {
	//initializers
	istringstream issline(line);
	string num;
	double x = 0;
	double y = 0;
	double z = 0;
	int label = 0;
	double dif1 = 0,dif2=0,dif3=0;

	//read the file
	while (!issline.eof()) {
		getline(issline, num, ',');
		x = stod(num);
		//o.setX(x);

		getline(issline, num, ',');
		y = stod(num);
		//o.setY(y);

		getline(issline, num, ',');
		z = stod(num);
		//o.setZ(z);

		getline(issline, num, ',');
		label = stoi(num);
		//o.setLabel(label);

		//find the and save the label of whatever combination of x, y, z have the shorest diference
		//find the x diference
		if (x > uo.getX()) {
			if (x > 0 && uo.getX() < 0) {
				dif1 = x + uo.getX();
			}
			if (x > 0 && uo.getX() > 0) {
				dif1 = x - uo.getX();
			}
			if (x < 0 && uo.getX() < 0) {
				dif1 = x - uo.getX();
			}
		}
		if (x < uo.getX()) {
			if (x < 0 && uo.getX() > 0) {
				dif1 = uo.getX() + x;
			}
			if (x < 0 && uo.getX() < 0) {
				dif1 = uo.getX() - x;
			}
			if (x > 0 && uo.getX() > 0) {
				dif1 = uo.getX() - x;
			}
		}
		//--------------------------------
		//find the y diference
		if (y > uo.getY()) {
			if (y > 0 && uo.getY() < 0) {
				dif2 = y + uo.getY();
			}
			if (y > 0 && uo.getY() > 0) {
				dif2 = y - uo.getY();
			}
			if (y < 0 && uo.getY() < 0) {
				dif2 = y - uo.getY();
			}
		}
		else {
			if (y < 0 && uo.getY() > 0) {
				dif2 = uo.getY() + y;
			}
			if (y < 0 && uo.getY() < 0) {
				dif2 = uo.getY() - y;
			}
			if (y > 0 && uo.getY() > 0) {
				dif2 = uo.getY() - y;
			}
		}
		//--------------------------------
		//find the z diference
		if (z > uo.getZ()) {
			if (z > 0 && uo.getZ() < 0) {
				dif3 = z + uo.getZ();
			}
			if (x > 0 && uo.getZ() > 0) {
				dif3 = z - uo.getZ();
			}
			if (x < 0 && uo.getZ() < 0) {
				dif3 = z - uo.getZ();
			}
		}
		else {
			if (z < 0 && uo.getZ() > 0) {
				dif3 = uo.getZ() + z;
			}
			if (x < 0 && uo.getZ() < 0) {
				dif3 = uo.getX() - z;
			}
			if (x > 0 && uo.getZ() > 0) {
				dif3 = uo.getX() - z;
			}
		}
		
		// if the diference is the shortest saved that diferece and label. Repeat.
		if (dif1 < o.getX()) {
			if (dif2 < o.getY()) {
				if (dif3 < o.getZ()) {
					o.setX(dif1);
					o.setY(dif2);
					o.setZ(dif3);
					o.setLabel(label);
				}
			}
		}
	}
	return 0;
}


//read the unkowndata file
int UnkownFile(string line) {
	//initializers
	istringstream issline(line);
	string num;
	double x;
	double y;
	double z;
	int i = 0;

	//read the file and save to the class
	while (!issline.eof()) {
		getline(issline, num, ',');
		x = stod(num);
		uo.setX(x);

		getline(issline, num, ',');
		y = stod(num);
		uo.setY(y);

		getline(issline, num, ',');
		z = stod(num);
		uo.setZ(z);
		
	}
	return 0;

}


int main() {

	// user input or file input selection
	int input;
	cout << "Enter a number:" << endl;
	cout << "1) Read from file" << endl;
	cout << "2) User input" << endl;
	cout << "3) Print all function names" << endl;
	cin >> input;

	//set the class so that it can be used to find diference
	o.setX(100);
	o.setY(100);
	o.setZ(100);

	string filename = "Data.txt"; 
	ifstream fin;
	ofstream fout;

	if (input == 1) {
		//open the file with the unkown labels
		fin.open(filename);

		if (fin.is_open()) {
			//read and save the contents to the class
			while (!fin.eof()) {
				string line;
				getline(fin, line);
				UnkownFile(line);
				cout << "\n" << "Data: " << endl;
				cout << "X: " << uo.getX() << endl;
				cout << "Y: " << uo.getY() << endl;
				cout << "Z: " << uo.getZ() << endl;
			}
			fin.close();
		}
		else { // error check
			cout << "I cannot open this file: " << filename << endl;
		}
	}
	// --------------------------------------------------------------------
	
	//get the user to input there (x,y,z)
	if (input == 2) {
		double info;
		cout << "enter x: " << endl;
		cin >> info;
		uo.setX(info);

		cout << "enter y: " << endl;
		cin >> info;
		uo.setY(info);

		cout << "enter z: " << endl;
		cin >> info;
		uo.setZ(info);
	}

	//print the names of every function then exit
	if (input == 3) {
		anotherclass();
		exit(0);
	}

	filename = "Test.txt";
	//open the file with all the feature matrix
	fin.open(filename);

	if (fin.is_open()) {

		while (!fin.eof()) { // compare matrix and save to class
			string line;
			getline(fin, line);
			FeatureMatrix(line);
			cout << "\n" << "Line: " << endl;
			cout << "X: " << o.getX() << endl;
			cout << "Y: " << o.getY() << endl;
			cout << "Z: " << o.getZ() << endl;
			cout << "Label: " << o.getLabel() << endl;
		}
		fin.close();
	}
	else { // error check
		cout << "I cannot open this file: " << filename << endl;
	}
	
	//set the label according to what the label should be
	uo.setLabel(o.getLabel());

	//final print
	cout << "\n" << "Phone Orientation for Data: " << endl;
	cout << "X: " << uo.getX() << endl;
	cout << "Y: " << uo.getY() << endl;
	cout << "Z: " << uo.getZ() << endl;
	cout << "Is label: " << uo.getLabel() << endl;

	return 0;

}
