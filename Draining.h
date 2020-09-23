#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include <stdlib.h>
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
 void mergeInFirst();
 void mergeInSecond();
 void mergeInThird();
 void mergeInFourth();
 void algorithm();
 

 
 ReadDevide Files;
 vector<int> numberSeriesInFileS;
 bool* fullFile;
};