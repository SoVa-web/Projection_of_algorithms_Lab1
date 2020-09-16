#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"ReadDevide.h"

using namespace std;

class Draining{

public:
Draining(){};
 Draining(ReadDevide& StartFiles);
 void numberSeriesInFile();

 
 ReadDevide Files;
 vector<int> numberSeriesInFileS;
 
};