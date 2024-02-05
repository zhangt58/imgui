//
// Created by tong on 2/3/24.
//

#ifndef IMGUI_CA_H
#define IMGUI_CA_H

#include "cadef.h"


// monitors a PV
#ifdef __cplusplus
extern "C" {
#endif

void ca_monitor(char *, double *);

// Data struct for storing event data
typedef struct {
    unsigned short data_type;
    unsigned int nelem;
    void *pdata;
} PVResult;

#ifdef __cplusplus
}
#endif

#endif //IMGUI_CA_H
