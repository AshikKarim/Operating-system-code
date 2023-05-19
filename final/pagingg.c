#include <stdio.h>
#include <math.h>

#define PAGE_SIZE 4

// Page table entry structure
typedef struct {
    int valid;      // Flag indicating if the page is valid
    int frame;      // Frame number where the page is stored
} PageTableEntry;

int main() {
    int logicalMemorySize, physicalMemorySize;
    int logicalAddress;
    int continueFlag = 0;

    printf("Enter the size of the logical memory: ");
    scanf("%d", &logicalMemorySize);

    printf("Enter the size of the physical memory: ");
    scanf("%d", &physicalMemorySize);

    int numPages = ceil((double)logicalMemorySize / PAGE_SIZE);
    int numFrames = ceil((double)physicalMemorySize / PAGE_SIZE);

    PageTableEntry pageTable[numPages];

    printf("\nEnter the page table:\n");
    printf("(Enter frame number as -1 if that page is not present in any frame)\n");

    for (int i = 0; i < numPages; i++) {
        printf("\nPage %d Frame: ", i);
        scanf("%d", &pageTable[i].frame);
        pageTable[i].valid = (pageTable[i].frame != -1);
    }

    do {
        printf("\nEnter the logical address: ");
        scanf("%d", &logicalAddress);

        int pageNumber = logicalAddress / PAGE_SIZE;
        int offset = logicalAddress % PAGE_SIZE;

        if (pageNumber < numPages && pageTable[pageNumber].valid) {
            int frameNumber = pageTable[pageNumber].frame;
            int physicalAddress = (frameNumber * PAGE_SIZE) + offset;
            printf("Physical address: %d\n", physicalAddress);
        } else {
            printf("Invalid logical address or page not present in any frame.\n");
        }

        printf("Do you want to continue (1/0)? ");
        scanf("%d", &continueFlag);
    } while (continueFlag == 1);

    return 0;
}
