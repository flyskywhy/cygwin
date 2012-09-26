/* The size of the chunks that are used for indirect pieces of messages.
   Too low, and you'll have a lot of malloc overhead. Too high, and you'll
   get wasted mem.
*/
#define GIOP_INDIRECT_CHUNK_SIZE 1024
