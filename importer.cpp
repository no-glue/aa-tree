#include "importer.h"
#include "decorator_max_depth.h"
#include "decorator_average_path_length.h"
#include "decorator_bfs_message.h"
#include "decorator_dfs_message.h"
#include "decorator_not_seen.h"

int main() {
  AaTree * tree = new AaTree();
  Importer * importer = new Importer();
  DecoratorMaxDepth * max_depth = new DecoratorMaxDepth();
  DecoratorAveragePathLength * av_path_len = new DecoratorAveragePathLength();
  DecoratorBfsMessage * bfs_message = new DecoratorBfsMessage();
  DecoratorNotSeen * not_seen = new DecoratorNotSeen();
  importer->import("../../node/netmark/data_live_journal/split/", tree);
  // todo use first data set
  cout<<"nodes: "<<importer->nodes(tree)<<endl;
  // todo move this to component
  cout<<"edges: "<<importer->edges(tree)<<endl;
  // todo move this to component
  cout<<"density: "<<importer->density(tree)<<endl;
  // todo move this to component
  cout<<"average degree: "<<importer->average_degree(tree)<<endl;
  // todo move this to component
  cout<<"average path length: "<<importer->breadth_first_search(tree, av_path_len, bfs_message)<<endl;
  tree->walk(not_seen);
  delete not_seen;
  delete bfs_message;
  delete av_path_len;
  delete max_depth;
  delete importer;
  delete tree;
  return 0;
}