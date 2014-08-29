class DecoratorNotSeen {
public:
  template<typename Node> void visit(Node * & root, bool flag = false) {
    // clear visited for root
    root->visited = flag;
  }
};