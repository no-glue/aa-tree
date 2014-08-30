template<typename Ifstream, typename Str>class GeneratorFile {
public:
  Ifstream file;
  GeneratorFile(Str file_name) {
    // open file
    file.open(file_name.c_str(), Ifstream::in);
  }
  Str file_is() {
    // get the file
    Str ret;
    file >> ret;
    return ret;
  }
  void close() {
    // close the file
    file.close();
  }
};