#names of src files
MATH_LIB_NAME = math_lib
TEST_BIN = tdd_math

#name of output path
O_PATH = build/

MATH_LIB_NAME := $(O_PATH)$(MATH_LIB_NAME)
TEST_BIN := $(O_PATH)$(TEST_BIN)

#testing framework path
TESTLIB_NAME = libgtest
TEST_DIR = googletest-master/
TEST_SRC = $(TEST_DIR)googletest/

#compiler settings
CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++11

all:

pack:

clean:
	rm -f $(O_PATH)*

test: $(O_PATH) $(TEST_BIN)
	./$(TEST_BIN)

doc:

run:

profile:


#----------------------------TEST COMPILATION----------------------------------

#linking binary with test
$(TEST_BIN) : $(TEST_BIN).o $(MATH_LIB_NAME).o
	$(CXX) -o $@ $^ -L$(TEST_SRC)lib -lgtest -lpthread

#compilation of obj file with test
$(TEST_BIN).o : $(notdir $(TEST_BIN).cpp) $(TEST_SRC)lib/$(TESTLIB_NAME).a
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(TEST_SRC)include

#compilation of the lib (.a) with google test (if it is not compilated)
#cmake is used (due to instructions in googlest-master/googletest/README.md)
$(TEST_SRC)lib/%.a : $(TEST_DIR)
	cd $(TEST_SRC) && cmake .. && make -s && cd ../..

#if there is no folder with testing framework, try to download it by git
#and rename it
$(TEST_DIR):
	git clone https://github.com/google/googletest.git $(TEST_DIR)

$(O_PATH)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(O_PATH) : 
	mkdir $@
