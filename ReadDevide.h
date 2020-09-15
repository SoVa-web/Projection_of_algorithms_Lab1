#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

 class ReadDevide{
 public:
  ReadDevide(string name);
  int numberSequences();//number of sequences in the source file

string name;
string file1;
string file2;
string file3;
string file4;//file for merging streams in first phase
 };