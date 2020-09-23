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
    return h;
}

void Draining::mergeInFirst(){
    const int maximum = 1000000;
    int numberMerg = minMerg();
    int count = 0;
     string boof0 = ""; string boof1 =""; string boof2=""; string boof3="";
    int number0 = maximum; int number1 = maximum; int number2 = maximum; int number3 = maximum;
    char point1 = 'o'; char point2 = 'o'; char point3 = 'o'; char point0 = 'o';
    bool statusNumber1; bool statusNumber2; bool statusNumber3; bool statusNumber0;
    statusNumber1=false; statusNumber2=false; statusNumber3=false; statusNumber0=false;
    ofstream fout;
           fout.open(this->Files.setFiles[0]);
                ifstream in1, in2, in3;
                in1.open(this->Files.setFiles[1]); in2.open(this->Files.setFiles[2]); in3.open(this->Files.setFiles[3]);
                while (count != numberMerg){
                     if (!statusNumber1){
                         statusNumber1 = true;
                        in1>>point1;
                        while (point1 != ' ') {
                            boof1+=point1;
                            in1>>point1;}
                        if(boof1 == "."){
                            number1 = maximum;
                            boof1="";
                        }else{
                            number1 = atoi(boof1.c_str());
                            boof1="";}}
                   if (!statusNumber2){
                         statusNumber2 = true;
                        in2>>point2;
                        while (point2 != '_') {
                            boof2+=point2;
                            in2>>point2;}
                        if(boof2 == "."){
                            number2 = maximum;
                            boof2="";
                        }else{
                            number2 = atoi(boof2.c_str());
                            boof2="";}}
                    if (!statusNumber3){
                         statusNumber3 = true;
                        in3>>point3;
                        while (point3 != ' ') {
                            boof3+=point3;
                            in3>>point3;}
                        if(boof3 == "."){
                            number3 = maximum;
                            boof3="";
                        }else{
                            number3 = atoi(boof3.c_str());
                            boof3="";}}
                   if(statusNumber1 && statusNumber2 &&  statusNumber3){
                       if((number1 <=number3 && number3<=number2 && number1 != maximum)||(number1 <=number2 && number2<=number3 && number1 != maximum)){
                            fout<<number1;
                            statusNumber1 = false; }
                       if((number3 <=number2 && number2<=number1 && number3 != maximum)||(number3 <=number1 && number1<=number2 && number3 != maximum)){
                            fout<<number3;
                            statusNumber3 = false; }
                       if((number2 <=number1 && number1<=number3 && number2 != maximum)||(number2 <=number3 && number3<=number1 && number2 != maximum)){
                            fout<<number2;
                            statusNumber2 = false;}} 
                   if(number1 == maximum && number2 == maximum && number3 == maximum ){
                       count++;
                       statusNumber1 = false; statusNumber2 = false; statusNumber3 = false;}}
                string psevdo1, psevdo2, psevdo3;
                psevdo1 = "A1.txt"; psevdo2 = "B1.txt"; psevdo3 = "C1.txt";//rewrite
                ofstream  p1, p2, p3;
                p1.open(psevdo1); p2.open(psevdo2); p3.open(psevdo3);
                while(!in1.eof()){
                    in1>>point1; p1<<point1; }
                while(!in2.eof()){
                    in2>>point2; p2<<point2; }
                while(!in3.eof()){
                    in3>>point3; p3<<point3; }
                p1.close();p2.close();p3.close();in1.close(); in2.close(); in3.close();//back 
                ofstream out1, out2, out3;
                out1.open(this->Files.setFiles[1]); out2.open(this->Files.setFiles[2]); out3.open(this->Files.setFiles[3]);
                ifstream f1, f2, f3;
                p1.open(psevdo1); p2.open(psevdo2); p3.open(psevdo3);
                while(!f1.eof()){
                    f1>>point1; out1<<point1; }
                while(!f2.eof()){
                    f2>>point2; out2<<point2; }
                while(!f3.eof()){
                    f3>>point3; out3<<point3; }
                f1.close();f2.close();f3.close();out1.close(); out2.close(); out3.close();
               fout.close();
}

