#include "mysql/psi/psi_mutex.h"
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
struct PSI_mutex;
typedef struct PSI_mutex PSI_mutex;
struct PSI_mutex_bootstrap
{
  void* (*get_interface)(int version);
};
typedef struct PSI_mutex_bootstrap PSI_mutex_bootstrap;
struct PSI_mutex_locker;
typedef struct PSI_mutex_locker PSI_mutex_locker;
enum PSI_mutex_operation
{
  PSI_MUTEX_LOCK= 0,
  PSI_MUTEX_TRYLOCK= 1
};
typedef enum PSI_mutex_operation PSI_mutex_operation;
struct PSI_mutex_info_v1
{
  PSI_mutex_key *m_key;
  const char *m_name;
  int m_flags;
  int m_volatility;
};
typedef struct PSI_mutex_info_v1 PSI_mutex_info_v1;
struct PSI_mutex_locker_state_v1
{
  uint m_flags;
  enum PSI_mutex_operation m_operation;
  struct PSI_mutex *m_mutex;
  struct PSI_thread *m_thread;
  ulonglong m_timer_start;
  ulonglong (*m_timer)(void);
  void *m_wait;
};
typedef struct PSI_mutex_locker_state_v1 PSI_mutex_locker_state_v1;
typedef void (*register_mutex_v1_t)
  (const char *category, struct PSI_mutex_info_v1 *info, int count);
typedef struct PSI_mutex* (*init_mutex_v1_t)
  (PSI_mutex_key key, const void *identity);
typedef void (*destroy_mutex_v1_t)(struct PSI_mutex *mutex);
typedef void (*unlock_mutex_v1_t)
  (struct PSI_mutex *mutex);
typedef struct PSI_mutex_locker* (*start_mutex_wait_v1_t)
  (struct PSI_mutex_locker_state_v1 *state,
   struct PSI_mutex *mutex,
   enum PSI_mutex_operation op,
   const char *src_file, uint src_line);
typedef void (*end_mutex_wait_v1_t)
  (struct PSI_mutex_locker *locker, int rc);
struct PSI_mutex_service_v1
{
  register_mutex_v1_t register_mutex;
  init_mutex_v1_t init_mutex;
  destroy_mutex_v1_t destroy_mutex;
  start_mutex_wait_v1_t start_mutex_wait;
  end_mutex_wait_v1_t end_mutex_wait;
  unlock_mutex_v1_t unlock_mutex;
};
typedef struct PSI_mutex_service_v1 PSI_mutex_service_t;
typedef struct PSI_mutex_info_v1 PSI_mutex_info;
typedef struct PSI_mutex_locker_state_v1 PSI_mutex_locker_state;
extern MYSQL_PLUGIN_IMPORT PSI_mutex_service_t *psi_mutex_service;
C_MODE_END
