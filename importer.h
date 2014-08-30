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
  template<class Tree> int nodes(Tree * & tree) {
    // get number of nodes
    // todo move this to another component
    return stoi(tree->find("nodes")->value[0]);
  }
  template<class Tree> int edges(Tree * & tree) {
    // get number of edges
    // todo move this to another component
    return stoi(tree->find("edges")->value[0]);
  }
  template<class Tree> double density(Tree * & tree) {
    // network density
    // todo move this to another component
    double e = (double)stoi(tree->find("edges")->value[0]);
    double n = (double)stoi(tree->find("nodes")->value[0]);

    return (2 * e) / (n * (n - 1));
  }
  template<class Tree> float average_degree(Tree * & tree) {
    // average number of edges for a node
    // todo move this to another component
    int e = stoi(tree->find("edges")->value[0]);
    int n = stoi(tree->find("nodes")->value[0]);

    return (2 * e) / (float)(n);
  }
  template<class Tree, class Ret, class Message> float breadth_first_search(Tree * & tree, Ret * & decorator, Message * & decorator_message, string start_node = "1", int start_depth = 1) {
    // breadth first search
    // todo decorate this
    AaNode * next = tree->find(start_node);
    int i = 0;
    queue<string> nodes;
    queue<int> depth;
    int edges = 0;
    int length = 0;
    int current_depth = 0;
    float ret = 0;

    for(; i < next->value.size(); i++) {
      nodes.push(next->value[i]);
      depth.push(start_depth);
      tree->visited(next->value[i]);
    }

    while(!nodes.empty()) {
      next = tree->find(nodes.front());
      nodes.pop();
      start_depth = depth.front();
      depth.pop();
      ret = decorator->return_is(ret, edges, length, start_depth, current_depth);

      decorator_message->message(ret, edges, length);

      if(!next) continue;

      for(i = 0; i < next->value.size(); i++) {
        if(tree->is_visited(next->value[i])) continue;

        nodes.push(next->value[i]);
        depth.push(start_depth + 1);
        tree->visited(next->value[i]);
      }
    }

    return ret;
  }
};