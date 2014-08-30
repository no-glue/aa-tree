template<class Node, class Tree>class Metrics {
public:
  int nodes(Tree * & tree) {
    // get number of nodes
    return stoi(tree->find("nodes")->value[0]);
  }
  int edges(Tree * & tree) {
    // get number of edges
    return stoi(tree->find("edges")->value[0]);
  }
  double density(Tree * & tree) {
    // network density
    double e = (double)stoi(tree->find("edges")->value[0]);
    double n = (double)stoi(tree->find("nodes")->value[0]);

    return (2 * e) / (n * (n - 1));
  }
  float average_degree(Tree * & tree) {
    // average number of edges for a node
    int e = stoi(tree->find("edges")->value[0]);
    int n = stoi(tree->find("nodes")->value[0]);

    return (2 * e) / (float)(n);
  }
  template<typename Qstr, typename Qint, class Ret, class Message, typename Str> float breadth_first_search(Tree * & tree, Ret * & decorator, Message * & decorator_message, Str start_node = "1", int start_depth = 1) {
    // breadth first search
    Node * next = tree->find(start_node);
    int i = 0;
    Qstr nodes;
    Qint depth;
    int edges = 0;
    int length = 0;
    int current_depth = 0;
    float ret = 0;

    for(; i < next->value.size(); i++) {
      nodes.push(next->value[i]);
      depth.push(start_depth);
      tree->visited(next->value[i]);
    }

    while(!nodes.empty()) {
      next = tree->find(nodes.front());
      nodes.pop();
      start_depth = depth.front();
      depth.pop();
      ret = decorator->return_is(ret, edges, length, start_depth, current_depth);

      decorator_message->message(ret, edges, length);

      if(!next) continue;

      for(i = 0; i < next->value.size(); i++) {
        if(tree->is_visited(next->value[i])) continue;

        nodes.push(next->value[i]);
        depth.push(start_depth + 1);
        tree->visited(next->value[i]);
      }
    }

    return ret;
  }
};