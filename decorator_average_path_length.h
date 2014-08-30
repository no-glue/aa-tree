class DecoratorAveragePathLength {
public:
  float return_is(float ret, int & edges, int & length, int & start_depth, int & current_depth) {
    // find average path length
    edges++;
    length+=start_depth;
    return edges / (float)length;
  }
};