#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include"ReadDevide.h"

using namespace std;

class Draining{

public:
Draining(){};
 Draining(ReadDevide& StartFiles);
 void numberSeriesInFile();
 void draining();
 void checkFull();
 int minMerg();
 

 
 ReadDevide Files;
 vector<int> numberSeriesInFileS;
 bool* fullFile;
};