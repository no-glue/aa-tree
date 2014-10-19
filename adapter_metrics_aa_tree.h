template<typename Type, typename Qnode, typename Qdepth, class List, class Node, class Tree>class MetricsAaTree {
public:
  MetricsAaTree() {}
  MetricsAaTree(List * & results, Tree * & tree):results(results), tree(tree) {}
  void collect_nodes() {
    // add number of nodes to results
    collect_nodes(results, tree);
  }
  int nodes() {
    // get number of nodes
    return nodes(tree);
  }
  void collect_edges() {
    // add number of edges to results
    collect_edges(results, tree);
  }
  int edges() {
    // get number of edges
    return edges(tree);
  }
  void collect_density() {
    // add density to results
    collect_density(results, tree);
  }
  double density() {
    // actual connections vs max connections
    return density(tree);
  }
  void collect_average_degree() {
    // add average results to results
    collect_average_degree(results, tree);
  }
  double average_degree() {
    // average number of edges for a node
    return average_degree(tree);
  }
  void breadth_first_search() {
    // breadth first search
    breadth_first_search(results, tree);
  }
private:
  List * results;
  Tree * tree;
  void collect_nodes(List * & results, Tree * & tree) {
    // add number of nodes to results
    results->insert_right("nodes", tree->find("nodes")->value[0]);
  }
  int nodes(Tree * & tree) {
    // get number of nodes
    return stoi(tree->find("nodes")->value[0]);
  }
  void collect_edges(List * & results, Tree * & tree) {
    // add number of edges to results
    results->insert_right("edges", tree->find("nodes")->value[0]);
  }
  int edges(Tree * & tree) {
    // get number of edges
    return stoi(tree->find("edges")->value[0]);
  }
  void collect_density(List * & results, Tree * & tree) {
    // add density to results
    results->insert_right("density", to_string(density(tree)));
  }
  double density(Tree * & tree) {
    // actual connections vs max connections
    double e = (double)edges(tree);
    double n = (double)nodes(tree);
    return (2 * e) / (n * (n - 1));
  }
  void collect_average_degree(List * & results, Tree * & tree) {
    // add average degree to results
    results->insert_right("average degree", to_string(average_degree(tree)));
  }
  double average_degree(Tree * & tree) {
    // average degree
    double e = (double)edges(tree);
    double n = (double)nodes(tree);
    return (2 * e) / n;
  }
  void breadth_first_search(List * & results, Tree * & tree) {
    // breadth first search
    // Type start_node = tree->find(startnode)->value[0];
    // Node * next = tree->find(start_node);
    // int i = 0;
    // Qnode node;
    // Qdepth depth;

    // for(; i < next->value.size(); i++) {
    //   node.push(next->value[i]);
    //   depth.push(start_depth);
    //   tree->visited(next->value[i]);
    // }

    // while(!nodes.empty()) {
    //   next = tree->find(nodes.front());
    //   nodes.pop();
    //   start_depth = depth.front();
    //   depth.pop();

    //   if(!next) continue;

    //   for(i = 0; i < next->value.size(); i++) {
    //     if(tree->is_visited(next->value[i])) continue;

    //     nodes.push(next->value[i]);
    //     depth.push(start_depth + 1);
    //     tree->visited(next->value[i]);
    //   }
    // }
  }
};