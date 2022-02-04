#name of app library
APP_BIN = calculator

#name of app and this version
APP_NAME = dumdumCalc
VERSION = 1.0

#the name of final archive
AR_NAME = xmarek77_xdvora3o_xdvora3r_xdedic07

#names of src files for tests math library and profiling
MATH_LIB_NAME = math_lib

TEST_BIN = tdd_math

#name of profiling program
PROF_NAME = stddev
PROF_SAMPLE = profiling_sample

#name of folder in which is gui implementation
GUI_DIR = gui/

#lists of gui source files
GUI_SRCS := $(wildcard $(GUI_DIR)*.cpp) $(wildcard $(GUI_DIR)*.ui)
GUI_SRCS := $(GUI_SRCS) $(wildcard $(GUI_DIR)*.h)

#folder in which is generated documentation
DOC_DIR = Documentation/

#original name of user manual in PDF
ORIG_MAN = dokumentace
#name of user manual, which will be included to deb. pckg
MAN_NAME = calculator_man

#output path
O_PATH = build/

#testing framework path
TESTLIB_NAME = libgtest
TEST_DIR = googletest/googletest/

#compiler settings
CXX = g++
CXXFLAGS := -Werror -Wall -pedantic -std=c++11

CC = g++
LDLIBS=-lm

#CMAKEFLAGS :=

.PHONY: all pack clean test doc run profile install callgrind debug

all: $(O_PATH) $(O_PATH)$(TEST_BIN) $(O_PATH)$(PROF_NAME) $(O_PATH)$(APP_BIN)
		
pack: clean doc install
	mkdir -p ../repo
	mkdir -p ../doc
	mkdir -p ../install
	cp -r $(DOC_DIR)html/* ../doc
	cp $(APP_NAME)-$(VERSION).deb ../install
	rm -rf $(O_PATH) $(DOC_DIR) $(APP_NAME)-$(VERSION)/usr/bin
	rm -rf $(APP_NAME)-$(VERSION)/usr/share/doc
	rm -f $(APP_NAME)-$(VERSION).deb
	cd .. && cp -r `ls -a | egrep -v '^repo|doc|install|\.\.|\.$$'` repo
	cd .. && zip -r $(AR_NAME).zip repo install doc
	mv  ../$(AR_NAME).zip $(AR_NAME).zip
	cd .. && rm -rf repo install doc

clean:
	rm -rf $(O_PATH) $(DOC_DIR)
	rm -rf $(APP_NAME)-$(VERSION)/usr/bin $(APP_NAME)-$(VERSION)/share/doc
	rm -f $(APP_NAME)-$(VERSION).deb $(AR_NAME).zip
	

test: $(O_PATH) $(O_PATH)$(TEST_BIN) 
	./$(O_PATH)$(TEST_BIN)
	
	
install: $(O_PATH)
	cd $(O_PATH) && cmake ../$(GUI_DIR).
	make -C $(O_PATH)
	mkdir -p $(APP_NAME)-$(VERSION)/usr/bin
	mkdir -p $(APP_NAME)-$(VERSION)/usr/share/doc
	cp $(O_PATH)$(APP_BIN) $(APP_NAME)-$(VERSION)/usr/bin
	cp ../$(ORIG_MAN).pdf $(APP_NAME)-$(VERSION)/usr/share/doc/$(MAN_NAME).pdf
	dpkg-deb --build $(APP_NAME)-$(VERSION)
	

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
$(O_PATH)$(TEST_BIN) : LDLIBS := -L$(TEST_DIR)lib -lgtest -lpthread $(LDLIBS)
$(O_PATH)$(TEST_BIN) : LDFLAGS := -L$(TEST_DIR)lib
$(O_PATH)$(TEST_BIN) : $(O_PATH)$(TEST_BIN).o $(O_PATH)$(MATH_LIB_NAME).o

#compilation of obj file with test
$(O_PATH)$(TEST_BIN).o : CXXFLAGS := $(CXXFLAGS) -I$(TEST_DIR)include
$(O_PATH)$(TEST_BIN).o : $(TEST_BIN).cpp $(TEST_DIR)lib/$(TESTLIB_NAME).a

#compilation of the lib (.a) with google test (if it is not compilated)
#cmake is used (due to instructions in googlest-master/googletest/README.md)
$(TEST_DIR)lib/%.a : $(TEST_DIR)
	cd $(TEST_DIR) && cmake .. && make -s

$(TEST_DIR) : 
	git clone https://github.com/google/googletest.git
	
#--------------------------------APP BUILD------------------------------------

$(O_PATH)$(APP_BIN): $(GUI_SRCS)
	cd $(O_PATH) && cmake $(CMAKEFLAGS) ../$(GUI_DIR). 
	cd $(O_PATH) && make -s

#------------------------------GENERAL TARGETS---------------------------------

#ALL obj files need math_lib header file
$(O_PATH)%.o : %.cpp $(MATH_LIB_NAME).h
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(O_PATH) : 
	mkdir $@

#------------------------------------END---------------------------------------
