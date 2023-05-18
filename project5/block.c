#include <unistd.h>
#include <fcntl.h>
#include "image.h"

#define BLOCK_SIZE 4096

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
