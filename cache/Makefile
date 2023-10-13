builddir=bin

all:  $(builddir) $(builddir)/cache_lfu  $(builddir)/cache_lru  $(builddir)/cache_ideal

$(builddir):
	mkdir $(builddir)

$(builddir)/cache_lfu: cache_lfu.cpp
	g++ cache_lfu.cpp -o $(builddir)/cache_lfu

$(builddir)/cache_lru: cache_lru.cpp
	g++ cache_lru.cpp -o $(builddir)/cache_lru

$(builddir)/cache_ideal: cache_ideal.cpp
	g++ cache_ideal.cpp -o $(builddir)/cache_ideal

test: tests all
	./make_tests.sh

generate_tests:
	./generate_tests.sh

clean:
	rm $(builddir)/*
	rm -r tests