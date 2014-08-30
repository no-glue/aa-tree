class DecoratorMaxDepth {
public:
  float return_is(float ret, int & edges, int & length, int & start_depth, int & current_depth) {
    if(current_depth < start_depth) current_depth = start_depth;

    return current_depth;
  }
};