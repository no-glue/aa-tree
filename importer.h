template<class Generator, class Tree, class Message, typename Str, typename Ifstream>class Importer {
public:
  void import(Generator * & generator, Tree * & tree, Message * & message) {
    // todo move out to decorator
    Str file_name("");
    Ifstream file;
    Str from, to;
    int count = 1;

    while((file_name = generator->file_is()) != "") {
      file.open(file_name.c_str(), Ifstream::in);
      while(file>>from>>to) {
        tree->insert(from, to);
      }
      message->message(file_name, count);
      count++;
      file.close();
    }

    generator->close();
  }
};