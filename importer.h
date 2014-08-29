#include "aa_tree.h"

class Importer {
public:
  void import(string dir_name, AaTree * & tree) {
    // import edges from files to tree
    string file_path;
    DIR * dir = opendir(dir_name.c_str());
    struct dirent * file;
    string line;
    ifstream myfile;
    streamsize size;
    vector<unsigned char> buffer;
    string edge, from, to;
    int count = 0;
    while(dir && (file = readdir(dir)) && ++count) {
      if(file->d_name[0] == '.') continue;
      file_path = dir_name + file->d_name;
      myfile.open(file_path.c_str(), ifstream::in);
      myfile.seekg(0, ios::end);
      size = myfile.tellg();
      myfile.seekg(0, ios::beg);
      buffer.clear();
      buffer.resize(size);
      edge = "";
      if(myfile.read(buffer.data(), size)) {
        cout<<"loaded file: "<<file->d_name<<" "<<count<<endl;
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
    closedir(dir);
  }
  int nodes(AaTree * & tree) {
    // get number of nodes
    // todo move this to another component
    return stoi(tree->find("nodes")->value[0]);
  }
  int edges(AaTree * & tree) {
    // get number of edges
    // todo move this to another component
    return stoi(tree->find("edges")->value[0]);
  }
  double density(AaTree * & tree) {
    // network density
    // todo move this to another component
    double e = (double)stoi(tree->find("edges")->value[0]);
    double n = (double)stoi(tree->find("nodes")->value[0]);

    return (2 * e) / (n * (n - 1));
  }
  float average_degree(AaTree * & tree) {
    // average number of edges for a node
    // todo move this to another component
    int e = stoi(tree->find("edges")->value[0]);
    int n = stoi(tree->find("nodes")->value[0]);

    return (2 * e) / (float)(n);
  }
  int depth_first_search(AaTree * & tree, string start_node = "1", int start_depth = 1) {
    // find max depth
    // todo decorate this
    AaNode * found = tree->find(start_node);
    int i = 0;
    stack<string> nodes;
    stack<int> depth;
    int current_depth = 0;

    for(; i < found->value.size(); i++) {
      nodes.push(found->value[i]);
      depth.push(start_depth);
    }

    while(!nodes.empty()) {
      found = tree->find(nodes.top());
      nodes.pop();
      start_depth = depth.top();
      depth.pop();
      if(start_depth > current_depth) current_depth = start_depth; else break;

      if(found) {
        for(i = 0; i < found->value.size(); i++) {
          nodes.push(found->value[i]);
          depth.push(start_depth + 1);
        }
      }
    }

    return current_depth;
  }
};