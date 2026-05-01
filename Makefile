CXX      := clang++
CXXFLAGS := -std=c++23 -I/opt/homebrew/include -I./inc

BUILDDIR := build

SRC_COMP := $(wildcard src/*.cc)
SRC_SC   := $(wildcard src/showcase/*.cc)
SRCS     := $(SRC_COMP) $(SRC_SC)

OBJS := $(patsubst src/%.cc,$(BUILDDIR)/src/%.o,$(SRC_COMP)) \
        $(patsubst src/showcase/%.cc,$(BUILDDIR)/src/showcase/%.o,$(SRC_SC))

BIN := $(BUILDDIR)/generate

.PHONY: generate

generate: $(BIN)
	$(BIN)

$(BIN): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/src/%.o: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/src/showcase/%.o: src/showcase/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
