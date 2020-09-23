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
 void funcForMerging();
 bool result();
 
 ReadDevide Files;
 vector<int> numberSeriesInFileS;
 
};