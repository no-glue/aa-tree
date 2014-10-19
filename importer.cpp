#include <vector>
#include <iostream>
#include <fstream>
#include <string>
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
  AaTree<
    AaNode<string, vector<string> >,
    string
  > * tree = new AaTree<
    AaNode<string, vector<string> >,
    string
  >();
  AdapterMetricsAaTree<
    string,
    queue<string>,
    queue<string>,
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
    DoubleList<DoubleNode<string>, string>,
    AaNode<string, vector<string> >,
    AaTree<
      AaNode<string, vector<string> >,
      string
    >
  >(results, tree);
  delete results;
  delete tree;
  delete metrics;
  return 0;
}