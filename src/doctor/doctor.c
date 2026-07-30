/* src/doctor/doctor.c */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "doctor.h"

typedef struct
{
    const char *name;
    const char *command;
} doctor_command_check_t;

static const doctor_command_check_t command_checks[] =
{
    { "dbus",      "dbus-daemon" },
    { "eudev",     "udevadm"     },
    { "iwd",       "iwctl"       },
    { "seatd",     "seatd"       },
    { "Wayland",   "wayland-info" }
};

#define COMMAND_CHECK_COUNT \
    (sizeof(command_checks) / sizeof(command_checks[0]))

static int check_command(const char *name)
{
    char command[128];

    int n = snprintf(command,
                     sizeof(command),
                     "command -v %s >/dev/null 2>&1",
                     name);

    if (n < 0 || (size_t)n >= sizeof(command))
    {
        return 0;
    }

    return system(command) == 0;
}

static int check_library(const char *path)
{
    FILE *file;

    file = fopen(path, "r");

    if (file == NULL)
    {
        return 0;
    }

    fclose(file);

    return 1;
}

static void print_check(const char *name, int result)
{
    printf("%-12s %s\n",
           name,
           result ? "OK" : "UNSEEN");
}

void run_doctor(void)
{
    puts("\n");
    puts("TARAN OS Doctor");
    puts("----------------");
    puts("");

    print_check("Kernel", 1);

    size_t i;

    for (i = 0; i < COMMAND_CHECK_COUNT; i++)
    {
        print_check(
            command_checks[i].name,
            check_command(command_checks[i].command));
    }

    print_check(
        "wlroots",
        check_library("/usr/lib/libwlroots-0.20.so"));

    puts("\n");
}
