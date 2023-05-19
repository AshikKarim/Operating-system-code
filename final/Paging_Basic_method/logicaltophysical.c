#include <stdio.h>

#define PAGE_SIZE 4

int main() {
    int logicalMemorySize, physicalMemorySize;
    int logicalAddress;
    int continueFlag = 0;

    printf("Enter the size of the logical memory: ");
    scanf("%d", &logicalMemorySize);

    printf("Enter the size of the physical memory: ");
    scanf("%d", &physicalMemorySize);

    int numPages = (logicalMemorySize + PAGE_SIZE - 1) / PAGE_SIZE;
    int numFrames = (physicalMemorySize + PAGE_SIZE - 1) / PAGE_SIZE;

    int pageTable[numPages];

    printf("\nEnter the page table:\n");
    printf("Page No\tFrame No\n-------\t-------\n");

    for (int i = 0; i < numPages; i++) {
        printf("%d\t\t", i);
        scanf("%d", &pageTable[i]);
    }

    do {
        printf("\nEnter the logical address: ");
        scanf("%d", &logicalAddress);

        int pageNumber = logicalAddress / PAGE_SIZE;
        int offset = logicalAddress % PAGE_SIZE;

        if (pageNumber < numPages && pageTable[pageNumber] != -1) {
            int frameNumber = pageTable[pageNumber];
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
