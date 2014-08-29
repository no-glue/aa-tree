class DecoratorBfsMessage {
public:
  void message(float ret, int edges, int length) {
    if(!(edges % 1000000)) cout<<"Edges: "<<edges<<endl;
  }
};