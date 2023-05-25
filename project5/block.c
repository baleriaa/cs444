#include <unistd.h>
#include <fcntl.h>
#include "image.h"
#include "block.h"
#include "free.h"

unsigned char *bread(int block_num, unsigned char *block) {
  int file_descriptor = image_fd;
  int offset = block_num * BLOCK_SIZE;  
  lseek(file_descriptor, offset, SEEK_SET); 
  read(file_descriptor, block, BLOCK_SIZE); // read from file_descriptor into block
  return block;
}

void bwrite(int block_num, unsigned char *block) {
  int file_descriptor = image_fd;
  int offset = block_num * BLOCK_SIZE;
  lseek(file_descriptor, offset, SEEK_SET);
  write(file_descriptor, block, BLOCK_SIZE); // write from block into file_descriptor
}

int alloc(void) {
  unsigned char block[BLOCK_SIZE];
  bread(2, block);
  int free_block = find_free(block);
  if (free_block == -1) {
    return -1;
  }
  set_free(block, free_block, 1);
  bwrite(2, block);
  return free_block;
}
