#include "test_tree.h"

int main() {
  TestTree * tree_test = new TestTree();
  AaTree * tree = new AaTree();
  string key1, value1, key2, value2;
  key1 = "like"; value1 = "icecream";
  tree_test->test_insert_key(key1, value1, tree);
  tree = new AaTree(); key1 = "like"; value1 = "icecream"; key2 = "like"; value2 = "chocolate";
  tree_test->test_insert_keys(key1, value1, key2, value2, tree);
  tree = new AaTree(); key1 = "like"; value1 = "icecream";
  tree_test->test_remove_key(key1, value1, tree);
  tree = new AaTree(); key1 = "like"; value1 = "icecream"; key2 = "like"; value2 = "chocolate";
  tree_test->test_level(key1, value1, key2, value2, tree);
  delete tree_test;
}