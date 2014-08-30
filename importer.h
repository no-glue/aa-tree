template<class Generator, typename Str, typename Ifstream, typename Streamsize, typename VectorUchar, typename Ios, typename Ostream>class Importer {
public:
  void import(Generator * & generator, Ostream & out) {
    // todo move out to decorator
    Str file_name("");

    while((file_name = generator->file_is()) != "") {
      out<<file_name<<"\n";
    }

    generator->close();
  }
};
// class Importer {
// public:
//   void import(string dir_name) {
//     // import edges from files to tree
//     string file_path;
//     DIR * dir = opendir(dir_name.c_str());//DIR
//     struct dirent * file;//struct dirent
//     string line;
//     ifstream myfile;
//     streamsize size;
//     vector<unsigned char> buffer;
//     string edge, from, to;
//     int count = 0;
//     int it = 0;
//     while(dir && (file = readdir(dir)) && ++count) {
//       if(file->d_name[0] == '.') continue;
//       file_path = dir_name + file->d_name;
//       myfile.open(file_path.c_str(), ifstream::in);
//       myfile.seekg(0, ios::end);
//       size = myfile.tellg();
//       myfile.seekg(0, ios::beg);
//       buffer.clear();
//       buffer.resize(size);
//       edge = "";
//       if(myfile.read(buffer.data(), size)) {
//         //cout<<"loaded file: "<<file->d_name<<" "<<count<<endl;
//         for(it = 0; it < buffer.size(); it++) {
//           if(buffer[it] == '\t') {
//             if(edge.at(0) == '\n') edge.erase(0, 1);
//             from = edge;
//             edge = "";
//           }
//           if(buffer[it] == '\n') {
//             if(edge.at(0) == '\t') edge.erase(0, 1);
//             to = edge;
//             edge = "";
//             //tree->insert(from, to);
//           }
//           edge += buffer[it];
//         }
//       }
//       myfile.close();
//     }
//     closedir(dir);
//   }
// };