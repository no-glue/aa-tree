#include <boost/python.hpp>
#include "aa_tree.h"

using namespace boost::python;

void (AaTree::*insert_key)(string, string) = &AaTree::insert;
void (AaTree::*remove_key)(string) = &AaTree::remove;
AaNode* (AaTree::*find_key)(string) = &AaTree::find;
int (AaTree::*level)() = &AaTree::level;

BOOST_PYTHON_MODULE(AaDictionary) {
  class_<AaTree>("AaTree").def("insert_key", insert_key).def("remove", remove_key).def("find_key", find_key).def("level", level);
};