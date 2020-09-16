#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

 class ReadDevide{
 public:
  ReadDevide(string name);
  int numberSequences(string title);//number of sequences in the source file
  vector<int>sequenceFibonacci(int numberSeries);
  

string name;
string file1;
string file2;
string file3;
string file4;//file for merging streams in first phase
const int numberFiles = 4;
 };