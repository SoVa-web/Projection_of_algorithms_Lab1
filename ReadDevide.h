#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

 class ReadDevide{
 public:
  ReadDevide(string name);
  void numberSequences();//number of sequences in the source file
  vector<int>sequenceFibonacci();
  void devideForFirstPhase(vector<int> sequence);
  

string name;
string file1;
string file2;
string file3;
string file4;//file for merging streams in first phase
vector<string> setFiles;
const int numberFiles = 4;
int numberStartSeries;
int numberEmptySeries;
 };