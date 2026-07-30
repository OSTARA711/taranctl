/* src/main.c */

#include <stdio.h>
#include <string.h>
#include "system_info.h"
#include "doctor.h"

#define TARANCTL_VERSION "0.1.0"

static void print_help(void)
{
    puts("taranctl - TARAN OS Control Utility");
    puts("");
    puts("Usage:");
    puts("  taranctl <command>");
    puts("");
    puts("Commands:");
    puts("  version     Show version information");
    puts("  info        Show system information");
    puts("  doctor      Check TARAN OS components");
    puts("  help        Show this help message");
}

static void print_version(void)
{
    puts("taranctl version " TARANCTL_VERSION);
}

static void print_info(void)
{
    show_system_info();
}

static void print_doctor(void)
{
    run_doctor();
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "version") == 0)
    {
        print_version();
    }
    else if (strcmp(argv[1], "info") == 0)
    {
        print_info();
    }
    else if (strcmp(argv[1], "doctor") == 0)
    {
        print_doctor();
    }
    else if (strcmp(argv[1], "help") == 0)
    {
        print_help();
    }
    else
    {
        printf("Unknown command: %s\n\n", argv[1]);
        print_help();
        return 1;
    }

    return 0;
}
