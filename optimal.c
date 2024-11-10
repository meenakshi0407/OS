#include <stdio.h>

int findOptimal(int pages[], int temp[], int n, int index) {
    int farthest = index, pos = -1, i, j;
    for (i = 0; i < n; ++i) {
        int found = 0;
        for (j = index; j < n; ++j) {
            if (pages[j] == temp[i]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if (!found)
            return i;  // If a page is not found in the future references
    }
    return (pos == -1) ? 0 : pos;  // If all pages are found in future references
}

int main() {
    int n, frames, pages[30], temp[10], pageFaults = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (int i = 0; i < frames; ++i) {
        temp[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        int pageHit = 0;
        
        for (int j = 0; j < frames; ++j) {
            if (temp[j] == pages[i]) {
                pageHit = 1;
                break;
            }
        }
        
        if (!pageHit) {
            if (i < frames) {
                temp[i] = pages[i];
            } else {
                int pos = findOptimal(pages, temp, frames, i);
                temp[pos] = pages[i];
            }
            pageFaults++;
        }
        
        printf("\n");
        for (int j = 0; j < frames; ++j) {
            printf("%d\t", temp[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d\n", pageFaults);
    
    return 0;
}
