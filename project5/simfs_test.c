#include "ctest.h"
#include "image.h"
#include "block.h"
#include <stdio.h>
#include <string.h>
#include "free.c"
#include "block.c"
#include "inode.c"
#include "mkfs.c"

#ifdef CTEST_ENABLE

void test_image_open_and_close(void) {
  CTEST_ASSERT(image_open("test", 0) != 1, "testing image_open's return value with truncate = 0");
  CTEST_ASSERT(image_close() == 0, "testing image_close's return value");
  CTEST_ASSERT(image_open("test", 1) != 1, "testing image_open's return value with truncate = 1"); 
  image_close();
}

void test_read_and_write_block(void) {
  image_open("test", 1);
  unsigned char test_block[BLOCK_SIZE] = "test";
  bwrite(0, test_block);
  unsigned char read_block[BLOCK_SIZE];
  bread(0, read_block);
  CTEST_ASSERT(memcmp(test_block, read_block, BLOCK_SIZE) == 0, "testing bread and bwrite");
  image_close();
}
 void test_set_and_find_free(void) {
  unsigned char block[BLOCK_SIZE] = {0};
  CTEST_ASSERT(find_free(block) == 0, "testing find_free when empty");
  set_free(block, 0, 1);
  CTEST_ASSERT(find_free(block) == 1, "testing find_free when first bit is set");
  set_free(block, 0, 0);
  CTEST_ASSERT(find_free(block) == 0, "testing find_free when first bit is cleared");
  image_close();
 }

void test_alloc_and_ialloc(void) {
  image_open("test", 1);
  int block = alloc();
  int inode = ialloc();
  CTEST_ASSERT(block != -1 && inode != -1, "testing alloc and ialloc allocation");
  int block2 = alloc();
  int inode2 = ialloc();
  CTEST_ASSERT(block2 != -1 && inode2 != -1, "testing second alloc and ialloc allocation");
  CTEST_ASSERT(block != block2, "testing block difference");
  CTEST_ASSERT(inode != inode2, "testing inode difference");
  image_close();
 }

 void test_mkfs(void) {
  image_open("test", 1);
  mkfs();
  for (int i = 0; i < 7; i++) {
    CTEST_ASSERT(alloc() != -1, "testing mkfs alloc");
  }
  image_close();
 }


int main(void) {
  CTEST_VERBOSE(1);
  CTEST_COLOR(1);

  test_image_open_and_close();
  test_read_and_write_block();
  test_set_and_find_free();
  test_alloc_and_ialloc();
  test_mkfs();

  CTEST_RESULTS();
  CTEST_EXIT();
}

#endif