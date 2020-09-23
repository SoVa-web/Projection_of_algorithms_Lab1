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
  //Drain.numberSeriesInFile();
  /*for(int j =0; j <Drain.numberSeriesInFileS.size(); j++){
    cout<<Drain.numberSeriesInFileS[j]<<endl;
  }*//*Drain.numberSeriesInFile();
  Drain.checkFull();
  cout<<Drain.fullFile[0]<<endl;
    cout<<Drain.fullFile[1]<<endl;
    cout<<Drain.fullFile[2]<<endl;
    cout<<Drain.fullFile[3]<<endl;*/
  Drain.algorithm();
  
}