#include "header.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void openImage(){
  string inputPath, outPath;
  cout << "Insert input image/path to image(no spaces allowed): ";
  cin >> inputPath;
  ifstream InputImage(inputPath, ios::binary);
  if(!InputImage.is_open()){
    cout << "An error occured while opening " << inputPath << endl;
    return;
  }
  outPath = removeExstenstion(inputPath); 
  ofstream OutputImage(outPath, ios::binary);
  
  char c;
  while(InputImage.get(c)){
    OutputImage.put(c);
  }

  InputImage.close();
  OutputImage.close();
}


string removeExstenstion(string path){
  string png = ".png";
  string path2 = path.erase(path.length()-png.length());
  return path2 + "Roar.png";  
}
