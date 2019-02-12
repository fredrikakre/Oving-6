#include "std_lib_facilities.h"
#include "fileFunctions.h"
#include "catalog.h"

void testCatalog();
void testTemps();

int main(){
	//writeToFile("Oppgaveb.txt");
	//countChar();
	testTemps();
	return 0;
}

void testCatalog() {
	map<string, string> fag;
	/*fag["C++"] = "Er totalt piss"; fag["Viro"] = "kjekk"; fag["Elsie"] = "Gay cover";
	CourseCatalog catalog = {fag};
	catalog << catalog;*/
	CourseCatalog catalog = { fag };
	catalog.addExamples();
	//catalog.addCourse("TDT4112", "C++");
	catalog.printAll();
	catalog.openFile();
}

void testTemps() {
	vector<Temps> temperatureVector = readTemperatureFileToVector();
	printTemperatureVector(temperatureVector);
}





/* MAP FUNKSJONER
map<key type, value type> myMap;

myMap[key] = value;
myMap.insert(pair<type1, type2>(key, value));		(std::pair)

myMap.clear()
myMap.size()
myMap.erase(key)
myMap.erase(it)  //Dersom man har brukt it = myMap.find(key); 
myMap.empty()		//true if empty, otherwise false

for (map<int, string>::iterator it = myMap.begin(); it != myMap.end(); ++it)		//Iterate
	cout << it -> first << "  " << it->second << endl;

it -> first ( key) og it -> second (value). Iterator lagrer paret. 


map<int, string>::iterator it = myMap.find(key);						//Search: Stores the value in the iterator
cout << "Value for this key = " << it->second << endl;





FILER.
#include <fstream>

ofstream filobjekt;						//ofstream = skrive, ifstream = lese; fstream = begge (output og input)
filobjekt.open("filnavn.txt")
filobjekt << "Det du vil skrive";
filobjekt.close()



LES FRA FIL ORD FOR ORD              Bruk while(getline(filobjekt, line)) for å få hele linjer
Char filnavn[50];
ifstream filobjekt;
cin.getline(filnavn, 500);
filobjekt.open(filnavn)

if(!filobjekt.is_open()){			//Exit om den ikke klarer å åpne fila som ble bedt om. Exit greia er fra cstdlib
	exit(EXIT_FAILURE)
	}
ELLER
if(filobjekt.fail()) {
	cerr << "Error opening file" << endl;
	exit(1);
	}

char ord[50];					//Trenger å lagre verdien av ordene et sted
			
while (filobjekt.good()) {		//Går gjennom filen
	filobjekt >> ord;
	cout << ord << " ";


filobjekt.eof()  : returnerer true derom det er slutten av fila (eof = end of file)




STRINGSTREAM FUNKSJONER
Kan ha alt av int / char / string osv.

stringstream sso;
sso << "Inpput";
cout << sso; (Gir lagringslokasjon)
cout << sso.str;  (Gir stringen)

sso.clear()   (Fjerner error)
sso.str("");  Fjerner lagret tekst 

STRINGSTREAM OG Lese FRA FIL:
while (getline (fileobject, lineInFileString)) {
	sso << lineInFileString << endl;
	}
fileobject.close()
cout << sso.str();
*/