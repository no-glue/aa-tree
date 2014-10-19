#include <vector>
#include <iostream>
#include <fstream>
#include "string_wrapper.h"
#include <queue>
#include <stack>
#include <time.h>
#include "aa_node.h"
#include "aa_tree.h"
#include "double_node.h"
#include "double_list.h"
#include "adapter_metrics_aa_tree.h"
#include "decorator_file_read.h"
#include "generator_file.h"
#include "importer.h"

using namespace std;

int main() {
  string line;
  getline(cin, line);
  DoubleList<
    DoubleNode<string>,
    string
  > * results = new DoubleList<
    DoubleNode<string>,
    string
  >();
  // results
  AaTree<
    AaNode<string, vector<string> >,
    string
  > * tree = new AaTree<
    AaNode<string, vector<string> >,
    string
  >();
  // tree
  StringWrapper<double> * wrapper = new StringWrapper<double>();
  // string helper
  AdapterMetricsAaTree<
    string,
    queue<string>,
    queue<string>,
    StringWrapper<double>,
    DoubleList<DoubleNode<string>, string>,
    AaNode<string, vector<string> >,
    AaTree<
      AaNode<string, vector<string> >,
      string
    > 
  > * metrics = new AdapterMetricsAaTree<
    string,
    queue<string>,
    queue<string>,
    StringWrapper<double>,
    DoubleList<DoubleNode<string>, string>,
    AaNode<string, vector<string> >,
    AaTree<
      AaNode<string, vector<string> >,
      string
    >
  >(wrapper, results, tree);
  // metrics (use it as adapter)
  GeneratorFile<
    ifstream, string
  > * files = new GeneratorFile<
    ifstream, string
  >(line);
  // get file generator
  DecoratorFileRead<
    ostream, string
  > * file_read = new DecoratorFileRead<
    ostream, string
  >(cout);
  // get file read messages
  Importer<
    GeneratorFile<ifstream, string>, 
    AaTree<
      AaNode<string, vector<string> >,
      string
    >, 
    DecoratorFileRead<ostream, string>, 
    string, 
    ifstream
  > * importer = new Importer<
    GeneratorFile<ifstream, string>, 
    AaTree<
      AaNode<string, vector<string> >,
      string
    >, 
    DecoratorFileRead<ostream, string>, 
    string, 
    ifstream
  >();
  // importer
  time_t now = time(NULL), then;
  importer->import(files, tree, file_read);
  then = time(NULL);
  cout<<"indexing time "<<difftime(then, now)<<" seconds"<<endl;
  metrics->collect_nodes();
  metrics->collect_edges();
  metrics->collect_density();
  metrics->collect_average_degree();
  while(results->get_head()) {
    cout<<results->get_head()->key<<" "<<results->get_head()->value<<endl;
    results->pop_left();
  }
  delete results;
  delete tree;
  delete metrics;
  delete files;
  delete file_read;
  delete importer;
  return 0;
}