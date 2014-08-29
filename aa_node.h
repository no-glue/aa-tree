#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <dirent.h>
#include <queue>
#include <stack>

using namespace std;

class AaNode {
  public:
    string key;
    // key for this node
    vector<string> value;
    // values for this node
    AaNode * left;
    // left children
    AaNode * right;
    // right children
    int level;
    // level
    bool visited;
    // is node visited, useful when searching
    AaNode(string key, string init_value):key(key), left(NULL), right(NULL), level(1), visited(false) {
      // set up bare bones node
      value.push_back(init_value);
    }
    AaNode(string key, string init_value, AaNode * left, AaNode * right, int level, bool visited):key(key), left(left), right(right), level(level), visited(visited) {
      // set up node
      value.push_back(init_value);
    }
};