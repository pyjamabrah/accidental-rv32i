// Building RISC-V CPU
// Date: 07/01/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "riscv.h"
#include "memory.h"
#include "elf.h"
#include "disasm.h"

#define MAX_INSTRUCTIONS 1000000

int main()
{
    // Initialize the CPU
    riscv_cpu_t cpu;
    riscv_init(&cpu);

    // Load the program into memory
    riscv_load_program(&cpu, "test.bin");

    // Run the CPU
    for (int i = 0; i < MAX_INSTRUCTIONS; i++)
    {
        riscv_step(&cpu);
        if (cpu.pc == 0)
        {
            break;
        }
    }

    // Print the final state of the CPU
    riscv_print_state(&cpu);

    return 0;
}
