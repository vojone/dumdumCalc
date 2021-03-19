#names of src files
MATH_LIB_NAME = math_lib
TEST_BIN = tdd_math

#output path
O_PATH = build/

MATH_LIB_NAME := $(O_PATH)$(MATH_LIB_NAME)
TEST_BIN := $(O_PATH)$(TEST_BIN)

#testing framework path
TESTLIB_NAME = libgtest
TEST_DIR = googletest-master/googletest/

#compiler settings
CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++11

.PHONY: all pack clean test doc run profile
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
	$(CXX) -o $@ $^ -L$(TEST_DIR)lib -lgtest -lpthread

#compilation of obj file with test
$(TEST_BIN).o : $(notdir $(TEST_BIN).cpp) $(TEST_DIR)lib/$(TESTLIB_NAME).a
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(TEST_DIR)include

#compilation of the lib (.a) with google test (if it is not compilated)
#cmake is used (due to instructions in googlest-master/googletest/README.md)
$(TEST_DIR)lib/%.a :
	cd $(TEST_DIR) && cmake .. && make -s

$(O_PATH)%.o : $(notdir %.cpp)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(O_PATH) : 
	mkdir $@
