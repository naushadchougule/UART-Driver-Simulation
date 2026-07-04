#include "ring_buffer.h"

void RingBuffer_Init(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int RingBuffer_IsEmpty(RingBuffer *rb)
{
    return (rb->count == 0);
}

int RingBuffer_IsFull(RingBuffer *rb)
{
    return (rb->count == BUFFER_SIZE);
}

int RingBuffer_Push(RingBuffer *rb, uint8_t data)
{
    if (RingBuffer_IsFull(rb))
    {
        return 0;
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;

    return 1;
}

int RingBuffer_Pop(RingBuffer *rb, uint8_t *data)
{
    if (RingBuffer_IsEmpty(rb))
    {
        return 0;
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;

    return 1;
}
