#include<iostream>
#include<istream>
#include"ReadDevide.h"
#include"Draining.h"

using namespace std;

int main(){
  string name = "smallTest.txt";
  ReadDevide firstPhase(name);
  firstPhase.numberSequences();
  vector<int> sequence = firstPhase.sequenceFibonacci();
  firstPhase.devideForFirstPhase(sequence);
  Draining Drain(firstPhase);
  ifstream fin;
  fin.open(name);
  string a;
  getline(fin,a,' ');
  //cout<<a<<77777<<endl;
  int b = fin.tellg();
  //cout<<b<<endl;
  a = "";
  fin.close();
  ifstream in;
  in.open(name);
  in.seekg(b,ios::beg);
  getline(in,a,' ');
  //cout<<a<<77777<<endl;
  in.close();

}