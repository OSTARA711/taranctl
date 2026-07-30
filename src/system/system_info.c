/* src/system/system_info.c */

#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

#include "system_info.h"

static void show_file_value(const char *label, const char *path)
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        printf("%s: unavailable\n", label);
        return;
    }

    char buffer[256];

    if (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s: %s", label, buffer);
    }

    fclose(file);
}

void show_system_info(void)
{
    puts("\n");
    puts("TARAN OS System Information");
    puts("--------------------------");

    show_file_value("Hostname", "/proc/sys/kernel/hostname");
    show_file_value("Kernel", "/proc/sys/kernel/osrelease");

    struct utsname info;

    if (uname(&info) == 0)
    {
        printf("Architecture: %s\n", info.machine);
    }
    else
    {
        puts("Architecture: unavailable");
    }

    show_file_value("Alpine release", "/etc/alpine-release");
    puts("\n");

}
