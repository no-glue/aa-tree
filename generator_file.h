template<typename Ifstream, typename Str>class GeneratorFile {
public:
  Ifstream file;
  Str file_is(Str file_name) {
    // get the file
    Str ret;
    if(!file.is_open()) file.open(file_name.c_str(), Ifstream::in);
    file >> ret;
    return ret;
  }
  void close() {
    // close the file
    file.close();
  }
};