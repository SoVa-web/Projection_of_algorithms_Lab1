#include<iostream>
#include<istream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdio>
#include<stdlib.h>

using namespace std;

class SystemOfFiles{
  public:
   //func
   SystemOfFiles(int number, string name);
   void numberSequences();
   vector<int> sequenceFibonacci();
   void devideFirstPhase();
   void calculationSeries();
   int calculationMinNumberSeries();
   void merging();
   bool checkResult();

   //variables
   int numberHelpFiles;
   string startFile;
   string* setFiles;
   int numberStartSeries;
   vector<int> sequence;
   int* arraySeries;
   string result;
   int maxNumber = 1000000;

};

SystemOfFiles::SystemOfFiles(int number, string name){
numberHelpFiles = number;
startFile = name;
setFiles = new string[numberHelpFiles];
for(int i =0; i < numberHelpFiles; i++){
  string boof = "";
  boof = "helpFile"+to_string(i)+".txt";
  setFiles[i] = boof;
}
}

void SystemOfFiles::numberSequences(){
    int number = 1;//number sequences 
    int boof1, boof2; 
    ifstream fin;
    fin.open(this->startFile);
        fin>>boof1;
      while(!fin.eof()){
      fin>>boof2;
      if(boof2<=boof1){
       number++;}
      boof1=boof2;}
    fin.close();
    this->numberStartSeries = number;
}

vector<int> SystemOfFiles::sequenceFibonacci(){
    int degreeFibonacci = this->numberHelpFiles-2;//using formul p = m-2, m - number files, p - degree Fibonacci
    for(int i =0; i < degreeFibonacci; i++){
       sequence.push_back(0);}
    sequence.push_back(1);
    while(sequence[sequence.size()-1]<this->numberStartSeries){
        int n = 0;
        int t = 0;
        for(int i =0; i < degreeFibonacci+1; i++){
            n+=(sequence[sequence.size()-1-t]);
            t++;}
        sequence.push_back(n);}
    //this->numberEmptySeries = sequence[sequence.size()-1] - this->numberStartSeries;
    return sequence;
}

void SystemOfFiles::devideFirstPhase(){
  ifstream reading;
  reading.open(this->startFile);
  ofstream write[this->numberHelpFiles];
  for (int i = 0; i < this->numberHelpFiles; i++){
    write[i].open(this->setFiles[i]);
  }
  int boof1, boof2;
  reading>>boof1;
  int t =1;
  int count=0;
  bool lastNumber = false;
  //write[0]<<boof1<<"\n";
  for(int i =0; i < this->numberHelpFiles-1; i++){
   // cout<<t<<"t\n";
    count=0;
     while(count<sequence[sequence.size()-t-1]){
       //cout<<"n"<<sequence[sequence.size()-t-1]<<endl;
       if(reading.eof() && !lastNumber){//for last number
       write[i]<<boof2<<"\n";
       write[i]<<".\n";
       count++;
       lastNumber=true;
         break;
       }
       if(reading.eof()){
         break;
       }
       write[i]<<boof1<<"\n";
       reading>>boof2;
         if(boof2<=boof1){
           count++;
            write[i]<<".\n"; }   
            boof1=boof2;                         
     }
     while(count<sequence[sequence.size()-t-1]&&reading.eof()){
       count++;
       write[i]<<".\n";
     } 
    t++;
  }
   for(int i = 0; i < this->numberHelpFiles; i++){
    write[i].close();
  }
  reading.close();
}

void SystemOfFiles::calculationSeries(){
  arraySeries = new int[numberHelpFiles];
  ifstream read[numberHelpFiles];
  for(int i =0; i < numberHelpFiles;i++){
    read[i].open(setFiles[i]);
  }
  for(int i =0; i <numberHelpFiles; i++){
    int count =0;
    while (!read[i].eof()){
      if(read[i].eof())
      break;
      string boof;
      getline(read[i], boof);
      if(boof == ".")
       count++;
    }
    arraySeries[i]=count;
  }
  for(int i =0; i < numberHelpFiles;i++){
    read[i].close();
  }
}

int SystemOfFiles::calculationMinNumberSeries(){
int minimum;
for(int i=0; i < numberHelpFiles;i++){
  if(arraySeries[i] != 0){
    minimum= arraySeries[i];
    break;
  }
}
for(int i=0; i < numberHelpFiles;i++){
  if(arraySeries[i]>0 && arraySeries[i]<=minimum){
    minimum = arraySeries[i];
  }
}
return minimum;
}

