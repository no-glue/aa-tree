#include <boost/python.hpp>
#include "aa_tree.h"

using namespace boost::python;

void (AaTree::*insert)(string, string) = &AaTree::insert;

BOOST_PYTHON_MODULE(AaDictionary) {
  class_<AaTree>("AaTree").def("insert", insert);
};