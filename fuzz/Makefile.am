# fuzz 디렉토리의 Makefile.am
# 이 디렉토리에서 fuzz 테스트를 수행할 수 있습니다.

# Define the fuzz test programs
noinst_PROGRAMS = libidn2_to_ascii_8z_fuzzer libidn2_to_unicode_8z8z_fuzzer

# Source files for the fuzz test programs
libidn2_to_ascii_8z_fuzzer_SOURCES = libidn2_to_ascii_8z_fuzzer.c
libidn2_to_unicode_8z8z_fuzzer_SOURCES = libidn2_to_unicode_8z8z_fuzzer.c

# Linker flags for the fuzz test programs
libidn2_to_ascii_8z_fuzzer_LDADD = ../lib/libidn2.la
libidn2_to_unicode_8z8z_fuzzer_LDADD = ../lib/libidn2.la

# Additional files needed for fuzzing
EXTRA_DIST = libidn2_to_ascii_8z_fuzzer.dict libidn2_to_unicode_8z8z_fuzzer.dict README.md run-afl.sh run-clang.sh suppressions.valgrind libidn2_register_fuzzer.in libidn2_to_ascii_8z_fuzzer.in libidn2_to_ascii_8z_fuzzer.repro libidn2_to_unicode_8z8z_fuzzer.in fuzzer.h get_all_corpora get_ossfuzz_corpora libidn2_register_fuzzer.c
