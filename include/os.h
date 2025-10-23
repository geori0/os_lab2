#pragma  once

#ifdef OS_WINDOWS
    #include <windows.h>
#else
    #include <pthread.h>
#endif

#ifdef OS_WINDOWS
    typedef HANDLE OsThread
#else
    typedef  pthread_t OsThread;
#endif

int CreateThread(OsThread *thread, void *(*routine)(void *), void *arg);
int JoinThread(OsThread thread);
