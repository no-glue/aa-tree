template<class Ostream>class DecoratorBfsMessage {
public:
  Ostream & stream;
  DecoratorBfsMessage(Ostream & stream):stream(stream) {}
  void message(float ret, int edges, int length) {
    if(edges && !(edges % 1000000)) stream<<"Edges: "<<edges<<"\n";
  }
};