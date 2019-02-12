#include "catalog.h"
#include "std_lib_facilities.h"
using namespace std;
#include <iostream>


//CourseCatalog::CourseCatalog(string code, string name, map<string, string> mapC) : subjectCode(code), subjectName(name), mapCatalog(mapC) {}

CourseCatalog::CourseCatalog(map<string, string> mapC) : mapCatalog(mapC), valid(true) {
}

CourseCatalog CourseCatalog::operator<<(const CourseCatalog& catalog) {
	map<string, string>::iterator it = mapCatalog.find("C++");
	cout << it->second << endl;
	return catalog;
}

void CourseCatalog::addCourse(string code, string name) {
	//mapCatalog.insert(pair<string, string>(code, name));
	mapCatalog[code] = name;
}
void CourseCatalog::removeCourse(string code) {
	mapCatalog.erase(code);
}
string CourseCatalog::getCourse(string code) {
	return mapCatalog[code];
}
void CourseCatalog::addExamples() {
	mapCatalog.insert(pair<string, string>("TDT4110", "Informasjonsteknologi grunnkurs"));
	mapCatalog.insert(pair<string, string>("TDT4102", "Prosedyre- og objektorientert programmering"));
	mapCatalog.insert(pair<string, string>("TMA4100", " Matematikk 1."));
}
void CourseCatalog::printAll() {
	cout << "Code:" << setw(12) << "Value:" << endl;
	for (map<string, string>::iterator iter = mapCatalog.begin(); iter != mapCatalog.end(); ++iter) {
		cout << iter->first << setw(47) << iter->second << endl;
	}
	

}
void CourseCatalog::saveToFile() {
	ofstream outFile;
	outFile.open("courseCatalog.txt");
	for (map<string, string>::iterator iter = mapCatalog.begin(); iter != mapCatalog.end(); ++iter) {
		outFile << iter->first << ":" << iter->second << ":";// << endl;
	}
	cout << "File saved as courseCatalog.txt" << endl;
}
void CourseCatalog::openFile() {
	ifstream inFile; string line; vector<string> stringVector;   //Åpner fil
	inFile.open("courseCatalog.txt");
	if (inFile.fail()) {
		cerr << "Failed to load file.";							//sjekker for crash
		exit(1);
	}
	while (getline(inFile, line, ':')) {					//Lager en liste stringVector = {KODE, NAVN, KODE, NAVN ... }
		stringVector.push_back(line);			
	}
	for (int i = 0; i < stringVector.size(); i += 2) {			
		mapCatalog[stringVector[i]] = stringVector[i + 1];			//Setter sammen et map mapCatalog
	}
}

Temps::Temps(double firstElement, double secondElement) : max(firstElement), min(secondElement) {}


istream& operator>>(istream& inFile, Temps& t) {
	double tempOne, tempTwo; pair<double, double> temperaturePair;

	inFile >> tempOne >> tempTwo;									//Henter ut to verdier fra fila 
	temperaturePair = pair<double, double>(tempOne, tempTwo);			//Lager et par av de
	if (temperaturePair.first < temperaturePair.second) temperaturePair.swap(temperaturePair); //Setter største verdi først
	t = { temperaturePair.first, temperaturePair.second };			//Endrer verdien til temp
	return inFile;													// Returnerer fila
}


void Temps::printTemps() {
	cout << max << '\t' << min << endl;		 //'\t' << (max-min) << 
}
	
