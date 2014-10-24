#include <vector>
#include <string>
#include <assert.h>
#include "aa_node.h"
#include "aa_tree.h"
#include "test_tree.h"

using namespace std;

int main() {
  TestTree<AaTree<AaNode<string, vector<string> >, string>, AaNode<string, vector<string> >, string> * tree_test = new TestTree<AaTree<AaNode<string, vector<string> >, string>, AaNode<string, vector<string> >, string>();
  AaTree<AaNode<string, vector<string> >, string> * tree = new AaTree<AaNode<string, vector<string> >, string>();
  string key1, value1, key2, value2;
  key1 = "like"; value1 = "icecream";
  tree_test->test_insert_key(key1, value1, tree);
  tree = new AaTree<AaNode<string, vector<string> >, string>(); key1 = "like"; value1 = "icecream"; key2 = "like"; value2 = "chocolate";
  tree_test->test_insert_keys(key1, value1, key2, value2, tree);
  tree = new AaTree<AaNode<string, vector<string> >, string>(); key1 = "like"; value1 = "icecream";
  tree_test->test_remove_key(key1, value1, tree);
  tree = new AaTree<AaNode<string, vector<string> >, string>(); key1 = "like"; value1 = "icecream"; key2 = "like"; value2 = "chocolate";
  tree_test->test_level(key1, value1, key2, value2, tree);
  tree = new AaTree<AaNode<string, vector<string> >, string>(); key1 = "like"; value1 = "icecream"; key2 = "like"; value2 = "chocolate";
  tree_test->test_insert_unique(key1, value1, key2, value2, tree);
  delete tree_test;
}