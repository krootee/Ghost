/* Generated file - do not edit. */

#ifndef SYS_RO_VARS_H_
#define SYS_RO_VARS_H_

#include "fw/src/mgos_config.h"

struct sys_ro_vars {
  const char *mac_address;
  const char *arch;
  const char *fw_version;
  const char *fw_timestamp;
  const char *fw_id;
};

const struct mgos_conf_entry *sys_ro_vars_schema();

#endif /* SYS_RO_VARS_H_ */
