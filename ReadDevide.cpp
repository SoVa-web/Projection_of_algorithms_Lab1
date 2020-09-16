#include"ReadDevide.h"

ReadDevide::ReadDevide(string name){
    this->name = name;
    this->file1 = "A.txt";
    setFiles.push_back(file1);
    this->file2 = "B.txt";
    setFiles.push_back(file2);
    this->file3 = "C.txt";
    setFiles.push_back(file3);
    this->file4 = "D.txt";
    setFiles.push_back(file4);
}

void ReadDevide::numberSequences(){
    int number = 0;//number sequences 
    int boof1, boof2; 
    ifstream fin;
    fin.open(this->name);
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
    fin.close();
    this->numberStartSeries = number;
}

vector<int> ReadDevide::sequenceFibonacci(){
    vector<int> sequence;
    int degreeFibonacci = this->numberFiles-2;//using formul p = m-2, m - number files, p - degree Fibonacci
    for(int i =0; i < degreeFibonacci; i++){
       sequence.push_back(0);
    }
    sequence.push_back(1);
    while(sequence[sequence.size()-1]<this->numberStartSeries){
        int n = 0;
        int t = 0;
        for(int i =0; i < degreeFibonacci+1; i++){
            n+=(sequence[sequence.size()-1-t]);
            t++;
        }
        sequence.push_back(n);
    }
    this->numberEmptySeries = sequence[sequence.size()-1] - this->numberStartSeries;
    return sequence;
}

void ReadDevide::devideForFirstPhase(vector<int> sequence){
    int boof1, boof2;
    int now = 0;
    int t =1;
    ifstream fin;
    fin.open(this->name);
    if(fin.is_open()){
    fin>>boof1;
      for(int i =0; i < setFiles.size()-1; i++){
        now =0;
        ofstream fout;
        fout.open(setFiles[i]);
        if(fout.is_open()){//open start file
             if(t == 1){
                 fout<<boof1;
                  while(now<=sequence[sequence.size()-t-1] ){
                         if(!fin.eof()){
                              fin>>boof2;
                          if(boof2<=boof1){
                          now++;
                          fout<<" . ";
                          }
                        boof1=boof2;
                        fout<<boof1;
                        fout<<" ";}}
                             fout<<" . ";
                             now++;
             }else{
                  while(now<sequence[sequence.size()-t-1] ){
                    if(!fin.eof()){
                        fin>>boof2;
                     if(boof2<=boof1){
                        now++;
                        fout<<" . ";
                         }
                     boof1=boof2;
                     fout<<boof1;
                     fout<<" ";
                    }else{
                        fout<<" . ";
                        now++;
                    } } }}
        fout.close();
        t++; }
     fin.close();}
     ofstream fout;
     fout.open(this->setFiles[this->setFiles.size()-1]);
     fout.close();
}