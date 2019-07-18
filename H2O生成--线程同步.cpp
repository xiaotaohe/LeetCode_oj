class H2O {
public:
    pthread_mutex_t H_lock;
    pthread_mutex_t O_lock;
    int count;
    H2O() {
        pthread_mutex_init(&H_lock,NULL);
        pthread_mutex_init(&O_lock,NULL);
        count = 0;
        pthread_mutex_lock(&O_lock);
        

    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        pthread_mutex_lock(&H_lock);
        releaseHydrogen();
        pthread_mutex_unlock(++count == 2 ? &O_lock : &H_lock);
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        pthread_mutex_lock(&O_lock);
        releaseOxygen();
        count = 0;
        pthread_mutex_unlock(&H_lock);
    }
};