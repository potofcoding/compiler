build:
	cd builddir && meson compile

run1:
	cd builddir ; ./demo ../tests/test.c

run2:
	cd builddir ; ./demo ../tests/test2.c

run3:
	cd builddir ; ./demo ../tests/test3.c