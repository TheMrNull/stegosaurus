#include "header.h"
#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>
using namespace std;


void openImage(){
  string inputPath, outPath;
  cout << "Insert input image/path(only .BMP allowed): ";
  //cin >> inputPath;
  getline(cin, inputPath);
  ifstream InputImage(inputPath, ios::binary);
  if(!InputImage.is_open()){
    cout << "An error occured while opening " << inputPath << endl;
    return;
  }
  outPath = removeExt(inputPath);
  ofstream OutputImage(outPath, ios::binary);
  
  char c;
  while(InputImage.get(c)){
    OutputImage.put(c);
  }

  InputImage.close();
  OutputImage.close();
}


string removeExt(const string &path){
  namespace fs = std::filesystem;
  fs::path p(path);
  p.replace_extension("");
  return p.string() + "Roar.bmp";
}
