/**
 * You can modify this file.
 */

#include "matcher.h"
#include <stdio.h>
#include <string.h>
/**
 * Your helper functions can go below this line
 */



/**
 * Your helper functions can go above this line
 */


/**
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
	if (*pattern==0) return 1;
	else if (*partial_line==0) return 0;
	else if (*pattern=='\\') {
		if (*(pattern+1)!=*partial_line) return 0;
		else return matches_leading(partial_line+1,pattern+2);
	}
	else {
		//printf("Comparing two chars: %c & %c     \n", *partial_line,*pattern);
	
		if (*pattern=='.') return matches_leading(partial_line+1,pattern+1);
		else if (*pattern=='+'){
			while (*partial_line==*(pattern-1)) partial_line++;
			return matches_leading(partial_line,pattern+1);
		}
		else if (*(pattern+1)=='?') {
			if (*pattern==*partial_line) return matches_leading(partial_line+1,pattern+2);
			else if (*partial_line==*(pattern+2)) return matches_leading(partial_line,pattern+2);
			else return 0;
		}
		else if (*pattern==*partial_line)return matches_leading(partial_line+1,pattern+1);
		else return 0;
	}
}

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {
	while (*line!=0) if(matches_leading(line++,pattern)==1) return 1;
	return 0;	
}
