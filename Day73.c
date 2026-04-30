// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    // Count frequency
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating
    for (int i = 0; i < strlen(s); i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    // If none found
    printf("$");

    return 0;
}