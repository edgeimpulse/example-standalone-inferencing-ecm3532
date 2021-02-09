#include "config.h"
#define STR2(x) #x
#define STR(x) STR2(x)
#define BIN_SEC CONFIG_BIN_FILE_SECTION

#define INCBIN(name, file) \
     __asm__(".section "BIN_SEC",\"ax\"\n" \
            ".global incbin_" STR(name) "_start\n" \
            ".type incbin_" STR(name) "_start, %object\n" \
            ".balign 16\n" \
            "incbin_" STR(name) "_start:\n" \
            ".incbin \"" file "\"\n" \
            \
            ".global incbin_" STR(name) "_end\n" \
            ".type incbin_" STR(name) "_end, %object\n" \
            ".balign 1\n" \
            "incbin_" STR(name) "_end:\n" \
            ".byte 0\n" \
    ); \
    extern const  __attribute__((section("BIN_SEC"))) __attribute__((aligned(16))) void* incbin_ ## name ## _start; \
    extern const void*  __attribute__((section("BIN_SEC"))) incbin_ ## name ## _end;
