#include"Draining.h"

Draining::Draining(ReadDevide& StartFiles){
 Files = StartFiles;
}

void Draining::numberSeriesInFile(){
for(int i =0 ; i <this->Files.numberFiles; i++){
    int count = 0;
    char point;
    ifstream fin;
    fin.open(this->Files.setFiles[Files.setFiles.size()-1-i]);
    if(fin.is_open()){
      while (!fin.eof()) {
        fin>>point;
        if(point == '.'){
            count++;
        }
      } 
    }else{
        cout<<"File wasn`t opened!";
    }
    fin.close();
    numberSeriesInFileS.push_back(count);
}
}