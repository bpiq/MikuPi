CC:=gcc
LLIB:=-lMikuDuino
SRC=$(wildcard *.cpp)
BINS=$(SRC:.cpp=)
all:$(BINS)
	@echo
	@echo Mission Completed!
	@echo
%:%.cpp
	@echo Compiling $< ...
	$(CC) -o $@ $< $(LLIB)
.PHONY: clean
clean:
	rm $(BINS) -rf
