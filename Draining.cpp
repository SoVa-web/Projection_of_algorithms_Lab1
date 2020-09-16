#include"Draining.h"

Draining::Draining(ReadDevide& StartFiles){
 Files = StartFiles;
}

void Draining::numberSeriesInFile(){
for(int i =0 ; i <this->Files.numberFiles; i++){
    int count = 0;
    char point;
    ifstream fin;
    fin.open(this->Files.setFiles[i]);
    if(fin.is_open()){
      while (!fin.eof()) {
        fin>>point;
        if(point == '.'){
            count++;
        }
      } 
    }else{
        cout<<"File wasn`t opened!aaaaaaa";
    }
    fin.close();
    numberSeriesInFileS.push_back(count);
}
}

int Draining::minMerg(){
    int h;
    for(int i =0; i < this->Files.numberFiles;i++){
      if(numberSeriesInFileS[i] != 0){
          h = numberSeriesInFileS[i];
      }
    }
     for(int i =0; i < this->Files.numberFiles;i++){
      if(numberSeriesInFileS[i] != 0 && h > numberSeriesInFileS[i]){
          h = numberSeriesInFileS[i];
      }
    }
    cout<<h<<endl;
    return h;
}

void Draining::draining(){
    const int maximum = 1000000;
    int numberMerg = minMerg();
    int count1  =0,  count2 = 0, count3 = 0;
    for(int i =0; i < this->Files.numberFiles;i++){
        if(!fullFile[i]){//open for writing this file
           ofstream fout;
           fout.open(this->Files.setFiles[i]);
           if(fout.is_open()){
               //merge the series, I don't know how yet
           }else{
               cout<<"File not opened"<<endl;
           }
           fout.close();
        }
    }
}

void Draining::checkFull(){
    fullFile = new bool[4];
    for(int j = 0; j<this->Files.numberFiles;j++){
        fullFile[j] = true;
    }
    for(int i =0; i < this->numberSeriesInFileS.size(); i++){
        if(this->numberSeriesInFileS[i] == 0){
            fullFile[i] = false;
          break;
        }
    }
}