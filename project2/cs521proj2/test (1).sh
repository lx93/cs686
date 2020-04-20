#!/usr/bin/env bash

TESTS=(
    'a\nb\nc:a'
    'a\n:a'
    'a:...'
    'abc:.b.'
    'h\naaaaah:a+h'
    'h\naaaaahhhhh:aa+hh+'
    'h\naaaaahhhhh\n:aa+hh+'
    'woot\nwot\nwat\n:wo?t'
    'CCCCCCC\nC+\nC++:.\+\+'
    'GG:G+'
    'USF_CS552211.jpg:U.F_CL?S552+11\.jpg'
    'woot\nwot\nwat\n:wo?tt'
    'woot\nwott\nwat\n:wo?tt'
    'woot\nwtt\nwat\n:wo?tt'
    'hello.:\.?'
    '\\\\\\\\:\\+'
    'hello...:\.+'
    'hello...:o\.+'
    'hello...:a\.+'
    # near the end
    'hello.C++:\.C\++'
    'hello.C++:o\.C\++'
    'hello.C++:a\.C\++'
    'hello..C++:\.C\++'
    'hello..C++:.\.C\++'
    'hello..C++:o.\.C\++'
    'hello..C++:a.\.C\++'
    'hello..C++:\.\.C\++'
    'hello..C++:\.+C\++'
    'hello..C++:o\.+C\++'
    'hello..C++:a\.+C\++'
    'hello..C++:\.?C\++'
    'hello.C++:\.?C\++'
    'hello.C++:o\.?C\++'
    'hello.C++:a\.?C\++'
    # in the middle
    'hello.C++1:\.C\++'
    'hello.C++1:o\.C\++'
    'hello.C++1:a\.C\++'
    'hello..C++1:\.C\++'
    'hello..C++1:.\.C\++'
    'hello..C++1:o.\.C\++'
    'hello..C++1:a.\.C\++'
    'hello..C++1:\.\.C\++'
    'hello..C++1:\.+C\++'
    'hello..C++1:o\.+C\++'
    'hello..C++1:a\.+C\++'
    'hello..C++1:\.?C\++'
    'hello.C++1:\.?C\++'
    'hello.C++1:o\.?C\++'
    'hello.C++1:a\.?C\++'
    # hmmm
    'hello..C++:o\.C\++'
)

printf "Recompiling rgrep\n"

make clean
if ! make default; then
    printf "Cannot compile rgrep\n"
    exit 1
fi

LEN=${#TESTS[@]}
INDEX=1
for test in "${TESTS[@]}"; do
    TEXT="${test%%:*}"
    PATTERN="${test#*:}"
    printf "(%d/%d) Matching \"%s\" with \"%s\"\n" "$INDEX" "$LEN" "$TEXT" "$PATTERN"
    INDEX=$((INDEX+1))
    RGREP_OUTPUT=$(echo -e $TEXT | ./rgrep $PATTERN)
    GREP_OUTPUT=$(echo -e $TEXT | grep -E $PATTERN)
    printf "grep Output: %s\nrgrep output: %s\n\n" "$GREP_OUTPUT" "$RGREP_OUTPUT"
    if [ "$RGREP_OUTPUT" != "$GREP_OUTPUT" ]; then
        printf "Test failed.\n"
        exit 1
    fi
done

echo "Tests passed"
