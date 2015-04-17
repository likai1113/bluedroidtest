#include "bluedroidtest.h"

void adapter_state_changed(bt_state_t state);

void bdt_discovery_state_changed_callback(bt_discovery_state_t state);

void bdt_device_found_callback(int num_properties, bt_property_t *properties);

void bdt_adapter_properties_callback(bt_status_t status, int num_properties,
                                        bt_property_t *properties);