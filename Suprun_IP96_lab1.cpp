#include<iostream>
#include"ReadDevide.h"

using namespace std;

int main(){
  string name = "smallTest.txt";
  ReadDevide firstPhase(name);
  int i = firstPhase.numberSequences(name);
  cout<<i;
}