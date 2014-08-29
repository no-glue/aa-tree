class DecoratorDfsMessage {
public:
  void message(int edges, int stack_size) {
    if(!(edges % 1000000)) cout<<"Edges: "<<edges<<" Size: "<<stack_size<<endl;
  }
};