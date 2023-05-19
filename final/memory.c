#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MEM_SIZE 1024 // Maximum size of memory

// Memory block structure
typedef struct memory_block
{
    int id;
    int size;
    bool allocated;
} MemoryBlock;

// Function prototypes
void initialize_memory(MemoryBlock memory[], int size);
void print_memory(MemoryBlock memory[], int size);
int first_fit(MemoryBlock memory[], int size, int process_size);
int best_fit(MemoryBlock memory[], int size, int process_size);
int worst_fit(MemoryBlock memory[], int size, int process_size);

int main()
{
    MemoryBlock memory[MAX_MEM_SIZE]; // Memory array
    int size = 5;                     // Number of memory blocks
    int process_size;                 // Size of process to allocate

    // Initialize memory
    initialize_memory(memory, size);

    // Print initial memory status
    printf("Initial memory status:\n");
    print_memory(memory, size);

    // First Fit allocation
    process_size = 12;
    int ff_index = first_fit(memory, size, process_size);
    if (ff_index != -1)
    {
        printf("First Fit: Process allocated at block %d\n", ff_index);
    }
    else
    {
        printf("First Fit: Process could not be allocated\n");
    }
    print_memory(memory, size);

    // Best Fit allocation
    process_size = 12;
    int bf_index = best_fit(memory, size, process_size);
    if (bf_index != -1)
    {
        printf("Best Fit: Process allocated at block %d\n", bf_index);
    }
    else
    {
        printf("Best Fit: Process could not be allocated\n");
    }
    print_memory(memory, size);

    // Worst Fit allocation
    process_size = 12;
    int wf_index = worst_fit(memory, size, process_size);
    if (wf_index != -1)
    {
        printf("Worst Fit: Process allocated at block %d\n", wf_index);
    }
    else
    {
        printf("Worst Fit: Process could not be allocated\n");
    }
    print_memory(memory, size);

    return 0;
}

// Initialize memory with random block sizes
void initialize_memory(MemoryBlock memory[], int size)
{
    for (int i = 0; i < size; i++)
    {
        memory[i].id = i;
        memory[i].size = rand() % 20 + 1; // Random block size between 1 and 20
        memory[i].allocated = false;
    }
}

// Print memory status
void print_memory(MemoryBlock memory[], int size)
{
    printf("Memory status:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Block %d - Size: %d - Allocated: %s\n", memory[i].id, memory[i].size, memory[i].allocated ? "Yes" : "No");
    }
}

// First Fit memory allocation
int first_fit(MemoryBlock memory[], int size, int process_size)
{
    for (int i = 0; i < size; i++)
    {
        if (!memory[i].allocated && memory[i].size >= process_size)
        {
            memory[i].allocated = true;
            return i;
        }
    }
    return -1; // Allocation failed
}

// Best Fit memory allocation
// Best Fit memory allocation
int best_fit(MemoryBlock memory[], int size, int process_size)
{
    int best_fit_index = -1;
    int best_fit_size = MAX_MEM_SIZE + 1; // Set initial best fit size to a high value
    for (int i = 0; i < size; i++)
    {
        if (!memory[i].allocated && memory[i].size >= process_size && memory[i].size < best_fit_size)
        {
            best_fit_index = i;
            best_fit_size = memory[i].size;
        }
    }

    if (best_fit_index != -1)
    {
        memory[best_fit_index].allocated = true;
    }

    return best_fit_index;
}

// Worst Fit memory allocation
int worst_fit(MemoryBlock memory[], int size, int process_size)
{
    int worst_fit_index = -1;
    int worst_fit_size = -1; // Set initial worst fit size to a low value

    for (int i = 0; i < size; i++)
    {
        if (!memory[i].allocated && memory[i].size >= process_size && memory[i].size > worst_fit_size)
        {
            worst_fit_index = i;
            worst_fit_size = memory[i].size;
        }
    }

    if (worst_fit_index != -1)
    {
        memory[worst_fit_index].allocated = true;
    }

    return worst_fit_index;
}

