#include "aa_tree.h"

int main() {
  string dir_name("../../node/netmark/data/split/");
  string file_path;
  DIR * dir = opendir(dir_name.c_str());
  struct dirent * file;
  AaTree * tree = new AaTree();
  string line;
  ifstream myfile;
  streamsize size;
  vector<unsigned char> buffer;
  string edge, from, to;
  while(dir && (file = readdir(dir))) {
    if(file->d_name[0] == '.') continue;
    file_path = dir_name + file->d_name;
    myfile.open(file_path.c_str(), ifstream::in);
    myfile.seekg(0, ios::end);
    size = myfile.tellg();
    myfile.seekg(0, ios::beg);
    buffer.resize(size);
    buffer.clear();
    if(myfile.read(buffer.data(), size)) {
      cout<<"loaded file: "<<file->d_name<<endl;
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
  }
  delete tree;
  closedir(dir);
  return 0;
}