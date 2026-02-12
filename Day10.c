// Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    // Input string
    scanf("%s", s);

    int start = 0;
    int end = strlen(s) - 1;
    int isPalindrome = 1;   // assume true

    while(start < end) {
        if(s[start] != s[end]) {
            isPalindrome = 0;   // not palindrome
            break;
        }
        start++;
        end--;
    }

    if(isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
