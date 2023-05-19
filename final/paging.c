#include <stdio.h>

#define MAX_PAGES 50

int main() {
    int page[MAX_PAGES], i, n, f, ps, off, pno;
    int choice = 0;

    printf("Enter the number of pages in memory: ");
    scanf("%d", &n);
    printf("Enter page size: ");
    scanf("%d", &ps);
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < n; i++)
        page[i] = -1;

    printf("\nEnter the page table\n");
    printf("(Enter frame number as -1 if that page is not present in any frame)\n\n");
    printf("Page No\tFrame No\n-------\t-------\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t", i);
        scanf("%d", &page[i]);
    }

    do {
        printf("\nEnter the logical address (i.e., page number and offset): ");
        scanf("%d%d", &pno, &off);

        if (page[pno] == -1)
            printf("The required page is not available in any frame.\n");
        else
            printf("Physical address (i.e., frame number and offset): %d, %d\n", page[pno], off);

        printf("Do you want to continue (1/0)?: ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}
