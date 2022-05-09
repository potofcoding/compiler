build:
	cd builddir && meson compile

run:
	cd builddir ; ./demo ../tests/test.c