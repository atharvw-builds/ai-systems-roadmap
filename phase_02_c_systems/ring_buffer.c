#include <stdio.h>
#include <stdlib.h>


// 1. Blue print
struct RingBuffer {
    int* buffer;
    int head;
    int tail;
    int max_capacity;
    int current_count;
};

// 2. Allocator 
struct RingBuffer* init_buffer(int capacity) {
    // Allocate the struct wrapper
    struct RingBuffer* rb = (struct RingBuffer*)malloc(sizeof(struct RingBuffer));
    // Allocate the contigous inner array
    rb->buffer = (int*)malloc(capacity * sizeof(int));
    // Initialze state
    rb->head = 0;
    rb->tail = 0;
    rb->max_capacity = capacity;
    rb->current_count = 0;

    return rb;

}

//3. cleanup
void free_buffer(struct RingBuffer* rb) {
    if (rb != NULL) {
        free(rb->buffer);
        free(rb);

    }
}

// 4.execution 
int main() {
    int size = 5;
    struct RingBuffer* queue = init_buffer(size);
    printf("Bare-metal allocation sucessfull!\n");
    printf("Ring Buffer capacity: %d\n", queue->max_capacity);
    printf("Struct sits at memory address: %p\n", (void*)queue);
    printf("Array sits at memroy address: %p\n", (void*) queue-> buffer);
    free_buffer(queue);
    return 0;
}
