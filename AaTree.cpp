#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "aa_tree.h"

using namespace boost::python;

void (AaTree::*insert_key)(string, string) = &AaTree::insert;
void (AaTree::*remove_key)(string) = &AaTree::remove;
AaNode* (AaTree::*find_key)(string) = &AaTree::find;
void (AaTree::*visited)(string, bool) = &AaTree::visited;
bool (AaTree::*is_visited)(string, bool) = &AaTree::is_visited;
int (AaTree::*level)() = &AaTree::level;

BOOST_PYTHON_MODULE(AaTree) {
  class_<std::vector<string> >("aa_tree_value")
  .def(vector_indexing_suite<vector<string> >());
  class_<AaNode>("AaNode", init<string, string>())
  .def_readwrite("key", &AaNode::key)
  .def_readwrite("value", &AaNode::value)
  .def_readwrite("left", &AaNode::left)
  .def_readwrite("right", &AaNode::right)
  .def_readwrite("level", &AaNode::level)
  .def_readwrite("visited", &AaNode::visited);
  class_<AaTree>("AaTree")
  .def("insert_key", insert_key)
  .def("remove_key", remove_key)
  .def("find_key", find_key, return_value_policy<manage_new_object>())
  .def("visited", visited)
  .def("visited", is_visited)
  .def("level", level);
};