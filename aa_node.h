template<typename Str, typename VectorString>class AaNode {
  public:
    Str key;
    // key for this node
    VectorString value;
    // values for this node
    AaNode * left;
    // left children
    AaNode * right;
    // right children
    unsigned char level;
    // level
    bool visited;
    // is node visited, useful when searching
    AaNode(Str key, Str init_value):key(key), left(NULL), right(NULL), level(1), visited(false) {
      // set up bare bones node
      value.push_back(init_value);
    }
    AaNode(Str key, Str init_value, AaNode * left, AaNode * right, unsigned char level, bool visited):key(key), left(left), right(right), level(level), visited(visited) {
      // set up node
      value.push_back(init_value);
    }
};