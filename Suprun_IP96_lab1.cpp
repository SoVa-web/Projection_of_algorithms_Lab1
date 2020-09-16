#include<iostream>
#include"ReadDevide.h"

using namespace std;

int main(){
  string name = "smallTest.txt";
  ReadDevide firstPhase(name);
  int i = firstPhase.numberSequences(name);
  vector<int> sequence = firstPhase.sequenceFibonacci(i);
  for(int j =0; j < sequence.size(); j++){
    cout<<sequence[j]<<endl;
  }
}