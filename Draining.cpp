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
    ifstream in[3];//files that we merge
    in[0].open(this->Files.setFiles[sources[0]]);
    in[1].open(this->Files.setFiles[sources[1]]);
    in[2].open(this->Files.setFiles[sources[2]]);
    in[0].seekg(positions[sources[0]],ios::beg);
    in[1].seekg(positions[sources[1]],ios::beg);
    in[2].seekg(positions[sources[2]],ios::beg);
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
    string s[3];
    while(count != minimum){
      int x[3];// number from file
    bool b[3];//was x[i] actually read
    for(int i = 0; i < 3; i++)
      b[i] = !!getline(in[i], s[i]);
    for(int i = 0; i < 3; i++)
      if(s[i] == ".")
        b[i] = 0;
      else
        x[i] = stoi(s[i]);
      
    while(b[0] || b[1] || b[2])
    {
      int index = 0;
      if(b[1] && (!b[index] || x[index] > x[1])) index = 1;
      if(b[2] && (!b[index] || x[index] > x[2])) index = 2;
      out << x[index] << '\n';
      b[index] = !!getline(in[index], s[index]);
      if(s[index] == ".")
        b[index] = 0;
      else
        x[index] = stoi(s[index]);
    }
    out << ".\n";
      count++;
    }
    positions[sources[0]] = in[0].tellg();
    positions[sources[1]] = in[1].tellg();
    positions[sources[2]] = in[2].tellg();
    positions[indexFileForMerge] =0;
    indexFileForMerge = indexNextFileForMerg;
    sources.clear();
    in[0].close(); in[1].close(); in[2].close(); out.close();
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





