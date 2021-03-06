include nall/Makefile

qtlibs := QtCore QtGui QtWidgets
include nall/qt/Makefile

ifeq ($(OSX_USE_GCC), 1)
# openmp is not available with clang, so optionally check if g++ is available.
# if so, compile only snesreader using that with full filter support
# (check for specific version since "g++" is aliased to clang)
  ifneq ($(shell command -v g++-6 2> /dev/null),)
    compiler      := g++-6
    osx_with_gcc  :=1
  endif
endif

c     := $(compiler) -xc -std=gnu99
cpp   := $(compiler) -std=gnu++11
flags := -I. -Iobj $(qtinc)
link  :=

ifeq ($(DEBUG), 1)
  flags += -O0 -g
else
  flags += -O3 -fomit-frame-pointer
endif

# silence warnings
flags += -Wno-switch -Wno-absolute-value -Wno-parentheses

ifeq ($(platform),x)
  flags := -fPIC -fopenmp $(flags)
  link += -s -fopenmp -lpthread -lgomp
else ifeq ($(platform),osx)
  ifeq ($(osx_with_gcc),)
    flags += -fPIC -mmacosx-version-min=10.9
    link += -lpthread -mmacosx-version-min=10.9 -headerpad_max_install_names
  else
    flags += -fPIC -fopenmp -mmacosx-version-min=10.9
    link += -fopenmp -lpthread -lgomp -mmacosx-version-min=10.9 -headerpad_max_install_names
  endif
else ifeq ($(platform),win)
  flags := -fopenmp $(flags)
  link += -fopenmp -lpthread
endif

objects := snesfilter

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

all: build;

objects := $(patsubst %,obj/%.o,$(objects))
moc_headers := $(call rwildcard,./,%.moc.hpp)
moc_objects := $(foreach f,$(moc_headers),obj/$(notdir $(patsubst %.moc.hpp,%.moc,$f)))

# automatically run moc on all .moc.hpp (MOC header) files
%.moc: $<; $(moc) -i $< -o $@

# automatically generate %.moc build rules
__list = $(moc_headers)
$(foreach f,$(moc_objects), \
  $(eval __file = $(word 1,$(__list))) \
  $(eval __list = $(wordlist 2,$(words $(__list)),$(__list))) \
  $(eval $f: $(__file)) \
)

##################
### snesfilter ###
##################

obj/snesfilter.o: snesfilter.cpp *

###############
### targets ###
###############

build: $(moc_objects) $(objects)
ifeq ($(platform),x)
	ar rcs libsnesfilter.a $(objects)
	$(cpp) $(link) -o libsnesfilter.so -shared -Wl,-soname,libsnesfilter.so.1 $(objects) $(qtlib)
else ifeq ($(platform),osx)
	ar rcs libsnesfilter.a $(objects)
	$(cpp) $(link) -o libsnesfilter.dylib -shared -dynamiclib $(objects) $(qtlib)
else ifeq ($(platform),win)
	$(cpp) $(link) -o snesfilter.dll -shared -Wl,--out-implib,libsnesfilter.a $(objects) $(qtlib)
endif

install:
ifeq ($(platform),x)
	install -D -m 755 libsnesfilter.a $(DESTDIR)$(prefix)/lib
	install -D -m 755 libsnesfilter.so $(DESTDIR)$(prefix)/lib
	ldconfig -n $(DESTDIR)$(prefix)/lib
else ifeq ($(platform),osx)
	cp libsnesfilter.dylib /usr/local/lib/libsnesfilter.dylib
endif

clean:
	-@$(call delete,obj/*.o)
	-@$(call delete,obj/*.moc)
	-@$(call delete,libsnesfilter.a)
	-@$(call delete,libsnesfilter.so)
	-@$(call delete,libsnesfilter.dylib)
	-@$(call delete,snesfilter.dll)
