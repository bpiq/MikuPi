libMikuDuino.so : MikuPi.c MikuDuino.c
	@gcc MikuPi.c MikuDuino.c -fPIC -shared -o libMikuDuino.so
	@install libMikuDuino.so /usr/lib/
	@install *.h /usr/include/
	@rm -f *.so
	@echo 'install OK!'
.PHONY : clean
clean :
	@rm -f *.so
	@echo 'clean'