#include "bdt_discovery.h"

/**************************************************************
*Global variable
**************************************************************/
extern unsigned char main_done;
extern bt_status_t status;

/* Main API */
extern bluetooth_device_t* bt_device;

extern const bt_interface_t* sBtInterface;


/* Set to 1 when the Bluedroid stack is enabled */
extern unsigned char bt_enabled;
/* Set to 1 when the Bluedroid stack is discovery */
extern int bt_discovery_running;

/****************************************************************
*Global Function
****************************************************************/

extern void bdt_log(const char *fmt_str, ...);

/*************************************************************
***test start discovery
**************************************************************/
void bdt_startdiscovery(void)
{
    if(!sBtInterface){
        bdt_log("sBtInterface is NULL. bluetooth interface is not init!");
        return;
    }
    if(!bt_enabled){
        bdt_log("bluetooth is disabled");
        return;
    }
    if(bt_discovery_running) {
        bdt_log("bluetooth discovery is running");
        return;
    }
    status = sBtInterface->start_discovery();
    
    if (status != BT_STATUS_SUCCESS){
        bdt_log("start discovery failed.");
    }
}

/*************************************************************
***test discovery
**************************************************************/
void bdt_canceldiscovery(void)
{
    if(!sBtInterface){
        bdt_log("sBtInterface is NULL. bluetooth interface is not init!");
        return;
    }
    if(!bt_enabled){
        bdt_log("bluetooth is disabled");
        return;
    }
    if(!bt_discovery_running) {
        bdt_log("bluetooth discovery is not running");
        return;
    }
    status = sBtInterface->cancel_discovery();
    
    if (status != BT_STATUS_SUCCESS){
        bdt_log("cancle discovery failed.");
    }
}