#include "aa_node.h"

class AaTree {
public:
  AaTree():root(NULL) {}
  ~AaTree() {make_empty(); delete root;} // todo make_empty()
  void insert(string & key, string & value, AaNode * & init_root = NULL) {
    // insert key and value
    insert(key, value, (init_root) ? init_root : root);
  }
private:
  AaNode * root;
  void insert(string & key, string & value, AaNode * & root) {
    if(!root) root = new AaNode(key, value);
    else if (key < root->key) insert(key, value, root->left);
    else if(key > root->key) rinsert(key, value, root->right);
    else root->value->push_back(value);
    skew(root); // todo skew
    split(root); // todo split
  }
  void skew(AaNode * & root) {
    // skew tree, rotate right (with left child)
  }
  void split(AaNode * & root) {
    // split tree, rotate left (with right child)
  }
};