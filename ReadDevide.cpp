#include"ReadDevide.h"

ReadDevide::ReadDevide(string name){
    this->name = name;
    this->file1 = "A.txt";
    this->file2 = "B.txt";
    this->file3 = "C.txt";
    this->file4 = "D.txt";
}

int ReadDevide::numberSequences(string title){
    int number = 0;//number sequences 
    int boof1, boof2; 
    ifstream fin;
    fin.open(title);
    if(fin.is_open()){
        fin>>boof1;
      while(!fin.eof()){
      fin>>boof2;
      if(boof2<=boof1){
       number++;
      }
      boof1=boof2;
      }
    }else{
        cout<<"File wasn`t opened!";
    }
    return number;
}