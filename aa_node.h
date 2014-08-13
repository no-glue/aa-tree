#include <cstring>
#include <vector>

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
    AaNode():key(""), value({""}), left(NULL), right(NULL), level(1) {
      // set up empty node
    }
    AaNode(string & key, string & value, AaNode * left, AaNode * right, int level):key(key), value(value), left(left), right(right), level(level) {
      // set up node
    }
};