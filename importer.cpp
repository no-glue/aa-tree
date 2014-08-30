#include "importer.h"
#include "metrics.h"
#include "decorator_average_path_length.h"
#include "decorator_bfs_message.h"
#include "decorator_not_seen.h"
#include "decorator_max_depth.h"

int main() {
  AaTree * tree = new AaTree();
  Importer * importer = new Importer();
  Metrics<AaNode, AaTree> * metrics = new Metrics<AaNode, AaTree>();
  DecoratorAveragePathLength * av_path_len = new DecoratorAveragePathLength();
  DecoratorBfsMessage * bfs_message = new DecoratorBfsMessage();
  DecoratorNotSeen * not_seen = new DecoratorNotSeen();
  DecoratorMaxDepth * get_max_depth = new DecoratorMaxDepth();
  importer->import("../../node/netmark/data_live_journal/split/", tree);
  // todo use first data set
  cout<<"nodes: "<<metrics->nodes(tree)<<endl;
  // todo move this to component
  cout<<"edges: "<<metrics->edges(tree)<<endl;
  // todo move this to component
  cout<<"density: "<<metrics->density(tree)<<endl;
  // todo move this to component
  cout<<"average degree: "<<metrics->average_degree(tree)<<endl;
  // todo move this to component
  cout<<"average path length: "<<metrics->breadth_first_search<queue<string>, queue<int>, DecoratorAveragePathLength, DecoratorBfsMessage>(tree, av_path_len, bfs_message)<<endl;
  // todo move this to component
  tree->walk(not_seen);
  cout<<"network diameter: "<<metrics->breadth_first_search<queue<string>, queue<int>, DecoratorMaxDepth, DecoratorBfsMessage>(tree, get_max_depth, bfs_message)<<endl;
  // todo move this to component
  delete get_max_depth;
  delete not_seen;
  delete bfs_message;
  delete av_path_len;
  delete metrics;
  delete importer;
  delete tree;
  return 0;
}