libMikuDuino.so : MikuPi.cpp MikuDuino.cpp MikuRelay.cpp MikuSHT2x.cpp Wire.cpp MikuOled.cpp
	@gcc $^ -fPIC -shared -o $@
	@install $@ /usr/lib/
	@install *.h /usr/include/
	@install fonts/mikupi.font /usr/share/fonts
	@rm -f *.so
	@echo 'install OK!'
.PHONY : clean
clean :
	@rm -f *.so
	@echo 'clean'