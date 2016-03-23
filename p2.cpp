#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <string>
#include <sstream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include "node.h"
#include "binarySearchTree.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

void nope_out(const string & name) {
  perror(name.c_str());
  exit(EXIT_FAILURE);
} // nope_out


int main(const int argc, const char * argv []) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(0);
  } // if

  string filename = argv[1];
  ifstream input(filename);
  int r =0,flag = 0;
  for(string stringIn; getline(input,stringIn);) { //go thru each line
    istringstream iss(stringIn);
    string uinput;
    while(getline(iss,uinput,' ')){
      if (flag==1){
	int valN = stoi(uinput);
	//insert
	flag=0;
      }
      if(flag==2){

	flag=0;
      }
      if(uinput=="insert"){
	flag = 1;
      }
      if(uinput=="delete"){
        flag = 2;
      }


    }
  
}

  return EXIT_SUCCESS;
} // main

