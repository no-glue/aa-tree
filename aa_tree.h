#include "aa_node.h"

class AaTree {
public:
  AaTree():root(NULL) {}
  ~AaTree() {make_empty(root); delete root;}
  void insert(string key, string & value) {
    // insert key and value
    insert(key, value, root);
  }
  void remove(string key) {
    // remove node
    remove(key, root);
  }
  AaNode * find(string key) {
    // find key
    return find(key, root);
  }
  int level() {
    // get root level (tree height)
    return root->level;
  }
private:
  AaNode * root;
  void insert(string key, string & value, AaNode * & root) {
    // insert key and value
    if(!root) root = new AaNode(key, value);
    else if (key < root->key) insert(key, value, root->left);
    else if(key > root->key) insert(key, value, root->right);
    else root->value.push_back(value);
    skew(root);
    split(root);
  }
  void skew(AaNode * & root) {
    // skew tree, rotate right (with left child)
    if(!root) return;
    if(!root->left) return;
    if(root->level == root->left->level) {
      AaNode * return_node = root->left;
      root->left = return_node->right;
      return_node->right = root;
      root = return_node;
    }
  }
  void split(AaNode * & root) {
    // split tree, rotate left (with right child)
    if(!root) return;
    if(!root->right) return;
    if(!root->right->right) return;
    if(root->right->right->level == root->level) {
      AaNode * return_node = root->right;
      root->right = return_node->left;
      return_node->left = root;
      return_node->level++;
      root = return_node;
    }
  }
  void remove(string key, AaNode * & root) {
    // remove node
    static AaNode * to_remove;
    if (!root) return;
    else if (key < root->key) remove(key, root->left);
    else if (key > root->key) remove(key, root->right);
    else {
      if(!root->left && !root->right) return;
      else if(!root->left) {
        to_remove = root->right;
        remove(to_remove->key, root->right);
        root->key = to_remove->key;
        root->value = to_remove->value;
      }
      else {
        to_remove = root->left;
        remove(to_remove->key, root->left);
        root->key = to_remove->key;
        root->value = to_remove->value;
      }
    }
    decrease_level(root);
    skew(root);
    skew(root->right);
    if(root->right) skew(root->right->right);
    split(root);
    split(root->right);
  }
  void decrease_level(AaNode * & root) {
    // decrease level of node
    if(!root) return;
    int left = (root->left) ? root->left->level : 1, right = (root->right) ? root->right->level : 1;
    int should_be = min(left, right) + 1;
    if(should_be < root->level) {
      root->level = should_be;
      if(root->right && should_be < root->right->level) root->right->level = should_be;
    }
  }
  void make_empty(AaNode * & root) {
    // make tree empty
    if(root) {
      make_empty(root->left);
      make_empty(root->right);
      delete root;
    }
    root = NULL;
  }
  AaNode * find(string key, AaNode * & root) {
    // find key
    AaNode * look = root;
    while(look) {
      if(look && look->key == key) return look;
      if(look && key < look->key) look = look->left;
      if(look && key > look->key) look = look->right;
    }
    return NULL;
  }
};