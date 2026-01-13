#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== Function Prototypes =====
int is_mode_valid(const char *mode);
char *extract_sentence(const char *text, int start, int end);
void find_sentence(const char *text, int mode, char **result, int *result_len);

// ================================
//             MAIN
// ================================
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Not valid!\n");
        return 0;
    }

    char *text = argv[1];
    char *mode_str = argv[2];

    int mode = is_mode_valid(mode_str);
    if (mode == 0) {
        printf("Not valid!\n");
        return 0;
    }

    char *best = NULL;
    int best_len = 0;

    find_sentence(text, mode, &best, &best_len);

    if (!best) {
        printf("Not valid!\n");
        return 0;
    }

    printf("%d\n", best_len);
    printf("%s\n", best);

    free(best);
    return 0;
}

// ================================
//      FUNCTION DEFINITIONS
// ================================

// Validate mode: returns 1 for longest, -1 for shortest, 0 invalid
int is_mode_valid(const char *mode) {
    if (strcmp(mode, "longest") == 0) return 1;
    if (strcmp(mode, "shortest") == 0) return -1;
    return 0;
}

// Allocate and copy text[start..end] WITHOUT memcpy, using calloc
char *extract_sentence(const char *text, int start, int end) {
    int len = end - start + 1;

    char *s = calloc(len + 1, sizeof(char));  // zero-initialised buffer
    if (!s) return NULL;

    for (int i = 0; i < len; i++) {
        s[i] = text[start + i];
    }
    s[len] = '\0';

    return s;
}

// Find shortest/longest sentence according to mode
void find_sentence(const char *text, int mode, char **result, int *result_len) {
    int n = strlen(text);
    int in_quote = 0;
    int start = -1;

    char *best_sentence = NULL;
    int best_length = (mode == 1 ? 0 : 999999);

    for (int i = 0; i < n; i++) {
        char c = text[i];

        // Toggle single-quote region
        if (c == '\'')
            in_quote = !in_quote;

        // Sentence start (any non-space when not already started)
        if (start == -1 && c != ' ')
            start = i;

        // Sentence end (dot or question NOT inside quotes)
        if ((c == '.' || c == '?') && !in_quote && start != -1) {
            int len = i - start + 1;

            int update = 0;
            if (mode == 1 && len > best_length) update = 1;   // longest
            if (mode == -1 && len < best_length) update = 1;  // shortest

            if (update) {
                if (best_sentence) free(best_sentence);
                best_sentence = extract_sentence(text, start, i);
                best_length = len;
            }

            start = -1;   // reset for next sentence
        }
    }

    *result = best_sentence;
    *result_len = best_length;
}
