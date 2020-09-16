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

vector<int> ReadDevide::sequenceFibonacci(int numberSeries){
    vector<int> sequence;
    int degreeFibonacci = this->numberFiles-2;//using formul p = m-2, m - number files, p - degree Fibonacci
    for(int i =0; i < degreeFibonacci; i++){
       sequence.push_back(0);
    }
    sequence.push_back(1);
    while(sequence[sequence.size()-1]<numberSeries){
        int n = 0;
        int t = 0;
        for(int i =0; i < degreeFibonacci+1; i++){
            n+=(sequence[sequence.size()-1-t]);
            t++;
        }
        sequence.push_back(n);
    }
    return sequence;
}