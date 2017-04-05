#include "mysql/psi/psi_socket.h"
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
struct PSI_socket;
typedef struct PSI_socket PSI_socket;
struct PSI_socket_bootstrap
{
  void* (*get_interface)(int version);
};
typedef struct PSI_socket_bootstrap PSI_socket_bootstrap;
struct PSI_socket_locker;
typedef struct PSI_socket_locker PSI_socket_locker;
enum PSI_socket_state
{
  PSI_SOCKET_STATE_IDLE= 1,
  PSI_SOCKET_STATE_ACTIVE= 2
};
typedef enum PSI_socket_state PSI_socket_state;
enum PSI_socket_operation
{
  PSI_SOCKET_CREATE= 0,
  PSI_SOCKET_CONNECT= 1,
  PSI_SOCKET_BIND= 2,
  PSI_SOCKET_CLOSE= 3,
  PSI_SOCKET_SEND= 4,
  PSI_SOCKET_RECV= 5,
  PSI_SOCKET_SENDTO= 6,
  PSI_SOCKET_RECVFROM= 7,
  PSI_SOCKET_SENDMSG= 8,
  PSI_SOCKET_RECVMSG= 9,
  PSI_SOCKET_SEEK= 10,
  PSI_SOCKET_OPT= 11,
  PSI_SOCKET_STAT= 12,
  PSI_SOCKET_SHUTDOWN= 13,
  PSI_SOCKET_SELECT= 14
};
typedef enum PSI_socket_operation PSI_socket_operation;
struct PSI_socket_info_v1
{
  PSI_socket_key *m_key;
  const char *m_name;
  int m_flags;
};
typedef struct PSI_socket_info_v1 PSI_socket_info_v1;
struct PSI_socket_locker_state_v1
{
  uint m_flags;
  struct PSI_socket *m_socket;
  struct PSI_thread *m_thread;
  size_t m_number_of_bytes;
  ulonglong m_timer_start;
  ulonglong (*m_timer)(void);
  enum PSI_socket_operation m_operation;
  const char* m_src_file;
  int m_src_line;
  void *m_wait;
};
typedef struct PSI_socket_locker_state_v1 PSI_socket_locker_state_v1;
typedef void (*register_socket_v1_t)
  (const char *category, struct PSI_socket_info_v1 *info, int count);
typedef struct PSI_socket* (*init_socket_v1_t)
  (PSI_socket_key key, const my_socket *fd,
  const struct sockaddr *addr, socklen_t addr_len);
typedef void (*destroy_socket_v1_t)(struct PSI_socket *socket);
typedef struct PSI_socket_locker* (*start_socket_wait_v1_t)
  (struct PSI_socket_locker_state_v1 *state,
   struct PSI_socket *socket,
   enum PSI_socket_operation op,
   size_t count,
   const char *src_file, uint src_line);
typedef void (*end_socket_wait_v1_t)
  (struct PSI_socket_locker *locker, size_t count);
typedef void (*set_socket_state_v1_t)(struct PSI_socket *socket,
                                      enum PSI_socket_state state);
typedef void (*set_socket_info_v1_t)(struct PSI_socket *socket,
                                     const my_socket *fd,
                                     const struct sockaddr *addr,
                                     socklen_t addr_len);
typedef void (*set_socket_thread_owner_v1_t)(struct PSI_socket *socket);
struct PSI_socket_service_v1
{
  register_socket_v1_t register_socket;
  init_socket_v1_t init_socket;
  destroy_socket_v1_t destroy_socket;
  start_socket_wait_v1_t start_socket_wait;
  end_socket_wait_v1_t end_socket_wait;
  set_socket_state_v1_t set_socket_state;
  set_socket_info_v1_t set_socket_info;
  set_socket_thread_owner_v1_t set_socket_thread_owner;
};
typedef struct PSI_socket_service_v1 PSI_socket_service_t;
typedef struct PSI_socket_info_v1 PSI_socket_info;
typedef struct PSI_socket_locker_state_v1 PSI_socket_locker_state;
extern MYSQL_PLUGIN_IMPORT PSI_socket_service_t *psi_socket_service;
C_MODE_END
