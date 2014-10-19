#define BUFFER_SIZE 128
template<typename Type, typename Qnode, typename Qdepth, class Wrapper, class List, class Node, class Tree>class AdapterMetricsAaTree {
public:
  AdapterMetricsAaTree() {}
  AdapterMetricsAaTree(Wrapper * & wrapper, List * & results, Tree * & tree):wrapper(wrapper), results(results), tree(tree) {}
  void collect_nodes() {
    // add number of nodes to results
    collect_nodes(wrapper, buffer, results, tree);
  }
  int nodes() {
    // get number of nodes
    return nodes(tree);
  }
  void collect_edges() {
    // add number of edges to results
    collect_edges(wrapper, buffer, results, tree);
  }
  int edges() {
    // get number of edges
    return edges(tree);
  }
  void collect_density() {
    // add density to results
    collect_density(wrapper, buffer, results, tree);
  }
  double density() {
    // actual connections vs max connections
    return density(tree);
  }
  void collect_average_degree() {
    // add average results to results
    collect_average_degree(wrapper, buffer, results, tree);
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
  Wrapper * wrapper;
  List * results;
  Tree * tree;
  char buffer[BUFFER_SIZE];
  void collect_nodes(Wrapper * & wrapper, char * buffer, List * & results, Tree * & tree) {
    // add number of nodes to results
    wrapper->clear(buffer, BUFFER_SIZE);
    wrapper->int_to_alpha(buffer, nodes(tree));
    results->insert_right("nodes", buffer);
  }
  int nodes(Tree * & tree) {
    // get number of nodes
    return stoi(tree->find("nodes")->value[0]);
  }
  void collect_edges(Wrapper * & wrapper, char * buffer, List * & results, Tree * & tree) {
    // add number of edges to results
    wrapper->clear(buffer, BUFFER_SIZE);
    wrapper->int_to_alpha(buffer, edges(tree));
    results->insert_right("edges", buffer);
  }
  int edges(Tree * & tree) {
    // get number of edges
    return stoi(tree->find("edges")->value[0]);
  }
  void collect_density(Wrapper * & wrapper, char * buffer, List * & results, Tree * & tree) {
    // add density to results
    wrapper->clear(buffer, BUFFER_SIZE);
    wrapper->float_to_alpha(buffer, density(tree));
    results->insert_right("density", buffer);
  }
  double density(Tree * & tree) {
    // actual connections vs max connections
    double e = (double)edges(tree);
    double n = (double)nodes(tree);
    return (2 * e) / (n * (n - 1));
  }
  void collect_average_degree(Wrapper * & wrapper, char * buffer, List * & results, Tree * & tree) {
    // add average degree to results
    wrapper->clear(buffer, BUFFER_SIZE);
    wrapper->float_to_alpha(buffer, average_degree(tree));
    results->insert_right("average degree", buffer);
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