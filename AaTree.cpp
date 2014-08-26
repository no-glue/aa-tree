#include <boost/python.hpp>
#include "aa_tree.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(AaDictionary) {
  class_<AaTree>("AaTree").
  def("insert", &AaTree::insert).
  def("remove", &AaTree::remove).
  def("find", &AaTree::find).
  def("level", &AaTree::level);
};