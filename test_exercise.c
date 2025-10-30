#include "include/exercise3.h"
#include <assert.h>

int main(){

    queue * q;
    initialize(q);
    // krav 1 til test fra afleveringen
    assert(q->front == NULL && q->rear == NULL && q->count == 0);
    assert(empty(q)); // test empty func

    // krav 2 til test fra afleveringen
    enqueue(q,1);
    int a = dequeue(q);
    assert(empty(q) && a == 1); // is the queue still empty and 1 = a

    // krav 3 til test fra afleveringen
    enqueue(q, 1);
    enqueue(q, 2);
    int x = dequeue(q);
    int y = dequeue(q);
    assert(empty(q) && 1 == x && 2 == y); // is the queue still empty?

    print_queue(q); // check that it still includes 1 and then 2 


    


}