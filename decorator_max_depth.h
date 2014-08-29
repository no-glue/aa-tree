class DecoratorMaxDepth {
public:
  bool run_condition(int start_depth, int current_depth) {
    // stop dfs if maximum depth
    return start_depth > current_depth;
  }
};