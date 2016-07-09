CC              := gcc
LD              := ld
CFLAGS          :=
LDFLAGS         := -shared -fpic
SOURCE          := MikuPi.cpp MikuDuino.cpp MikuRelay.cpp MikuSHT2x.cpp Wire.cpp MikuOled.cpp
OBJS            := $(patsubst %.cpp,%.o,$(SOURCE))
TARGET_LIB      := libMikuDuino.so

all:$(OBJS)
	@echo $(OBJS)
	$(LD) $(LDFLAGS) -o  $(TARGET_LIB) $(OBJS) 

%.o:%.cpp
	@echo Compiling $< ...
	$(CC) -c $(CFLAGS)  $< -o $*.o

.PHONY: clean

clean:
	rm *.so *.o -rf
