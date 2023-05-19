#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct
{
    int id;
    int size;
} Process;

void print_memory(int *memory, int size);
void initialize_memory(int *memory, int size);
int first_fit(int *memory, int size, Process process);
int best_fit(int *memory, int size, Process process);
int worst_fit(int *memory, int size, Process process);

int main()
{
    int memory[MAX_MEMORY];
    int choice, size, process_id, process_size, memory_left;
    Process process;

    initialize_memory(memory, MAX_MEMORY);

    do
    {
        printf("Memory Allocation Techniques:\n");
        printf("1. First-fit\n");
        printf("2. Best-fit\n");
        printf("3. Worst-fit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nFirst-fit Memory Allocation Technique:\n");
            printf("Enter the process id: ");
            scanf("%d", &process_id);
            printf("Enter the process size: ");
            scanf("%d", &process_size);
            process.id = process_id;
            process.size = process_size;
            size = first_fit(memory, MAX_MEMORY, process);
            if (size == -1)
            {
                printf("Memory not available for allocation\n");
            }
            else
            {
                printf("Memory allocated successfully for process %d, memory left = %d\n", process.id, size);
                print_memory(memory, MAX_MEMORY);
            }
            break;
        case 2:
            printf("\nBest-fit Memory Allocation Technique:\n");
            printf("Enter the process id: ");
            scanf("%d", &process_id);
            printf("Enter the process size: ");
            scanf("%d", &process_size);
            process.id = process_id;
            process.size = process_size;
            size = best_fit(memory, MAX_MEMORY, process);
            if (size == -1)
            {
                printf("Memory not available for allocation\n");
            }
            else
            {
                printf("Memory allocated successfully for process %d, memory left = %d\n", process.id, size);
                print_memory(memory, MAX_MEMORY);
            }
            break;
        case 3:
            printf("\nWorst-fit Memory Allocation Technique:\n");
            printf("Enter the process id: ");
            scanf("%d", &process_id);
            printf("Enter the process size: ");
            scanf("%d", &process_size);
            process.id = process_id;
            process.size = process_size;
            size = worst_fit(memory, MAX_MEMORY, process);
            if (size == -1)
            {
                printf("Memory not available for allocation\n");
            }
            else
            {
                printf("Memory allocated successfully for process %d, memory left = %d\n", process.id, size);
                print_memory(memory, MAX_MEMORY);
            }
            break;
        case 4:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice, please try again\n");
        }

    } while (choice != 4);

    return 0;
}

void print_memory(int *memory, int size)
{
    int i;
    printf("\nMemory Map:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", memory[i]);
        if ((i + 1) % 32 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

void initialize_memory(int *memory, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        memory[i] = -1;
    }
}

int first_fit(int *memory, int size, Process process)
{
    int i, j, start = -1, end = -1;
    for (i = 0; i < size; i++)
    {
        if (memory[i] == -1)
        {
            start = i;
            for (j = i; j < size; j++)
            {
                if (memory[j] == -1)
                {
                    end = j;
                }
                else
                {
                    break;
                }
            }
            if (end - start + 1 >= process.size)
            {
                for (j = start; j < start + process.size; j++)
                {
                    memory[j] = process.id;
                }
                return end - start + 1 - process.size;
            }
        }
    }
    return -1;
}

int best_fit(int *memory, int size, Process process)
{
    int i, j, start = -1, end = -1, min_size = MAX_MEMORY, min_start = -1, min_end = -1;
    for (i = 0; i < size; i++)
    {
        if (memory[i] == -1)
        {
            start = i;
            for (j = i; j < size; j++)
            {
                if (memory[j] == -1)
                {
                    end = j;
                }
                else
                {
                    break;
                }
            }
            if (end - start + 1 >= process.size && end - start + 1 - process.size < min_size)
            {
                min_size = end - start + 1 - process.size;
                min_start = start;
                min_end = end;
            }
        }
    }
    if (min_start != -1)
    {
        for (i = min_start; i < min_start + process.size; i++)
        {
            memory[i] = process.id;
        }
        return min_end - min_start + 1 - process.size;
    }
    return -1;
}

int worst_fit(int *memory, int size, Process process)
{
    int i, j, start = -1, end = -1, max_size = 0, max_start = -1, max_end = -1;
    for (i = 0; i < size; i++)
    {
        if (memory[i] == -1)
        {
            start = i;
            for (j = i; j < size; j++)
            {
                if (memory[j] == -1)
                {
                    end = j;
                }
                else
                {
                    break;
                }
            }
            if (end - start + 1 >= process.size && end - start + 1 - process.size > max_size)
            {
                max_size = end - start + 1 - process.size;
                max_start = start;
                max_end = end;
            }
        }
    }
    if (max_start != -1)
    {
        for (i = max_start; i < max_start + process.size; i++)
        {
            memory[i] = process.id;
        }
        return max_end - max_start + 1 - process.size;
    }
    return -1;
}



