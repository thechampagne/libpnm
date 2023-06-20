CXX ?= g++
LIBS := libpnm.a libpnm.so

.PHONY: all
all: $(LIBS)

libpnm.a: main.cpp
	$(CXX) -c $< -o pnm.o
	ar -crs libpnm.a pnm.o
	rm pnm.o

libpnm.so: main.cpp
	$(CXX) -shared -fPIC $< -o libpnm.so

.PHONY: clean
clean:
	find . -type f \( -name '*.so' -o -name '*.a' \) -delete
