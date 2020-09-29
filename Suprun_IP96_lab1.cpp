#include<iostream>
#include<istream>
#include<string>
#include<fstream>
#include<vector>

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
  int count = 0;//для серій які вже злили
  vector<int>indexMerge;
  int minSeries = calculationMinNumberSeries();
  int index;//куди зливають
  int positions[numberHelpFiles];
  for(int i =0; i < numberHelpFiles; i++){
    positions[i] = 0;
  }
  while (!checkResult()){
    
    for(int i =0; i < numberHelpFiles; i++){//файли які зливають
      if(arraySeries[i] != 0){
         indexMerge.push_back(i);
      }else{
        index = i;
        }
    }
    ifstream read[indexMerge.size()];
    ofstream write0;
    write0.open(setFiles[index]);
    cout<<setFiles[index];
    write0.seekp(0,ios::beg);
    for(int i =0; i < indexMerge.size(); i++){//відкриваємо ці файли й переносимо покажчики
      read[i].open(setFiles[indexMerge[i]]);
      read[i].seekg(positions[indexMerge[i]],ios::beg);
    }
    while(count<minSeries){//зливаємо серії
      bool needRead[indexMerge.size()];//чи потрібно читати далі
      int setNumber[indexMerge.size()];//прочитаний набір чисел
      for(int i =0; i < indexMerge.size(); i++){//початкове читання набору
        needRead[i] = false;
        string boof;
          getline(read[i], boof);
          if(boof == "."){
            setNumber[i] = maxNumber;
            needRead[i] = false;
          }else{
            setNumber[i]=atoi(boof.c_str());
            needRead[i] = false;
          }
      }
      int k =0;
      while (k<indexMerge.size()){//порівнюємо числа
      //cout<<777;
      k =0;
         for(int i =0; i < indexMerge.size(); i++){//читаємо число або пусту серію
        if(needRead[i] == true){
          string boof;
          getline(read[i], boof);
          if(boof == "."){
            setNumber[i] = maxNumber;
            needRead[i] = false;
          }else{
            setNumber[i]=atoi(boof.c_str());
            needRead[i] = false;
          }
        }
        }
         int minNumber;
         for(int i =0; i < indexMerge.size(); i++){
           if(indexMerge[i] != maxNumber){
             minNumber = indexMerge[i];
           }
         }
         int j;
         for (int i = 0; i < indexMerge.size(); i++){
           if(setNumber[i]<=minNumber && setNumber[i] != maxNumber){
             minNumber = setNumber[i];
             j =i;
           }
         }
         if(setNumber[j] != maxNumber){
           needRead[j] = true;
         write0<<to_string(minNumber)<<"\n";
         write0<<9999;
         cout<<minNumber;
         }

        for(int i =0; i < indexMerge.size(); i++){
        if(setNumber[i] == maxNumber)
        k++;
        }
        if(k == indexMerge.size())
          break;
      }
      count++;
    }
    ///
    for(int i =0; i < indexMerge.size(); i++){//закриваємо ці файли, віднімаємо серії, оновлюємо покажчики
      read[i].close();
      arraySeries[indexMerge[i]]-=minSeries;
      positions[indexMerge[i]] = read[i].tellg();
    }
    arraySeries[index] = minSeries;
    write0.close();
    positions[index] = 0;
    minSeries = calculationMinNumberSeries();
    indexMerge.clear();
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