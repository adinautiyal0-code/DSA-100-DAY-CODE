// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';

        freq[index]++;

        // If seen before → first repeated
        if (freq[index] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    // No repeated character
    printf("-1");

    return 0;
}