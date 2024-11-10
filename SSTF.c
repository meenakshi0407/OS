#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, size, seek = 0, diff;
    int queue[20], serviced[20], index;

    printf("Enter the size of the disk: ");
    scanf("%d", &size);
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        serviced[i] = 0; // Mark all requests as not serviced
    }

    // Loop through all requests
    for (i = 0; i < n; i++) {
        int min = 10000;
        // Find the request with the minimum seek time from the current head
        for (j = 0; j < n; j++) {
            if (!serviced[j]) {
                diff = abs(queue[j] - head);
                if (diff < min) {
                    min = diff;
                    index = j;
                }
            }
        }
        // Service the request
        seek += min;
        head = queue[index];
        serviced[index] = 1; // Mark this request as serviced
    }

    printf("Total seek time: %d\n", seek);
    return 0;
}
