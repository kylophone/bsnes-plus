include nall/Makefile
snes := snes
ifeq ($(profile),)
  profile := compatibility
endif
ifeq ($(ui),)
  ui := ui-qt
endif

# build version
version := v073+3a

# compiler
c       := $(compiler) -xc -std=gnu99
cpp     := $(compiler) -std=gnu++11
flags   := -I. -I$(snes)
link    :=
objects :=
deployqt_flags :=

ifeq ($(DEBUG), 1)
  flags += -O0 -g
  deployqt_flags += -no-strip
else
  flags += -O3 -fomit-frame-pointer
  ifneq ($(platform),osx)
    link += -s
  endif
endif

# comment this line to enable asserts
flags += -DNDEBUG

# profile-guided instrumentation
# flags += -fprofile-generate
# link += -lgcov

# silence warnings
flags += -Wno-switch -Wno-absolute-value -Wno-parentheses

# platform
ifeq ($(platform),x)
  link += -ldl -lX11 -lXext
else ifeq ($(platform),osx)
  osxbundle := ../bsnes+
  ifneq ($(profile),compatibility)
    osxbundle := $(osxbundle)$(profile)
  endif
  osxbundle := $(osxbundle).app
  flags += -mmacosx-version-min=10.9
  link += -mmacosx-version-min=10.9 -headerpad_max_install_names
else ifeq ($(platform),win)
  link += -mwindows
  link += -mthreads -luuid -lkernel32 -luser32 -lgdi32 -lcomctl32 -lcomdlg32 -lshell32 -lole32
  link += -Wl,-enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc
else
  unknown_platform: help;
endif

# implicit rules
compile = \
  $(strip \
    $(if $(filter %.c,$<), \
      $(c) $(flags) $1 -c $< -o $@, \
      $(if $(filter %.cpp,$<), \
        $(cpp) $(flags) $1 -c $< -o $@ \
      ) \
    ) \
  )

%.o: $<; $(call compile)

all: build plugins
	@echo \"all\" done

deploy: all
	$(qtpath)/bin/macdeployqt $(osxbundle) $(deployqt_flags)
	@echo \"deploy\" done

include $(snes)/Makefile
include $(ui)/Makefile

# including CoreFoundation in nall/string/platform.hpp polluted the global namespace
objects += nall-string-platform
obj/nall-string-platform.o: nall/string/platform.cpp

objects := $(patsubst %,obj/%.o,$(objects))

# targets
build: ui_build $(objects)
ifeq ($(platform),osx)
	test -d $(osxbundle) || mkdir -p $(osxbundle)/Contents/MacOS
	$(strip $(cpp) -o $(osxbundle)/Contents/MacOS/bsnes $(objects) $(link))
	mkdir -p $(osxbundle)/Contents/Resources
	cp -f data/bsnes.icns $(osxbundle)/Contents/Resources/AppIcon.icns
	sed 's/@VERSION/$(version)/g' data/Info.plist > $(osxbundle)/Contents/Info.plist
else
	$(strip $(cpp) -o out/bsnes $(objects) $(link))
endif

install: all
ifeq ($(platform),x)
	install -D -m 755 out/bsnes $(DESTDIR)$(prefix)/bin/bsnes
	install -D -m 644 data/bsnes.png $(DESTDIR)$(prefix)/share/pixmaps/bsnes.png
	install -D -m 644 data/bsnes.desktop $(DESTDIR)$(prefix)/share/applications/bsnes.desktop
	test -d ~/.bsnes || mkdir ~/.bsnes
else ifeq ($(platform),osx)
	mv -f $(osxbundle) /Applications/bsnes+.app
else
	@echo Install not available for current platform
endif

uninstall:
ifeq ($(platform),x)
	rm $(DESTDIR)$(prefix)/bin/bsnes
	rm $(DESTDIR)$(prefix)/share/pixmaps/bsnes.png
	rm $(DESTDIR)$(prefix)/share/applications/bsnes.desktop
else ifeq ($(platform),osx)
	rm -rf /Applications/bsnes+.app
else
	@echo Install not available for current platform
endif

plugins:
	@$(MAKE) -C ../snesreader
	@$(MAKE) -C ../snesfilter
	@$(MAKE) -C ../snesmusic
	@$(MAKE) -C ../supergameboy
ifneq ($(profile),accuracy)
	@$(MAKE) -C ../snesfilter
endif
ifeq ($(platform),osx)
	mkdir -p $(osxbundle)/Contents/Frameworks
	cp -f ../snesreader/libsnesreader.dylib $(osxbundle)/Contents/Frameworks/libsnesreader.dylib
	cp -f ../snesfilter/libsnesfilter.dylib $(osxbundle)/Contents/Frameworks/libsnesfilter.dylib
	cp -f ../snesmusic/libsnesmusic.dylib $(osxbundle)/Contents/Frameworks/libsnesmusic.dylib
	cp -f ../supergameboy/libsupergameboy.dylib $(osxbundle)/Contents/Frameworks/libsupergameboy.dylib
ifneq ($(profile),accuracy)
	cp -f ../snesfilter/libsnesfilter.dylib $(osxbundle)/Contents/Frameworks/libsnesfilter.dylib
endif
endif

clean: ui_clean plugins_clean
	-@$(call delete,obj/*.o)
	-@$(call delete,obj/*.a)
	-@$(call delete,obj/*.so)
	-@$(call delete,obj/*.dylib)
	-@$(call delete,obj/*.dll)
	-@$(call delete,*.res)
	-@$(call delete,*.pgd)
	-@$(call delete,*.pgc)
	-@$(call delete,*.ilk)
	-@$(call delete,*.pdb)
	-@$(call delete,*.manifest)

plugins_clean:
	@$(MAKE) clean -C ../snesreader
	@$(MAKE) clean -C ../snesfilter
	@$(MAKE) clean -C ../snesmusic
	@$(MAKE) clean -C ../supergameboy

archive-all:
	tar -cjf bsnes.tar.bz2 data launcher libco nall obj out phoenix ruby snes ui-phoenix ui-qt Makefile cc.bat clean.bat sync.sh

help:;
