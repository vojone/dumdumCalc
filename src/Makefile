#names of src files
MATH_LIB_NAME = math_lib

TEST_BIN = tdd_math

APP_BIN = calculator

PROF_NAME = math_prof
PROF_SAMPLE = profiling_sample

#name of folder in which is gui implementation
GUI_DIR = gui/
<<<<<<< HEAD
DOC_DIR = Documentation
=======
DOC_DIR = documentation
>>>>>>> e40c99ffdcc665f1b48831378560c0741a303664

#output path
O_PATH = build/

#testing framework path
TESTLIB_NAME = libgtest
TEST_DIR = googletest-master/googletest/

#compiler settings
CXX = g++
CXXFLAGS := -Werror -Wall -pedantic -std=c++11

CC = g++
LDLIBS=-lm

CMAKEFLAGS :=

.PHONY: all pack clean test doc run profile install callgrind debug
all:

pack:

clean:
	rm -rf $(O_PATH) $(DOC_DIR) dumdumCalc.deb dumdumCalc/usr/bin/calculator gui/calculator gui/calculator_autogen gui/CMakeCache.txt gui/CMakeFiles gui/cmake_install.cmake

test: $(O_PATH) $(O_PATH)$(TEST_BIN) 
	./$(O_PATH)$(TEST_BIN)
	
install:
	cmake gui/CMakeLists.txt
	make -C gui
	cp gui/calculator dumdumCalc/usr/bin
	dpkg-deb --build dumdumCalc

doc:
	doxygen

run: $(O_PATH) $(O_PATH)$(APP_BIN)
	./$(O_PATH)$(APP_BIN)
	

profile: CXXFLAGS := -O2 $(CXXFLAGS)
profile: LDFLAGS := -O2 $(LDFLAGS)
profile: $(O_PATH) $(O_PATH)$(PROF_NAME)
	./$(O_PATH)$(PROF_NAME) < $(PROF_SAMPLE)

#-------------------------------APP DEBUG--------------------------------------

debug: CMAKEFLAGS := -DCMAKE_BUILD_TYPE=Debug $(CMAKEFLAGS)
debug: $(O_PATH) $(O_PATH)$(APP_BIN)
	gdb -tui $(O_PATH)$(APP_BIN)

#-------------------------------PROFILING--------------------------------------

$(O_PATH)$(PROF_NAME) : $(O_PATH)$(PROF_NAME).o $(O_PATH)$(MATH_LIB_NAME).o

PROFOUT := callgrind-prof$(ARGS).out

callgrind: profile
	valgrind --tool=callgrind --callgrind-out-file=$(PROFOUT) \
	./$(O_PATH)$(PROF_NAME) < $(PROF_SAMPLE)

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
	
#--------------------------------APP BUILD------------------------------------

$(O_PATH)$(APP_BIN):
	cd $(O_PATH) && cmake $(CMAKEFLAGS) ../$(GUI_DIR). 
	cd $(O_PATH) && make -s

#------------------------------GENERAL TARGETS---------------------------------

#ALL obj files need math_lib header file
$(O_PATH)%.o : %.cpp $(MATH_LIB_NAME).h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(O_PATH) : 
	mkdir $@

#------------------------------------END---------------------------------------
