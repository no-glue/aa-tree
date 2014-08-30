template<class Tree, class Node, typename Str>class TestTree {
public:
  void test_insert_key(Str key, Str value, Tree * & tree) {
    // test single key insert
    Node * found;
    tree->insert(key, value);
    found = tree->find(key);
    assert(found->value[0] == value);
    delete tree;
  }
  void test_insert_keys(Str key1, Str value1, Str key2, Str value2, Tree * & tree) {
    // test same key, different values
    Node * found;
    tree->insert(key1, value1);
    tree->insert(key2, value2);
    found = tree->find(key1);
    assert(found->value[0] == value1);
    delete tree;
  }
  void test_remove_key(Str key, Str value, Tree * & tree) {
    // test remove key
    // should not be there after remove
    Node * found;
    tree->insert(key, value);
    tree->remove(key);
    found = tree->find(key);
    assert(found == 0);
    delete tree;
  }
  void test_level(Str key1, Str value1, Str key2, Str value2, Tree * & tree) {
    // test level
    // should be 1 for 2 keys
    tree->insert(key1, value1);
    tree->insert(key2, value2);
    assert(tree->level() == 1);
    delete tree;
  }
};