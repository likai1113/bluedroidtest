#include "bdt_callback.h"

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

void adapter_state_changed(bt_state_t state)
{
    bdt_log("ADAPTER STATE UPDATED : %s", (state == BT_STATE_OFF)?"OFF":"ON");
    if (state == BT_STATE_ON) {
        bt_enabled = 1;
    } else {
        bt_enabled = 0;
    }
}

void bdt_discovery_state_changed_callback(bt_discovery_state_t state) {
    //bdt_log("discovery_state_changed_callback, state = %d", state);
    if(state == BT_DISCOVERY_STOPPED) {
        bdt_log("bluetooth discovery stopped!");
        bt_discovery_running = 0;
        bdt_log("bluetooth discovery stopped,we restart discovery");
        bdt_startdiscovery();
    } else if(state == BT_DISCOVERY_STARTED) {
        bdt_log("bluetooth discovery started");
        bt_discovery_running = 1;
    } else {
        bdt_log("unknown state");
    }
}

void bdt_device_found_callback(int num_properties, bt_property_t *properties) {
    bdt_log("======device_found_callback======");
    int i;
    if(num_properties == 0) {
        bdt_log("device discovery find nothing");
        return;
    }
    for (i = 0; i < num_properties; i++) {
        //bdt_log("properties[%d].type = 0x%x", i, properties[i].type);

        switch(properties[i].type) {
            case BT_PROPERTY_BDNAME:
                bdt_log("bdname = %s", (const char *)properties[i].val);
                break;
            case BT_PROPERTY_BDADDR: {
                void *value = properties[i].val;
                uint8_t *p = ((bt_bdaddr_t *)value)->address;
                bdt_log("bdaddr = %x:%x:%x:%x:%x:%x", p[0], p[1], p[2], p[3], p[4], p[5]);
                }
                break;
            case BT_PROPERTY_UUIDS:
                bdt_log("uuids");
                break;
            case BT_PROPERTY_CLASS_OF_DEVICE:
                bdt_log("class of device");
                break;
            case BT_PROPERTY_TYPE_OF_DEVICE:
                bdt_log("type of device");
                break;
            case BT_PROPERTY_SERVICE_RECORD:
                bdt_log("service record");
                break;
            case BT_PROPERTY_ADAPTER_SCAN_MODE:
                bdt_log("adapter scan mode");
                break;
            case BT_PROPERTY_ADAPTER_BONDED_DEVICES:
                bdt_log("adapter bonded devices");
                break;
            case BT_PROPERTY_ADAPTER_DISCOVERY_TIMEOUT:
                bdt_log("adapter discovery timeout");
                break;
            case BT_PROPERTY_ADAPTER_HEADLESS_MODE_WAKEUP_DEVICES:
                bdt_log("adapter headless mode wakeup devices");
                break;
            case BT_PROPERTY_REMOTE_FRIENDLY_NAME:
                bdt_log("remote friendly name");
                break;
            case BT_PROPERTY_REMOTE_RSSI:
                bdt_log("remote rssi");
                break;
            case BT_PROPERTY_REMOTE_VERSION_INFO:
                bdt_log("remote version info");
                break;
            case BT_PROPERTY_DEVICE_MODE:
                bdt_log("device mode");
                break;
            case BT_PROPERTY_SCO_ROUTE_MODE:
                bdt_log("sco route mode");
                break;
            default :
                break;
            
        }
    }
}

void bdt_adapter_properties_callback(bt_status_t status, int num_properties,
                                        bt_property_t *properties) {
    bdt_log("======bdt_adapter_properties_callback======");
    int i;
    status == BT_STATUS_SUCCESS ? bdt_log("status is success"):bdt_log("status is ERROR");
    if(status != BT_STATUS_SUCCESS){
        return;
    } else {
        bdt_log("set adapter property success, we do that again!");
        bdt_set_adapter_property();
    }
    for (i = 0; i < num_properties; i++) {
        switch(properties[i].type) {
            case BT_PROPERTY_BDNAME:
                bdt_log("bdname = %s", (const char *)properties[i].val);
                break;
            case BT_PROPERTY_BDADDR: {
                void *value = properties[i].val;
                uint8_t *p = ((bt_bdaddr_t *)value)->address;
                bdt_log("bdaddr = %x:%x:%x:%x:%x:%x", p[0], p[1], p[2], p[3], p[4], p[5]);
                }
                break;
            case BT_PROPERTY_UUIDS:
                bdt_log("uuids");
                break;
            case BT_PROPERTY_CLASS_OF_DEVICE:
                bdt_log("class of device");
                break;
            case BT_PROPERTY_TYPE_OF_DEVICE:
                bdt_log("type of device");
                break;
            case BT_PROPERTY_SERVICE_RECORD:
                bdt_log("service record");
                break;
            case BT_PROPERTY_ADAPTER_SCAN_MODE:
                bdt_log("adapter scan mode");
                break;
            case BT_PROPERTY_ADAPTER_BONDED_DEVICES:
                bdt_log("adapter bonded devices");
                break;
            case BT_PROPERTY_ADAPTER_DISCOVERY_TIMEOUT:
                bdt_log("adapter discovery timeout");
                break;
            case BT_PROPERTY_ADAPTER_HEADLESS_MODE_WAKEUP_DEVICES:
                bdt_log("adapter headless mode wakeup devices");
                break;
            case BT_PROPERTY_REMOTE_FRIENDLY_NAME:
                bdt_log("remote friendly name");
                break;
            case BT_PROPERTY_REMOTE_RSSI:
                bdt_log("remote rssi");
                break;
            case BT_PROPERTY_REMOTE_VERSION_INFO:
                bdt_log("remote version info");
                break;
            case BT_PROPERTY_DEVICE_MODE:
                bdt_log("device mode");
                break;
            case BT_PROPERTY_SCO_ROUTE_MODE:
                bdt_log("sco route mode");
                break;
            default :
                break;
            
        }
    }    
    
}