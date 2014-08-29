#include "importer.h"

int main() {
  AaTree * tree = new AaTree();
  Importer * importer = new Importer();
  DecoratorMaxDepth * max_depth = new DecoratorMaxDepth();
  DecoratorAveragePathLength * av_path_len = new DecoratorAveragePathLength();
  importer->import("../../node/netmark/data/split/", tree);
  cout<<"nodes: "<<importer->nodes(tree)<<endl;
  // todo move this to component
  cout<<"edges: "<<importer->edges(tree)<<endl;
  // todo move this to component
  cout<<"density: "<<importer->density(tree)<<endl;
  // todo move this to component
  cout<<"average degree: "<<importer->average_degree(tree)<<endl;
  // todo move this to component
  cout<<"average path length: "<<importer->breadth_first_search(tree, av_path_len)<<endl;
  // todo move this to component
  cout<<"network diameter: "<<importer->depth_first_search(tree, max_depth)<<endl;
  // todo move this to component
  // todo make this a server
  delete av_path_len;
  delete max_depth;
  delete importer;
  delete tree;
  return 0;
}