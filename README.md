# AA Tree
Dictionary based on AA Tree and social network analytic toolkit.
  
## Example use
AaTree * tree = new AaTree();
  
tree->insert("some_key", "some_value");
  
tree->find("some_key");
  
tree->remove("some_key");
  
delete tree;
  
## Social network
metrics->nodes(tree) // gives number of nodes
  
metrics->edges(tree) // gives number of edges
  
metrics->density(tree) // gives density
  
metrics->average_degree(tree) // gives average degree
  
metrics->breadth_first_search(tree, av_path_len, bfs_message) // decorated to give average path length
  
metrics->breadth_first_search(tree, get_max_depth, bfs_message) // decorated to give network diameter
  
## How to compile
g++ -Wall -W -fpermissive -std=c++11 importer.cpp -o importer // compile examples
  
g++ -Wall -W -fpermissive -std=c++11 test_tree.cpp -o test_tree // compile tree test
  
## How to run
cat some_files | ./importer // to run examples
  
./test_tree // to run tests
  
## Tested with
http://snap.stanford.edu/data/#communities