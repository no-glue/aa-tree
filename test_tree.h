#include "aa_tree.h"

class TestTree {
public:
  void test_insert_key(string key, string value, AaTree * & tree) {
    // test single key insert
    AaNode * found;
    tree->insert(key, value);
    found = tree->find(key);
    assert(found->value[0] == value);
    delete tree;
  }
  void test_insert_keys(string key1, string value1, string key2, string value2, AaTree * & tree) {
    // test same key, different values
    AaNode * found;
    tree->insert(key1, value1);
    tree->insert(key2, value2);
    found = tree->find(key1);
    assert(found->value[0] == value1);
    delete tree;
  }
  void test_remove_key(string key, string value, AaTree * & tree) {
    // test remove key
    // should not be there after remove
    AaNode * found;
    tree->insert(key, value);
    tree->remove(key);
    found = tree->find(key);
    assert(found == 0);
    delete tree;
  }
  void test_level(string key1, string value1, string key2, string value2, AaTree * & tree) {
    // test level
    // should be 1 for 2 keys
    tree->insert(key1, value1);
    tree->insert(key2, value2);
    assert(tree->level() == 1);
    delete tree;
  }
};