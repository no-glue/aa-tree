class DecoratorAveragePathLength {
public:
  float return_is(float ret, int edges, int length) {
    // find average path length
    return edges / (float)length;
  }
};