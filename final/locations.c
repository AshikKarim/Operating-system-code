#include <stdio.h>

#define MEM_SIZE 1000

int mem[MEM_SIZE];
int num_first_fit = 0, num_best_fit = 0, num_worst_fit = 0;

void print_mem() {
    int i;
    for (i = 0; i < MEM_SIZE; i++) {
        printf("%d ", mem[i]);
    }
    printf("\n");
}

int first_fit(int size) {
    int i, j, start = -1, count = 0;
    for (i = 0; i < MEM_SIZE; i++) {
        if (mem[i] == 0) {
            if (start == -1) {
                start = i;
            }
            count++;
            if (count == size) {
                for (j = start; j < start + size; j++) {
                    mem[j] = 1;
                }
                num_first_fit++;
                return start;
            }
        } else {
            start = -1;
            count = 0;
        }
    }
    return -1;
}

int best_fit(int size) {
    int i, j, start = -1, count = 0, best_start = -1, best_count = MEM_SIZE;
    for (i = 0; i < MEM_SIZE; i++) {
        if (mem[i] == 0) {
            if (start == -1) {
                start = i;
            }
            count++;
            if (count == size) {
                if (count < best_count) {
                    best_start = start;
                    best_count = count;
                }
                start = -1;
                count = 0;
            }
        } else {
            start = -1;
            count = 0;
        }
    }
    if (best_start != -1) {
        for (j = best_start; j < best_start + size; j++) {
            mem[j] = 1;
        }
        num_best_fit++;
        return best_start;
    }
    return -1;
}

int worst_fit(int size) {
    int i, j, start = -1, count = 0, worst_start = -1, worst_count = -1;
    for (i = 0; i < MEM_SIZE; i++) {
        if (mem[i] == 0) {
            if (start == -1) {
                start = i;
            }
            count++;
            if (count == size) {
                if (count > worst_count) {
                    worst_start = start;
                    worst_count = count;
                }
                start = -1;
                count = 0;
            }
        } else {
            start = -1;
            count = 0;
        }
    }
    if (worst_start != -1) {
        for (j = worst_start; j < worst_start + size; j++) {
            mem[j] = 1;
        }
        num_worst_fit++;
        return worst_start;
    }
    return -1;
}

int main() {
    int i, size, choice, start;
    for (i = 0; i < MEM_SIZE; i++) {
        mem[i] = 0;
    }
    while (1) {
        printf("Enter the size of the process: ");
        scanf("%d", &size);
        printf("Enter your choice (1 for First Fit, 2 for Best Fit, 3 for Worst Fit, 0 to exit): ");
        scanf("%d",&choice);
    if (choice == 0) {
        break;
    }
    switch (choice) {
        case 1:
            start = first_fit(size);
            if (start != -1) {
                printf("Allocated %d bytes starting at index %d (First Fit)\n", size, start);
                print_mem();
            } else {
                printf("Memory not available for %d bytes (First Fit)\n", size);
            }
            break;
        case 2:
            start = best_fit(size);
            if (start != -1) {
                printf("Allocated %d bytes starting at index %d (Best Fit)\n", size, start);
                print_mem();
            } else {
                printf("Memory not available for %d bytes (Best Fit)\n", size);
            }
            break;
        case 3:
            start = worst_fit(size);
            if (start != -1) {
                printf("Allocated %d bytes starting at index %d (Worst Fit)\n", size, start);
                print_mem();
            } else {
                printf("Memory not available for %d bytes (Worst Fit)\n", size);
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}
printf("Number of allocations using First Fit: %d\n", num_first_fit);
printf("Number of allocations using Best Fit: %d\n", num_best_fit);
printf("Number of allocations using Worst Fit: %d\n", num_worst_fit);
return 0;
}
