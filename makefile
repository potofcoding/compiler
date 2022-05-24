build:
	cd builddir && meson compile

runs1:
	cd builddir ; ./demo ../tests/test.c

runs2:
	cd builddir ; ./demo ../tests/test2.c

runs3:
	cd builddir ; ./demo ../tests/test3.c