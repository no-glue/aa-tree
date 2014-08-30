class DecoratorBfsMessage {
public:
  void message(float ret, int edges, int length) {
    if(edges && !(edges % 1000000)) cout<<"Edges: "<<edges<<endl;
  }
};