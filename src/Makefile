#names of src files
MATH_LIB_NAME = math_lib

TEST_BIN = tdd_math

PROF_NAME = math_prof
PROF_SAMPLE = profiling_sample


#output path
O_PATH = build/

#testing framework path
TESTLIB_NAME = libgtest
TEST_DIR = googletest-master/googletest/

#compiler settings
CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++11

CC = g++
LDLIBS=-lm

.PHONY: all pack clean test doc run profile
all:

pack:

clean:
	rm -f $(O_PATH)*

test: $(O_PATH) $(O_PATH)$(TEST_BIN)
	./$(O_PATH)$(TEST_BIN)

doc:

run:

profile: $(O_PATH) $(O_PATH)$(PROF_NAME)
	./$(O_PATH)$(PROF_NAME) < $(PROF_SAMPLE)

#-------------------------------PROFILING--------------------------------------

$(O_PATH)$(PROF_NAME) : $(O_PATH)$(PROF_NAME).o $(O_PATH)$(MATH_LIB_NAME).o

#----------------------------TEST COMPILATION----------------------------------

#linking binary with test
$(O_PATH)$(TEST_BIN) : $(O_PATH)$(TEST_BIN).o $(O_PATH)$(MATH_LIB_NAME).o
	$(CC) -o $@ $^ -L$(TEST_DIR)lib -lgtest -lpthread $(LDLIBS)

#compilation of obj file with test
$(O_PATH)$(TEST_BIN).o : $(TEST_BIN).cpp $(TEST_DIR)lib/$(TESTLIB_NAME).a
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(TEST_DIR)include

#compilation of the lib (.a) with google test (if it is not compilated)
#cmake is used (due to instructions in googlest-master/googletest/README.md)
$(TEST_DIR)lib/%.a :
	cd $(TEST_DIR) && cmake .. && make -s

#------------------------------GENERAL TARGETS---------------------------------

#ALL obj files need math_lib header file
$(O_PATH)%.o : %.cpp $(MATH_LIB_NAME).h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(O_PATH) : 
	mkdir $@

#------------------------------------END---------------------------------------
