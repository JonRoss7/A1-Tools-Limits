/*
  Word Count using dedicated lists
*/

/*
Copyright © 2019 University of California, Berkeley

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <assert.h>
#include <getopt.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "word_count.h"

/* Global data structure tracking the words encountered */
WordCount *word_counts = NULL;

/* The maximum length of each word in a file */
#define MAX_WORD_LEN 64

/*
 * 3.1.1 Total Word Count
 *
 * Returns the total amount of words found in infile.
 * A word is defined as a sequence of contiguous alphabetical characters
 * of length greater than one.
 */
int num_words(FILE* infile) {
    int c;
    int in_word = 0;
    int word_len = 0;
    int total_words = 0;

    while ((c = fgetc(infile)) != EOF) {
        if (isalpha(c)) {
            if (!in_word) {
                in_word = 1;
                word_len = 1;
            } else {
                word_len++;
            }
        } else {
            if (in_word && word_len > 1) {
                total_words++;
            }
            in_word = 0;
            word_len = 0;
        }
    }

    // Count last word if file does not end with a non-alpha character
    if (in_word && word_len > 1) {
        total_words++;
    }

    rewind(infile); // Reset file pointer for reuse
    return total_words;
}

// Minimal implementations for compatibility with word_count.h
void count_words(WordCount **wclist, FILE *infile) {}
static bool wordcount_less(const WordCount *wc1, const WordCount *wc2) { return 0; }

// Display help message
static int display_help(void) {
    printf("Flags:\n"
           "--count (-c): Count the total amount of words in the file, or STDIN if a file is not specified.\n"
           "--frequency (-f): Count the frequency of each word in the file (not used in this task).\n"
           "--help (-h): Displays this help message.\n");
    return 0;
}

int main(int argc, char *argv[]) {
    bool count_mode = true;
    int total_words = 0;
    bool freq_mode = false;

    FILE *infile = NULL;

    // Command-line parsing
    int i;
    static struct option long_options[] = {
        {"count", no_argument, 0, 'c'},
        {"frequency", no_argument, 0, 'f'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((i = getopt_long(argc, argv, "cfh", long_options, NULL)) != -1) {
        switch (i) {
            case 'c':
                count_mode = true;
                freq_mode = false;
                break;
            case 'f':
                count_mode = false;
                freq_mode = true;
                break;
            case 'h':
                return display_help();
        }
    }

    if (!count_mode && !freq_mode) {
        printf("Please specify a mode.\n");
        return display_help();
    }

    map_init();

    /* Create empty data structure */
    init_words(&word_counts);

    /* Open file or use stdin */
    if ((argc - optind) < 1) {
        infile = stdin;
    } else {
        infile = fopen(argv[optind], "r");
        if (!infile) {
            perror(argv[optind]);
            return 1;
        }
    }

    /* Count mode: calculate total words */
    if (count_mode) {
        total_words = num_words(infile);
        printf("The total number of words is: %i\n", total_words);
    }

    if (infile != stdin) {
        fclose(infile);
    }

    return 0;
}
