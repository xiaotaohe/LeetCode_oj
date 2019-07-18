class FooBar {
private:
    int n;
    pthread_mutex_t b_lock;
    pthread_mutex_t f_lock;
public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_init(&b_lock,NULL);
        pthread_mutex_init(&f_lock,NULL);
        pthread_mutex_lock(&b_lock);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	pthread_mutex_lock(&f_lock);
            printFoo();
            pthread_mutex_unlock(&b_lock);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	pthread_mutex_lock(&b_lock);
            printBar();
            pthread_mutex_unlock(&f_lock);
        }
    }
};