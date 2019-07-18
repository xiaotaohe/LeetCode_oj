class Foo {
public:
    pthread_mutex_t A;
    pthread_mutex_t B;
    pthread_mutex_t C;

    Foo() {
        pthread_mutex_init(&A,NULL);
        pthread_mutex_init(&B,NULL);
        pthread_mutex_init(&C,NULL);
        
        pthread_mutex_lock(&B);
        pthread_mutex_lock(&C);
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        pthread_mutex_lock(&A);
        printFirst();
        pthread_mutex_unlock(&B);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        pthread_mutex_lock(&B);
        printSecond();
        pthread_mutex_unlock(&C);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        pthread_mutex_lock(&C);
        printThird();
        pthread_mutex_unlock(&A);
    }
};