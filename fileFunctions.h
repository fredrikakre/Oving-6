#pragma once
#include "catalog.h"

void writeToFile(string filename);
void addLineNumber();
void countOnlyPresentChar();
void countChar();
vector<Temps> readTemperatureFileToVector();
void printTemperatureVector(vector<Temps> temperatureVector);