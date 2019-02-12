#pragma once
#include "std_lib_facilities.h"


class CourseCatalog {
	string subjectCode; string subjectName;
	map<string, string> mapCatalog;  // KODER, NAVN
	bool valid;
public:
	CourseCatalog(map<string, string> mapC);

	CourseCatalog operator<<(const CourseCatalog& catalog);
	void addCourse(string code, string name);
	void removeCourse(string code);
	string getCourse(string code);
	void addExamples();
	void printAll();
	void saveToFile();
	void openFile();
};


class Temps {
	double max; double min;
public:
	Temps(double firstElement, double secondElement);
	friend istream& operator>>(istream& in, Temps& t);
	void printTemps();
};



