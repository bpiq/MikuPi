libMikuDuino.so : MikuPi.cpp MikuDuino.cpp MikuRelay.cpp
	@gcc $^ -fPIC -shared -o $@
	@install $@ /usr/lib/
	@install *.h /usr/include/
	@rm -f *.so
	@echo 'install OK!'
.PHONY : clean
clean :
	@rm -f *.so
	@echo 'clean'