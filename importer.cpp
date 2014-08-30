#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <dirent.h>
#include <queue>
#include <stack>
#include "aa_node.h"
#include "aa_tree.h"
#include "metrics.h"
#include "decorator_average_path_length.h"
#include "decorator_bfs_message.h"
#include "decorator_not_seen.h"
#include "decorator_max_depth.h"

using namespace std;

int main() {
  AaTree<AaNode<vector<string>, string>, string> * tree = new AaTree<AaNode<vector<string>, string>, string>();
  Metrics<AaNode<vector<string>, string>, AaTree<AaNode<vector<string>, string>, string> > * metrics = new Metrics<AaNode<vector<string>, string>, AaTree<AaNode<vector<string>, string>, string> >();
  DecoratorAveragePathLength * av_path_len = new DecoratorAveragePathLength();
  DecoratorBfsMessage<ostream> * bfs_message = new DecoratorBfsMessage<ostream>(cout);
  DecoratorNotSeen * not_seen = new DecoratorNotSeen();
  DecoratorMaxDepth * get_max_depth = new DecoratorMaxDepth();
  // todo use first data set
  cout<<"nodes: "<<metrics->nodes(tree)<<endl;
  // todo move this to component
  cout<<"edges: "<<metrics->edges(tree)<<endl;
  // todo move this to component
  cout<<"density: "<<metrics->density(tree)<<endl;
  // todo move this to component
  cout<<"average degree: "<<metrics->average_degree(tree)<<endl;
  // todo move this to component
  cout<<"average path length: "<<metrics->breadth_first_search<queue<string>, queue<int>, DecoratorAveragePathLength, DecoratorBfsMessage<ostream>, string>(tree, av_path_len, bfs_message)<<endl;
  // todo move this to component
  tree->walk(not_seen);
  cout<<"network diameter: "<<metrics->breadth_first_search<queue<string>, queue<int>, DecoratorMaxDepth, DecoratorBfsMessage<ostream>, string>(tree, get_max_depth, bfs_message)<<endl;
  // todo move this to component
  delete get_max_depth;
  delete not_seen;
  delete bfs_message;
  delete av_path_len;
  delete metrics;
  delete tree;
  return 0;
}