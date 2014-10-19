template<typename Type, typename Qnode, typename Qdepth, class Node, class Tree>class MetricsAaTree {
public:
  MetricsAaTree() {}
  MetricsAaTree(Tree * & tree):tree(tree) {}
  int nodes() {
    // get number of nodes
    return nodes(tree);
  }
  int edges() {
    // get number of edges
    return edges(tree);
  }
  double density() {
    // actual connections vs max connections
    return density(tree);
  }
  double average_degree() {
    // average number of edges for a node
    return average_degree(tree);
  }
  void breadth_first_search(Tree * & tree) {
    // breadth first search
    Type start_node = tree->find(startnode)->value[0];
    Node * next = tree->find(start_node);
    int i = 0;
    Qnode node;
    Qdepth depth;

    for(; i < next->value.size(); i++) {
      node.push(next->value[i]);
      depth.push(start_depth);
      tree->visited(next->value[i]);
    }

    while(!nodes.empty()) {
      next = tree->find(nodes.front());
      nodes.pop();
      start_depth = depth.front();
      depth.pop();

      if(!next) continue;

      for(i = 0; i < next->value.size(); i++) {
        if(tree->is_visited(next->value[i])) continue;

        nodes.push(next->value[i]);
        depth.push(start_depth + 1);
        tree->visited(next->value[i]);
      }
    }
  }
private:
  Tree * tree;
  int nodes(Tree * & tree) {
    // get number of nodes
    return stoi(tree->find("nodes")->value[0]);
  }
  int edges(Tree * & tree) {
    // get number of edges
    return stoi(tree->find("edges")->value[0]);
  }
  double density(Tree * & tree) {
    // actual connections vs max connections
    double e = (double)edges(tree);
    double n = (double)nodes(tree);
    return (2 * e) / (n * (n - 1));
  }
  double average_degree(Tree * & tree) {
    double e = (double)edges(tree);
    double n = (double)nodes(tree);
    return (2 * e) / n;
  }
};