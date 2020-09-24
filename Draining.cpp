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
      count--;
    }else{
        cout<<"File wasn`t opened!aaaaaaa";
    }
    fin.close();
    numberSeriesInFileS.push_back(count);
}
}

void Draining::funcForMerging(){
  int indexFileForMerge;//index of the file to merge
  int* positions;
  positions =  new int[numberSeriesInFileS.size()];
  for(int i =0; i <numberSeriesInFileS.size(); i++){
    positions[i] = 0;
  }
  numberSeriesInFile();
  for(int i =0; i < numberSeriesInFileS.size(); i++){
      if(numberSeriesInFileS[i] == 0){
        indexFileForMerge = i;
        break;
      }
    }
  numberSeriesInFileS.clear();
  while(result() != true){
    vector<int> sources;//merge file indexes
    for(int i =0; i < numberSeriesInFileS.size(); i++){
      if(numberSeriesInFileS[i] != indexFileForMerge){
        sources.push_back(i);
      }
    }
    ifstream in0, in1, in2;//files that we merge
    in0.open(this->Files.setFiles[sources[0]]);
    in1.open(this->Files.setFiles[sources[1]]);
    in2.open(this->Files.setFiles[sources[2]]);
    in0.seekg(positions[sources[0]],ios::beg);
    in1.seekg(positions[sources[1]],ios::beg);
    in2.seekg(positions[sources[2]],ios::beg);
    ofstream out;//in this file merge
    out.open(this->Files.setFiles[indexFileForMerge]);
    int minimum = minNumberSeries();
    int indexNextFileForMerg =0;
    for(int i =0; i < sources.size(); i ++){
      if(minimum == sources[i]){
        indexNextFileForMerg = sources[i];
        break;
      }
    }
    int count =0;//number merged series
    string boof0, boof1, boof2;
    int num0, num1, num2;
      getline(in0,boof0,'\n');
      getline(in1,boof1,'\n');
      getline(in2,boof2,'\n');
    while(count != minimum){
      if(boof0=="."){
        num0 = maxNumber;
      }else{
        num0 = atoi(boof0.c_str());
      }
      if(boof1=="."){
        num1 = maxNumber;
      }else{
        num1 = atoi(boof1.c_str());
      }
      if(boof2=="."){
        num2 = maxNumber;
      }else{
        num2 = atoi(boof2.c_str());
      }

     // here will be the merge process series
    //
    //
    //
     if(boof2=="." && boof0=="." && boof1=="."){
       count++;
     }
    boof0 = "";
    boof1 = "";
    boof2 = "";
    }
    positions[sources[0]] = in0.tellg();
    positions[sources[1]] = in1.tellg();
    positions[sources[2]] = in2.tellg();
    positions[indexFileForMerge] =0;
    indexFileForMerge = indexNextFileForMerg;
    sources.clear();
    in0.close(); in1.close(); in2.close(); out.close();
    numberSeriesInFileS.clear();
  }
}

int Draining::minNumberSeries(){
   int minimum = this->maxNumber;
   for(int i =0; i < this->numberSeriesInFileS.size(); i++){
     if(this->numberSeriesInFileS[i]>0 && this->numberSeriesInFileS[i]<=minimum)
     minimum = this->numberSeriesInFileS[i];
   }
   return minimum;
}

bool Draining::result(){
  numberSeriesInFile();
  int count = 0;
  for(int i = 0; i < numberSeriesInFileS.size(); i++){
    if(numberSeriesInFileS[i] == 0){
       count++;
    }
  }
  if(count == numberSeriesInFileS.size()-1){
    return true;
  }
  return false;
}