void Draining::mergeInSecond(){
     const int maximum = 1000000;
    int numberMerg = minMerg();
    int count = 0;
     string boof0 = ""; string boof1 =""; string boof2=""; string boof3="";
    int number0 = maximum; int number1 = maximum; int number2 = maximum; int number3 = maximum;
    char point1 = 'o'; char point2 = 'o'; char point3 = 'o'; char point0 = 'o';
    bool statusNumber1; bool statusNumber2; bool statusNumber3; bool statusNumber0;
    statusNumber1=false; statusNumber2=false; statusNumber3=false; statusNumber0=false;
    ofstream fout;
           fout.open(this->Files.setFiles[1]);
                ifstream in0, in2, in3;
                in0.open(this->Files.setFiles[0]); in2.open(this->Files.setFiles[2]); in3.open(this->Files.setFiles[3]);
                while (count != numberMerg){
                    if (!statusNumber0){
                         statusNumber0 = true;
                        in0>>point0;
                        while (point0 != ' ') {
                            boof0+=point0;
                            in0>>point0;}
                            
                        if(boof0 == "."){
                            number0 = maximum;
                            boof0="";
                        }else{
                            number0 = atoi(boof0.c_str());
                            boof0="";}}
                    if (!statusNumber2){
                         statusNumber2 = true;
                        in2>>point2;
                        while (point2 != '_') {
                            boof2+=point2;
                            in2>>point2;}
                        if(boof2 == "."){
                            number2 = maximum;
                            boof2="";
                        }else{
                            number2 = atoi(boof2.c_str());
                            boof2="";}}
                    if (!statusNumber3){
                         statusNumber3 = true;
                        in3>>point3;
                        while (point3 != ' ') {
                            boof3+=point3;
                            in3>>point3;}
                        if(boof3 == "."){
                            number3 = maximum;
                            boof3="";
                        }else{
                            number3 = atoi(boof3.c_str());
                            boof3="";}}
                   if(statusNumber0 && statusNumber2 &&  statusNumber3){
                       if((number0 <=number3 && number3<=number2 && number0 != maximum)||(number0 <=number2 && number2<=number3 && number0 != maximum)){
                            fout<<number0;
                            statusNumber0 = false; }
                       if((number3 <=number2 && number2<=number0 && number3 != maximum)||(number3 <=number0 && number0<=number2 && number3 != maximum)){
                            fout<<number3;
                            statusNumber3 = false; }
                       if((number2 <=number0 && number0<=number3 && number2 != maximum)||(number2 <=number3 && number3<=number0 && number0 != maximum)){
                            fout<<number2;
                            statusNumber2 = false;}} 
                   if(number0 == maximum && number2 == maximum && number3 == maximum ){
                       count++;
                       statusNumber0 = false; statusNumber2 = false; statusNumber3 = false;}}
                string psevdo0, psevdo2, psevdo3;
                psevdo0 = "A1.txt"; psevdo2 = "B1.txt"; psevdo3 = "C1.txt";//rewrite
                ofstream  p0, p2, p3;
                p0.open(psevdo0); p2.open(psevdo2); p3.open(psevdo3);
                while(!in0.eof()){
                    in0>>point0; p0<<point0; }
                while(!in2.eof()){
                    in2>>point2; p2<<point2; }
                while(!in3.eof()){
                    in3>>point3; p3<<point3; }
                p0.close();p2.close();p3.close();in0.close(); in2.close(); in3.close();//back 
                ofstream out0, out2, out3;
                out0.open(this->Files.setFiles[0]); out2.open(this->Files.setFiles[2]); out3.open(this->Files.setFiles[3]);
                ifstream f0, f2, f3;
                p0.open(psevdo0); p2.open(psevdo2); p3.open(psevdo3);
                while(!f0.eof()){
                    f0>>point0; out0<<point0; }
                while(!f2.eof()){
                    f2>>point2; out2<<point2; }
                while(!f3.eof()){
                    f3>>point3; out3<<point3; }
                f0.close();f2.close();f3.close();out0.close(); out2.close(); out3.close();
               fout.close();
}

