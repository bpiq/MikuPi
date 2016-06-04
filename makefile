libMikuDuino.so : MikuPi.cpp MikuDuino.cpp
	@gcc MikuPi.cpp MikuDuino.cpp -fPIC -shared -o libMikuDuino.so
	@install libMikuDuino.so /usr/lib/
	@install *.h /usr/include/
	@rm -f *.so
	@echo 'install OK!'
.PHONY : clean
clean :
	@rm -f *.so
	@echo 'clean'