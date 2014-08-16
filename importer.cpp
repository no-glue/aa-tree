#include "aa_tree.h"

int main() {
  int i = 0;
  string line;
  ifstream myfile("../../node/netmark/data/edgesorkut.txt");
  while(getline(myfile,line) && ++i) { 
    cout<<line<<"  "<<i<<"\n";
  }
  myfile.close();
  return 0;
}