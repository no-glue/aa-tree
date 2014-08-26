# Name of the file(s) we're compiling

TARGET = AaTree

# location of the Python header files

PYTHON = /usr/include/python2.7

# location of the Boost Python include files and library

BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

$(TARGET).so: $(TARGET).o
	g++ -shared -Wl,--export-dynamic \
	$(TARGET).o -L$(BOOST_LIB) -lboost_python \
	-L/usr/lib/python2.1/config -lpython2.4 \
	-o AaTree.so

$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON) -I$(BOOST_INC) -c $(TARGET).cpp

clean:
	rm -f *.o *.dll *.a *~ core
