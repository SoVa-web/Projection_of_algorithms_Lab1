#include<iostream>
#include"ReadDevide.h"
#include"Draining.h"

using namespace std;

int main(){
  string name = "smallTest.txt";
  ReadDevide firstPhase(name);
  firstPhase.numberSequences();
  vector<int> sequence = firstPhase.sequenceFibonacci();
  /*for(int j =0; j < sequence.size(); j++){
    cout<<sequence[j]<<endl;
  }*/
  firstPhase.devideForFirstPhase(sequence);
  Draining Drain(firstPhase);
  Drain.numberSeriesInFile();
  for(int j =0; j <Drain.numberSeriesInFileS.size(); j++){
    cout<<Drain.numberSeriesInFileS[j]<<endl;
  }
}