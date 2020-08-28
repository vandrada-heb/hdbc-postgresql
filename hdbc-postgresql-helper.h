#include <libpq-fe.h>
#include <pthread.h>

typedef struct TAG_finalizeonce {
  void *encapobj;
  int refcount;
  int isfinalized;
  struct TAG_finalizeonce *parent;
  pthread_mutex_t lock;
} finalizeonce;

extern finalizeonce *wrapobjpg(void *obj, finalizeonce *parentobj);

extern void PQfinish_app(finalizeonce *conn);
extern void PQfinish_finalizer(finalizeonce *conn);

extern void PQclear_app(finalizeonce *res);
extern void PQclear_finalizer(finalizeonce *res);
