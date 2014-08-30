template<class Ostream, typename Str>class DecoratorFileRead {
public:
  Ostream & stream;
  DecoratorFileRead(Ostream & stream):stream(stream) {}
  void message(Str file_name, int count) {
    stream<<"Loaded file "<<file_name<<" "<<count<<"\n";
  }
};