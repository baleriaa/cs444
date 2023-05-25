#include "mkfs.h"
#include "block.h"
#include "image.h"

void mkfs(void) {
  unsigned char block[BLOCK_SIZE * 1024] = {0};

  for (int i = 0; i < 1024; i++) {
    write(image_fd, block, BLOCK_SIZE);
  }

  for (int i = 0; i < 7; i++) {
    alloc();
  }
}