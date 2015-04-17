#include "bdt_adapterproperty.h"

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

void bdt_set_adapter_property(void) {
    bdt_log("bdt_set_adapter_property");
    bt_property_t prop;
    char *name = "likai";
    if(!sBtInterface){
        bdt_log("sBtInterface is NULL. bluetooth interface is not init!");
        return;
    }
    if(!bt_enabled){
        bdt_log("bluetooth is disabled");
        return;
    }
    if(bt_discovery_running) {
        bdt_log("bluetooth discovery is running, stop it!");
        bdt_canceldiscovery();
    }
    prop.type = BT_PROPERTY_BDNAME;
    prop.len = strlen(name) + 1;
    prop.val = name;
    status = sBtInterface->set_adapter_property(&prop);
    if (status != BT_STATUS_SUCCESS){
        bdt_log("cancle discovery failed.");
    }
    
}