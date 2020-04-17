CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic

default:
	$(CC) $(FLAGS) rgrep.c matcher.c -o rgrep

clean:
	rm -f rgrep
	rm -rf *.dSYM

check:
	test "`echo "a\nb\nc" | grep 'a'`" = "a"
	test "`echo "a\n" | grep 'a'`" = "a"
	test "`echo "a" | grep '...'`" = ""
	test "`echo "abc" | grep '.b.'`" = "abc"
	test "`echo "h\naaaaah" | grep -E 'a+h'`" = "aaaaah"
	test "`echo "h\naaaaahhhhh" | grep -E 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "h\naaaaahhhhh\n" | grep -E 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo "woot\nwot\nwat\n" | grep -E 'wo?t'`" = "wot"
	test "`echo "CCCCCCC\nC+\nC++" | grep -E '.\+\+'`" = "C++"
	test "`echo "GG" | grep -E 'G+'`" = "GG"
	test "`echo "USF_CS552211.jpg" | grep -E 'U.F_CL?S552+11\.jpg'`" = "USF_CS552211.jpg"
	test "`echo "test1" | grep "."`" = "test1"
	test "`echo "a\nb\nc" | grep -E "a+"`" = "a"
	test "`echo "test3" | grep -E "tet?st3"`" = "test3"
	test "`echo "test4.txt" | grep -E "test4\.txt"`" = "test4.txt"
	@echo "Passed sanity check." 
