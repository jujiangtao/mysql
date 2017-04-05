#include "mysql/psi/psi_idle.h"
#include "my_global.h"
#include "psi_base.h"
typedef unsigned int PSI_mutex_key;
typedef unsigned int PSI_rwlock_key;
typedef unsigned int PSI_cond_key;
typedef unsigned int PSI_thread_key;
typedef unsigned int PSI_file_key;
typedef unsigned int PSI_stage_key;
typedef unsigned int PSI_statement_key;
typedef unsigned int PSI_socket_key;
struct PSI_placeholder
{
  int m_placeholder;
};
C_MODE_START
struct PSI_idle_bootstrap
{
  void* (*get_interface)(int version);
};
typedef struct PSI_idle_bootstrap PSI_idle_bootstrap;
typedef struct PSI_placeholder PSI_idle_service_t;
typedef struct PSI_placeholder PSI_idle_locker_state;
extern MYSQL_PLUGIN_IMPORT PSI_idle_service_t *psi_idle_service;
C_MODE_END
