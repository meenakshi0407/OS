#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, size, seek = 0, diff;
    int queue[20], temp, max, min, index;

    printf("Enter the size of the disk: ");
    scanf("%d", &size);
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Sort the request array
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find the index of the first request greater than the head
    for (i = 0; i < n; i++) {
        if (queue[i] > head) {
            index = i;
            break;
        }
    }

    // Service the requests to the right of the head
    for (i = index; i < n; i++) {
        diff = abs(queue[i] - head);
        seek += diff;
        head = queue[i];
    }

    // Move the head to the end of the disk
    seek += abs(size - queue[i - 1] - 1);
    head = size - 1;

    // Service the requests to the left of the head
    for (i = index - 1; i >= 0; i--) {
        diff = abs(queue[i] - head);
        seek += diff;
        head = queue[i];
    }

    printf("Total seek time: %d\n", seek);
    return 0;
}
