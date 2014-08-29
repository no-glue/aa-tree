#include "importer.h"

int main() {
  AaTree * tree = new AaTree();
  Importer * importer = new Importer();
  importer->import("../../node/netmark/data/split/", tree);
  cout<<"nodes: "<<importer->nodes(tree)<<endl;
  // todo move this to component
  cout<<"edges: "<<importer->edges(tree)<<endl;
  // todo move this to component
  cout<<"density: "<<importer->density(tree)<<endl;
  // todo move this to component
  cout<<"average degree: "<<importer->average_degree(tree)<<endl;
  // todo move this to component
  cout<<"network diameter: "<<importer->depth_first_search(tree)<<endl;
  // todo move this to component
  // todo make this a server
  delete importer;
  delete tree;
  return 0;
}