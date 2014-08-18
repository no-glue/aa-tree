#include "aa_tree.h"

int main() {
  AaTree * tree = new AaTree();
  string line;
  ifstream myfile("../../node/netmark/data/orkutaa");
  myfile.seekg(0, ios::end);
  streamsize size = myfile.tellg();
  myfile.seekg(0, ios::beg);
  vector<unsigned char> buffer(size);
  string edge, from, to;
  if(myfile.read(buffer.data(), size)) {
    cout<<"loaded file\n";
    for(vector<unsigned char>::iterator it = buffer.begin(); it != buffer.end(); ++it) {
      if(*it == '\t') {
        if(edge.at(0) == '\n') edge.erase(0, 1);
        from = edge;
        edge = "";
      }
      if(*it == '\n') {
        if(edge.at(0) == '\t') edge.erase(0, 1);
        to = edge;
        edge = "";
        tree->insert(from, to);
      }
      edge += *it;
    }
  }
  myfile.close();
  delete tree;
  return 0;
}