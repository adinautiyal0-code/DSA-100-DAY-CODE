// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][50];
    int count[MAX] = {0};
    int unique = 0;

    // Process votes
    for (int i = 0; i < n; i++) {
        char vote[50];
        scanf("%s", vote);

        int found = 0;

        // Check if already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], vote) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        // New candidate
        if (!found) {
            strcpy(names[unique], vote);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[50];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}