#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <vector>
#include <string>
#include "aa_node.h"
#include "aa_tree.h"
#include "decorator_not_seen.h"

using namespace boost::python;
using namespace std;

void (AaTree<AaNode<string, vector<string> >, string >::*insert_key)(string, string) = &AaTree<AaNode<string, vector<string> >, string >::insert;
void (AaTree<AaNode<string, vector<string> >, string >::*remove_key)(string) = &AaTree<AaNode<string, vector<string> >, string >::remove;
AaNode<string, vector<string> >* (AaTree<AaNode<string, vector<string> >, string >::*find_key)(string) = &AaTree<AaNode<string, vector<string> >, string >::find;
void (AaTree<AaNode<string, vector<string> >, string >::*visited)(string, bool) = &AaTree<AaNode<string, vector<string> >, string >::visited;
bool (AaTree<AaNode<string, vector<string> >, string >::*is_visited)(string, bool) = &AaTree<AaNode<string, vector<string> >, string >::is_visited;
int (AaTree<AaNode<string, vector<string> >, string >::*level)() = &AaTree<AaNode<string, vector<string> >, string >::level;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(visited_default, visited, 1, 2);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(is_visited_default, is_visited, 1, 2);

BOOST_PYTHON_MODULE(AaTree) {
  class_<DecoratorNotSeen>("DecoratorNotSeen").
  def("visit", &DecoratorNotSeen::visit<AaNode<string, vector<string> > >);
  class_<std::vector<string> >("aa_tree_value")
  .def(vector_indexing_suite<vector<string> >());
  class_<AaNode<string, vector<string> > >("AaNode", init<string, string>())
  .def_readwrite("key", &AaNode<string, vector<string> >::key)
  .def_readwrite("value", &AaNode<string, vector<string> >::value)
  .def_readwrite("left", &AaNode<string, vector<string> >::left)
  .def_readwrite("right", &AaNode<string, vector<string> >::right)
  .def_readwrite("level", &AaNode<string, vector<string> >::level)
  .def_readwrite("visited", &AaNode<string, vector<string> >::visited);
  class_<AaTree<AaNode<string, vector<string> >, string> >("AaTree")
  .def("insert_key", insert_key)
  .def("remove_key", remove_key)
  .def("find_key", find_key, return_value_policy<manage_new_object>())
  .def("visited", visited, visited_default())
  .def("is_visited", is_visited, is_visited_default())
  .def("level", level);
};