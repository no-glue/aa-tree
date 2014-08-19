#include "importer.h"

int main() {
  AaTree * tree = new AaTree();
  Importer * importer = new Importer();
  importer->import("../../node/netmark/data/split/", tree);
  delete importer;
  delete tree;
  return 0;
}