#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AaNode {
  public:
    string & key;
    // key for this node
    vector<string> & value;
    // values for this node
    AaNode * left;
    // left children
    AaNode * right;
    // right children
    int level;
    // level
    AaNode(string & key, string & init_value):key(key), left(NULL), right(NULL), level(1) {
      // set up bare bones node
      value.push_back(init_value);
    }
    AaNode(string & key, string & init_value, AaNode * left, AaNode * right, int level):key(key), left(left), right(right), level(level) {
      // set up node
      value.push_back(init_value);
    }
};