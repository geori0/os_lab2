#include "os.h"  

int CreateThread(OsThread *thread, void *(*routine)(void *), void *arg) {
    return pthread_create(thread, NULL, routine, arg);
}

int JoinThread(OsThread thread) {
    return pthread_join(thread, NULL);
} 