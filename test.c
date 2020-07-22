#include <sys/sysinfo.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    struct sysinfo sys_info;

    int days, hours, mins, x = 1;

    if(sysinfo(&sys_info) != 0)
        perror("sysinfo");

    days = sys_info.uptime / 86400;
    hours = (sys_info.uptime / 3600) - (days * 24);
    mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);

    printf(" Uptime: %d days, %d hours, %d minutes, %ld seconds  \n", days, hours, mins, sys_info.uptime % 60);
}
