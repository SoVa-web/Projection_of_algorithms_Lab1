#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"ReadDevide.h"

class Draining{

public:
Draining(){};
 Draining(ReadDevide& StartFiles);
 void numberSeriesInFile();

 
 ReadDevide Files;
 vector<int> numberSeriesInFileS;
 
};