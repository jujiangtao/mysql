#include "mysql/psi/psi_file.h"
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
struct PSI_file;
typedef struct PSI_file PSI_file;
struct PSI_file_bootstrap
{
  void* (*get_interface)(int version);
};
typedef struct PSI_file_bootstrap PSI_file_bootstrap;
typedef struct PSI_placeholder PSI_file_service_t;
typedef struct PSI_placeholder PSI_file_info;
typedef struct PSI_placeholder PSI_file_locker_state;
extern MYSQL_PLUGIN_IMPORT PSI_file_service_t *psi_file_service;
C_MODE_END
