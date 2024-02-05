//
// Created by tong on 2/3/24.
//

#include "ca.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    char *pvname = "tong:ai1";
    double value;

    ca_context_create(1);
    ca_monitor(pvname, &value);
    while (1) {
        printf("value -> %g\n", value);
        sleep(1);
    }
    ca_pend_event(0);
    ca_context_destroy();
}