void Draining::mergeInThird(){
    const int maximum = 1000000;
    int numberMerg = minMerg();
    int count = 0;
     string boof0 = ""; string boof1 =""; string boof2=""; string boof3="";
    int number0 = maximum; int number1 = maximum; int number2 = maximum; int number3 = maximum;
    char point1 = 'o'; char point2 = 'o'; char point3 = 'o'; char point0 = 'o';
    bool statusNumber1; bool statusNumber2; bool statusNumber3; bool statusNumber0;
    statusNumber1=false; statusNumber2=false; statusNumber3=false; statusNumber0=false;
    ofstream fout;
           fout.open(this->Files.setFiles[2]);
                ifstream in1, in0, in3;
                in1.open(this->Files.setFiles[1]); in0.open(this->Files.setFiles[0]); in3.open(this->Files.setFiles[3]);
                while (count != numberMerg){
                    if (!statusNumber1){
                         statusNumber1 = true;
                        in1>>point1;
                        while (point1 != ' ') {
                            boof1+=point1;
                            in1>>point1;}
                        if(boof1 == "."){
                            number1 = maximum;
                            boof1="";
                        }else{
                            number1 = atoi(boof1.c_str());
                            boof1="";}}
                    if (!statusNumber0){
                         statusNumber0 = true;
                        in0>>point0;
                        while (point0 != ' ') {
                            boof0+=point0;
                            in0>>point0;}
                        if(boof0 == "."){
                            number0 = maximum;
                            boof0="";
                        }else{
                            number0 = atoi(boof0.c_str());
                            boof0="";}}
                    if (!statusNumber3){
                         statusNumber3 = true;
                        in3>>point3;
                        while (point3 != ' ') {
                            boof3+=point3;
                            in3>>point3;}
                        if(boof3 == "."){
                            number3 = maximum;
                            boof3="";
                        }else{
                            number3 = atoi(boof3.c_str());
                            boof3="";}}
                   if(statusNumber1 && statusNumber0 &&  statusNumber3){
                       if((number1 <=number3 && number3<=number0 && number1 != maximum)||(number1 <=number0 && number0<=number3 && number1 != maximum)){
                            fout<<number1;
                            statusNumber1 = false; }
                       if((number3 <=number0 && number0<=number1 && number3 != maximum)||(number3 <=number1 && number1<=number0 && number3 != maximum)){
                            fout<<number3;
                            statusNumber3 = false; }
                       if((number0 <=number1 && number1<=number3 && number0 != maximum)||(number0 <=number3 && number3<=number1 && number0 != maximum)){
                            fout<<number0;
                            statusNumber0 = false;}} 
                   if(number1 == maximum && number0 == maximum && number3 == maximum ){
                       count++;
                       statusNumber1 = false; statusNumber0 = false; statusNumber3 = false;}}
                string psevdo1, psevdo0, psevdo3;
                psevdo1 = "A1.txt"; psevdo0 = "B1.txt"; psevdo3 = "C1.txt";//rewrite
                ofstream  p1, p0, p3;
                p1.open(psevdo1); p0.open(psevdo0); p3.open(psevdo3);
                while(!in1.eof()){
                    in1>>point1; p1<<point1; }
                while(!in0.eof()){
                    in0>>point0; p0<<point0; }
                while(!in3.eof()){
                    in3>>point3; p3<<point3; }
                p1.close();p0.close();p3.close();in1.close(); in0.close(); in3.close();//back 
                ofstream out1, out0, out3;
                out1.open(this->Files.setFiles[1]); out0.open(this->Files.setFiles[0]); out3.open(this->Files.setFiles[3]);
                ifstream f1, f0, f3;
                p1.open(psevdo1); p0.open(psevdo0); p3.open(psevdo3);
                while(!f1.eof()){
                    f1>>point1; out1<<point1; }
                while(!f0.eof()){
                    f0>>point0; out0<<point0; }
                while(!f3.eof()){
                    f3>>point3; out3<<point3; }
                f1.close();f0.close();f3.close();out1.close(); out0.close(); out3.close();
               fout.close();
}

