LLVM ?= 1

ifeq ($(LLVM),1)
    LLVM_PREFIX := /opt/homebrew/opt/llvm
    CC := $(LLVM_PREFIX)/bin/clang
    LD := $(LLVM_PREFIX)/bin/ld.lld
    CPPFLAGS += -I$(LLVM_PREFIX)/include
    CPPFLAGS += -I./include
    LDFLAGS += -L$(LLVM_PREFIX)/lib -fuse-ld=lld
else
    CC := clang
    LD := ld
endif

CFLAGS ?= -std=c17 -O2 -Wall -Wextra

.PHONY: clean cleanall

%:
	@if [ -f "$@.c" ]; then \
		$(CC) $(CPPFLAGS) $(CFLAGS) "$@.c" -o "$@.exe" $(LDFLAGS) && \
		echo "$@.c -> $@.exe"; \
	else \
		echo "No source file $@.c"; \
		exit 1; \
	fi

%.exe: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ $(LDFLAGS)
	@echo "$< -> $@"

%.c:
	SRC:=$(patsubst %.c,%,$@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $@ -o $(SRC).exe $(LDFLAGS)
	@echo "$@ -> $(SRC).exe"


clean:
	rm -f *.exe

cleanall:
	rm -f */*.exe