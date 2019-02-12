#include "std_lib_facilities.h"
#include "fileFunctions.h"
#include "catalog.h"

void writeToFile(string filename) {					// Trenger hjelp til å få setninger på samme linje i .txt fila
	ofstream outFile; char word[80];
	outFile.open(filename);

	cout << "Write 'quit' to quit the program. \n";
	while (0 != 1) {
		//cout << "Skriv noe som skal lagres i fil: "; 
		cin.getline(word, 80);
		if (word[0] == 'q' && word[1] == 'u' && word[2] == 'i' && word[3] == 't') {
			break;
		}
		outFile << word << endl;
	}
	outFile.close();
}


void addLineNumber() {
	string line; int counter = 0; stringstream sso;

	fstream inOutFile;
	inOutFile.open("OppgaveB.txt");
	
	if (inOutFile.fail()) {						//Sjekker for error
		cerr << "Failed to open.";
		exit(1);
	}

	while (getline(inOutFile, line)) {				//Lager en stringstream med et tall før hver linje
		sso << counter << ": " << line << endl;
		++counter;
	}
	inOutFile << sso.str();
	inOutFile.close();
}

map<char, int> makeAlphabet() {
	map<char, int> alphabet;
	char letter;
	for (int intLetter = 97; intLetter < 123; ++intLetter) {	//Lager et
		letter = static_cast<char>(intLetter);
		alphabet[letter] = 0;
	}
	alphabet['?'] = 0;
	return alphabet;
}

void countChar() {
	fstream inFile;							//Open file
	inFile.open("grunnlov.txt");
	if (inFile.fail()) {
		cerr << "Failed to open";
		exit(1);
	}

	map<char, int> alphabet = makeAlphabet();			//Declare variables
	map<char, int>::iterator it; char letter;
	
	inFile >> letter;
	while (inFile.good()) {		
		letter = tolower(letter);          //Go through file
		if (alphabet.count(letter) == 0) {			//If the char is not a letter, add it to the key '0'
			++alphabet['?'];
		}
		else {
			it = alphabet.find(letter);
			++it->second;
		}
		inFile >> letter;
	}
	for (it = alphabet.begin(); it != alphabet.end(); ++it) {		//Print result
		if (it->second != 0) {
			cout << it->first << ":  " << it->second << endl;
		}
	}
}


vector<Temps> readTemperatureFileToVector() {
	ifstream inFile;
	inFile.open("temperatures.txt");
	if (inFile.fail()) {
		cerr << "Failed to open temperatures.txt";
		exit(1);
	}
	Temps t = { 0, 0 }; vector<Temps> temperatureVector;

	while (!inFile.eof()) {
		inFile >> t;
		temperatureVector.push_back(t);				//tempVec = {Temppar1, temppar 2 ... }
	}
	inFile.close();
	return temperatureVector;
}

void printTemperatureVector(vector<Temps> temperatureVector) {
	for (int temp = 0; temp < temperatureVector.size(); ++temp) temperatureVector[temp].printTemps();
}
















// IKKE EN DEL AV ØVING
void countOnlyPresentChar() {
	fstream inFile; 
	char letter;
	map<char, int> alphabet; alphabet['A'] = 0;
	map<char, int>::iterator it = alphabet.find('A');//pair<char, int>('A', 0);

	inFile.open("grunnlov.txt"); 
	if (inFile.fail()) {
		cerr << "Failed to open";
		exit(1);
	}
	inFile >> letter;
	while (inFile.good()) {
		letter = tolower(letter);
		if (alphabet.count(letter) == 0) {					//Om bokstaven ikke finnes i oversikten, legger den til
			alphabet.insert(pair<char, int>(letter, 1));
		}
		else {
			it = alphabet.find(letter);						//Om bokstaven finnes, øker den verdien med 1
			it->second = it->second + 1;
		}
		inFile >> letter;
	}
	for (it = alphabet.begin(); it != alphabet.end(); ++it)	// Show result
		cout << it->first << ":  " << it->second << endl;
	inFile.close();
}
