#include "ca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *connState[] = {"Never", "Previously", "Connected", "Closed"};


PVResult *eventDataCast(struct event_handler_args *args)
{
    chid chan = args->chid;
    long dbrType = args->type;
    long nelem = args->count;
    size_t elem_size;

    PVResult *pEventData = malloc(sizeof(PVResult));
    pEventData->data_type = (unsigned short) dbrType;
    pEventData->nelem = (unsigned int) nelem;

    void *rdata;
    switch (dbrType) {
        case DBR_STRING: {
            elem_size = sizeof(dbr_string_t);
            dbr_string_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
        case DBR_INT: {
            elem_size = sizeof(dbr_int_t);
            dbr_int_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
        case DBR_FLOAT: {
            elem_size = sizeof(dbr_float_t);
            dbr_float_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
        case DBR_ENUM: {
            elem_size = sizeof(dbr_enum_t);
            dbr_enum_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
        case DBR_CHAR: {
            elem_size = sizeof(dbr_char_t);
            dbr_char_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
        case DBR_LONG: {
            elem_size = sizeof(dbr_long_t);
            dbr_long_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
        case DBR_DOUBLE: {
            elem_size = sizeof(dbr_double_t);
            dbr_double_t *data = malloc(nelem * elem_size);
            rdata = data;
            break;
        }
    }
    memcpy(rdata, args->dbr, nelem * elem_size);
    pEventData->pdata = (void *) rdata;
    return pEventData;
}

// event callback for monitor function only
static void eventCallback_(struct event_handler_args args) {
    double *pvalue = args.usr;
    PVResult *pRes = eventDataCast(&args);
    // printf("Event %s -> %g\n", (char *) ca_name(args.chid), *(dbr_double_t *)pRes->pdata);
    *pvalue = *(dbr_double_t *) pRes->pdata;
    free(pRes);
}

static void connectionCallback_(struct connection_handler_args args) {
    chid chanid = args.chid;
    evid evtid;
    double *pvalue = (double *)ca_puser(chanid);
    char *pvname = (char *)ca_name(chanid);
    int dbfType = ca_field_type(chanid);
    int nelem = ca_element_count(chanid);
    long op = args.op;
    int res;
    if (op == CA_OP_CONN_UP) {
        res = ca_create_subscription(dbfType, nelem, chanid, DBE_VALUE | DBE_ALARM, eventCallback_, pvalue, &evtid);
    } else {
        printf("%s is disconnected [%s]\n", pvname, connState[ca_state(chanid)]);
    }
    free(pvname);
}

// set up monitoring a PV
void ca_monitor(char *pvname, double *pvalue) {
    chid chanid;
    int res;
    if (ca_current_context() == NULL) {
        ca_context_create(1);
    }
    res = ca_create_channel(pvname, connectionCallback_, pvalue, 0, &chanid);
    if (res != ECA_NORMAL) {
        printf("[%s] CA create channel failed: %s\n", pvname, ca_message(res));
    }
}

void clean_monitor() {
    ca_context_destroy();
}