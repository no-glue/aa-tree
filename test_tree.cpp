#include "aa_tree.h"

int main() {
  AaTree * tree = new AaTree();
  AaNode * found;
  string key("like");
  string value("icecream");
  tree->insert(key, value);
  found = tree->find(key);
  cout<<"found: "<<found->value[0]<<"\n";
  value = "chocolate";
  tree->insert(key, value);
  found = tree->find(key);
  cout<<"found: "<<found->value[0]<<" "<<found->value[1]<<"\n";
  key = "dislike";
  value = "strangers";
  tree->insert(key, value);
  found = tree->find(key);
  cout<<"found: "<<key<<" "<<found->value[0]<<" "<<"\n";
  delete tree;
}