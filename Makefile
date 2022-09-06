
#
# Makefile for P4 (submitted version)
# COSC 052
# Fall 2019
#

DRIVER_NAME = main
SUBMIT_NAME = submit
LIBRARY_NAME = agLibrary
RESULTS_NAME = P4ExperimentResultsTable.pdf


a.out: $(DRIVER_NAME).o Resources.o Exceptions.o ProcessTimer.o
	g++ -std=c++11 $(DRIVER_NAME).o Resources.o Exceptions.o ProcessTimer.o

$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h LL.h Resources.h LL_adapters.h
	g++ -std=c++11 -c $(DRIVER_NAME).cpp

Resources.o: Resources.cpp Resources.h
	g++ -std=c++11 -c Resources.cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	g++ -std=c++11 -c Exceptions.cpp

ProcessTimer.o: ProcessTimer.cpp ProcessTimer.h
	g++ -std=c++11 -c ProcessTimer.cpp

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(RESULTS_NAME) $(DRIVER_NAME).cpp $(DRIVER_NAME).h LL.h LL_adapters.h Exceptions.cpp Exceptions.h Resources.cpp Resources.h ProcessTimer.cpp ProcessTimer.h Makefile

clean:
	rm -f *.o core a.out