void SystemOfFiles::merging(){
  int p =0;
  int count = 0;
  vector<int>indexMerge;
  bool needRead[numberHelpFiles];
  int setNumber[numberHelpFiles];
  for(int i =0; i < numberHelpFiles; i++){
    needRead[i] = true;
    setNumber[i] = maxNumber;
  }
  int minSeries = calculationMinNumberSeries();
  int index;//file for merge
  int positions[numberHelpFiles];
  for(int i =0; i < numberHelpFiles; i++){
    positions[i] = 0;
  }
  fstream file[numberHelpFiles];
  while (!checkResult()){
    count = 0;
    for(int i =0; i < numberHelpFiles; i++){
      if(arraySeries[i] != 0){
         indexMerge.push_back(i);
      }else{
        index = i;
        }
    }
    file[index].open(setFiles[index], ios::out);
    file[index].seekp(0,ios::beg);
    for(int i =0; i < indexMerge.size(); i++){
      file[indexMerge[i]].open(setFiles[indexMerge[i]], ios::in);
      needRead[indexMerge[i]] = false;
        string boof;
          getline(file[indexMerge[i]], boof);
          if(boof == "." ){
            setNumber[indexMerge[i]]=maxNumber;
          }else{
            setNumber[indexMerge[i]]=atoi(boof.c_str());
          }
    }
    while(count<minSeries){//merge series
      int k =0;
      while (k != indexMerge.size()){//compare numbers
      k=0;
      for (int  i = 0; i < indexMerge.size(); i++){
        if(needRead[indexMerge[i]]){
         string boof;
          getline(file[indexMerge[i]], boof);
          if(boof == "."){
            setNumber[indexMerge[i]] = maxNumber;
            needRead[indexMerge[i]] = false;
          }else{
            setNumber[indexMerge[i]]=atoi(boof.c_str());
            needRead[indexMerge[i]] = false;
          }
        }
      }
      int minIn, minNum = setNumber[0];
      for(int i =0; i < indexMerge.size(); i++){
        if(minNum>=setNumber[indexMerge[i]]){
          minNum = setNumber[indexMerge[i]];
          minIn = indexMerge[i];
        }
      }
      if(minNum != maxNumber && !needRead[minIn]){
        file[index]<<minNum<<"\n";
        needRead[minIn] = true;
      }
      for (int i = 0; i < indexMerge.size(); i++){
        if(setNumber[indexMerge[i]] == maxNumber)
        k++;
      }
      if(k == indexMerge.size()){
        for (int i = 0; i < indexMerge.size(); i++){
         needRead[indexMerge[i]] = true;
      }
      }
      }
      file[index]<<"."<<"\n";
      for(int i =0; i < indexMerge.size(); i++){
        file[indexMerge[i]].sync();
      }
      count++;
    }
    for(int i =0; i < indexMerge.size(); i++){
      arraySeries[indexMerge[i]]-=minSeries;
      string a = to_string(i)+".txt";
      string b;
      fstream n;
      n.open(a, ios::out);
      while (!file[indexMerge[i]].eof()){
        getline(file[indexMerge[i]], b);
        n<<b<<"\n";
      }
      n.close(); file[indexMerge[i]].close();
      n.open(a, ios::in);
      file[indexMerge[i]].open(setFiles[indexMerge[i]], ios::out);
      while (!n.eof()){
        getline(n, b);
        file[indexMerge[i]]<<b<<"\n";
      }
      file[indexMerge[i]].close();
      n.close();
    }
    arraySeries[index] = minSeries;
    file[index].close();
    positions[index] = 0;
    minSeries = calculationMinNumberSeries();
    indexMerge.clear();
    p++;
  }
  cout<<"Sorting array of number in file "<<result;
}

bool SystemOfFiles::checkResult(){
  int count =0;
  for(int i =0; i <numberHelpFiles; i++){
    if(arraySeries[i] == 0){
      count++;
    }
  }
  if(count==numberHelpFiles-1){
    for(int i =0; i <numberHelpFiles; i++){
    if(arraySeries[i] == 1){
      result = setFiles[i];
    }
    }
    return true;
  }
  return false;
}

int main(){
  string name ="smallTest.txt";
  int number = 4;
  SystemOfFiles files(number, name);
  files.numberSequences();
  //cout<<"series"<<files.numberStartSeries<<"\n";
  files.sequenceFibonacci();
 /* for(int i =0; i < files.sequence.size(); i++){
    cout<<files.sequence[i]<<endl;
  }*/
  files.devideFirstPhase();
  files.calculationSeries();
  files.merging();

}