void Draining::mergeInFourth(){
    const int maximum = 1000000;
    int numberMerg = minMerg();
    int count = 0;
    string boof0 = ""; string boof1 =""; string boof2=""; string boof3="";
    int number0 = maximum; int number1 = maximum; int number2 = maximum; int number3 = maximum;
    char point1 = 'o'; char point2 = 'o'; char point3 = 'o'; char point0 = 'o';
    bool statusNumber1; bool statusNumber2; bool statusNumber3; bool statusNumber0;
    statusNumber1=false; statusNumber2=false; statusNumber3=false; statusNumber0=false;
    ofstream fout;
           fout.open(this->Files.setFiles[3]);
                ifstream in1, in2, in0;
                in1.open(this->Files.setFiles[1]); in2.open(this->Files.setFiles[2]); in0.open(this->Files.setFiles[0]);
                while (count != numberMerg){
                    if (!statusNumber1){
                         statusNumber1 = true;
                        in1>>point1;
                        while (point1 != '_') {cout<<boof1;
                            boof1+=point1;
                            in1>>point1;}
                        if(boof1 == "."){
                            number1 = maximum;
                            boof1 = "";
                        }else{
                            number1 = atoi(boof1.c_str());
                             boof1 ="";}}
                    if (!statusNumber2){
                         statusNumber2 = true;
                        in2>>point2;
                        while (point2 != '_') {
                            boof2+=point2;
                            in2>>point2;}
                        if(boof2 == "."){
                            number2 = maximum;
                            boof2="";
                        }else{
                            number2 = atoi(boof2.c_str());
                            boof2="";}}
                    if (!statusNumber0){
                         statusNumber0 = true;
                        in0>>point0;
                        while (point0 != '_') {
                            boof0+=point0;
                            in0>>point0;}
                        if(boof0 == "."){
                            number0 = maximum;
                            boof0="";
                        }else{
                            number0 = atoi(boof0.c_str());
                            boof0="";}}
                   if(statusNumber1 && statusNumber2 &&  statusNumber0){
                       if((number1 <=number0 && number0<=number2 && number1 != maximum)||(number1 <=number2 && number2<=number0 && number1 != maximum)){
                            fout<<number1;
                            statusNumber1 = false; }
                       if((number0 <=number2 && number2<=number1 && number0 != maximum)||(number0 <=number1 && number1<=number2 && number0 != maximum)){
                            fout<<number0;
                            statusNumber0 = false; }
                       if((number2 <=number1 && number1<=number0 && number2 != maximum)||(number2 <=number0 && number0<=number1 && number2 != maximum)){
                            fout<<number2;
                            statusNumber2 = false;}} 
                   if(number1 == maximum && number2 == maximum && number0 == maximum ){
                       count++;
                       statusNumber1 = false; statusNumber2 = false; statusNumber0 = false;}}
                string psevdo1, psevdo2, psevdo0;
                psevdo1 = "A1.txt"; psevdo2 = "B1.txt"; psevdo0 = "C1.txt";//rewrite
                ofstream  p1, p2, p0;
                p1.open(psevdo1); p2.open(psevdo2); p0.open(psevdo0);
                while(!in1.eof()){
                    in1>>point1; p1<<point1; }
                while(!in2.eof()){
                    in2>>point2; p2<<point2; }
                while(!in0.eof()){
                    in0>>point0; p0<<point0; }
                p1.close();p2.close();p0.close();in1.close(); in2.close(); in0.close();//back 
                ofstream out1, out2, out0;
                out1.open(this->Files.setFiles[1]); out2.open(this->Files.setFiles[2]); out0.open(this->Files.setFiles[0]);
                ifstream f1, f2, f0;
                p1.open(psevdo1); p2.open(psevdo2); p0.open(psevdo0);
                while(!f1.eof()){
                    f1>>point1; out1<<point1; }
                while(!f2.eof()){
                    f2>>point2; out2<<point2; }
                while(!f0.eof()){
                    f0>>point3; out0<<point0; }
                f1.close();f2.close();f0.close();out1.close(); out2.close(); out0.close();
               fout.close();
}

void Draining::algorithm(){
    numberSeriesInFile();
    checkFull();
    int sumSeries = 0;
    for(int i =0 ; i < 4; i++){
        sumSeries+=numberSeriesInFileS[i];
    }
    while ( sumSeries != 1){
        draining();
        numberSeriesInFileS.clear();
        numberSeriesInFile();
     sumSeries = 0;
    for(int i =0 ; i < 4; i++){
        sumSeries+=numberSeriesInFileS[i];
    }
    }
     numberSeriesInFileS.clear();
    numberSeriesInFile();
    int numberSortingFile;
    for(int i =0; i < this->Files.numberFiles; i++){
        if(this->numberSeriesInFileS[i] = 1)
        numberSortingFile = i;
    }
    cout<<" Sorting file "<<this->Files.setFiles[numberSortingFile];
}

void Draining::draining(){
    checkFull();
               if(this->fullFile[0] == false){
                   mergeInFirst();
               }

                if(this->fullFile[1] == false){
                   mergeInSecond();
               }

                if(this->fullFile[2] == false){
                    mergeInThird();
                   }
                if(this->fullFile[3] == false){
                   mergeInFourth();
               }
}

void Draining::checkFull(){
    fullFile = new bool[4];
    for(int j = 0; j<4;j++){
        fullFile[j] = true;
        //cout<<this->numberSeriesInFileS[j]<<endl;
    }
    for(int i =0; i < 4; i++){
        if(this->numberSeriesInFileS[i] == 0){
            fullFile[i] = false;
          break;
        }
    }
}