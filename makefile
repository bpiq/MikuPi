CC              := gcc
LD              := ld
CFLAGS          :=
LDFLAGS         := -shared -fpic
SOURCE          := MikuPi.cpp MikuDuino.cpp MikuRelay.cpp MikuSHT2x.cpp Wire.cpp MikuOled.cpp
HEADER          := $(wildcard *.h)
OBJS            := $(patsubst %.cpp,%.o,$(SOURCE))
TARGET_LIB      := libMikuDuino.so
FONT            := fonts/mikupi.font
INSTALL_LIB     := /usr/lib
INSTALL_INCLUDE := /usr/include
INSTALL_FONT    := /usr/share/fonts
all:$(OBJS)
	@echo $(OBJS)
	$(LD) $(LDFLAGS) -o  $(TARGET_LIB) $(OBJS) 

%.o:%.cpp
	@echo Compiling $< ...
	$(CC) -c $(CFLAGS)  $< -o $*.o
install:
	install $(FONT) $(INSTALL_FONT)
	install $(TARGET_LIB) $(INSTALL_LIB)
	install $(HEADER) $(INSTALL_INCLUDE)
.PHONY: clean

clean:
	rm *.so *.o -rf
