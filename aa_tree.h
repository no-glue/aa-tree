template<class Node, typename Str>class AaTree {
  // todo template this
public:
  AaTree():root(NULL) {}
  ~AaTree() {make_empty(root); delete root;}
  void insert(Str key, Str value) {
    // insert key and value
    insert(key, value, root);
  }
  void remove(Str key) {
    // remove node
    if(root && !root->left && !root->right && root->key == key) {delete root; root = NULL;}
    else remove(key, root);
  }
  Node * find(Str key) {
    // find key
    return find(key, root);
  }
  void visited(Str key, bool flag = true) {
    // mark node as visited
    Node * found = find(key, root);

    if(found) found->visited = flag;
  }
  bool is_visited(Str key, bool def = true) {
    // see if node is visited
    Node * found = find(key, root);

    return (found) ? found->visited : def;    
  }
  int level() {
    // get root level (tree height)
    return root->level;
  }
  template<typename Visitor> void walk(Visitor * & visitor) {
    // walk the tree, preorder
    walk(visitor, root);
  }
private:
  Node * root;
  void insert(Str key, Str value, Node * & root) {
    // insert key and value
    if(!root) root = new Node(key, value);
    else if (key < root->key) insert(key, value, root->left);
    else if(key > root->key) insert(key, value, root->right);
    else root->value.push_back(value);
    skew(root);
    split(root);
  }
  void skew(Node * & root) {
    // skew tree, rotate right (with left child)
    if(!root) return;
    if(!root->left) return;
    if(root->level == root->left->level) {
      Node * return_node = root->left;
      root->left = return_node->right;
      return_node->right = root;
      root = return_node;
    }
  }
  void split(Node * & root) {
    // split tree, rotate left (with right child)
    if(!root) return;
    if(!root->right) return;
    if(!root->right->right) return;
    if(root->right->right->level == root->level) {
      Node * return_node = root->right;
      root->right = return_node->left;
      return_node->left = root;
      return_node->level++;
      root = return_node;
    }
  }
  void remove(Str key, Node * & root) {
    // remove node
    static Node * to_remove;
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
  void decrease_level(Node * & root) {
    // decrease level of node
    if(!root) return;
    int left = (root->left) ? root->left->level : 1, right = (root->right) ? root->right->level : 1;
    int should_be = min(left, right) + 1;
    if(should_be < root->level) {
      root->level = should_be;
      if(root->right && should_be < root->right->level) root->right->level = should_be;
    }
  }
  void make_empty(Node * & root) {
    // make tree empty
    if(root) {
      make_empty(root->left);
      make_empty(root->right);
      delete root;
    }
    root = NULL;
  }
  Node * find(Str key, Node * & root) {
    // find key
    Node * look = root;
    while(look) {
      if(look && look->key == key) return look;
      if(look && key < look->key) look = look->left;
      if(look && key > look->key) look = look->right;
    }
    return NULL;
  }
  template<typename Visitor> void walk(Visitor * & visitor, Node * & root) {
    // walk the tree, preorder
    if(root->left) walk(visitor, root->left);
    visitor->visit(root);
    if(root->right) walk(visitor, root->right);
  }
  int min(int left, int right) {
    // find min
    return (left <= right) ? left : right;
  }
};