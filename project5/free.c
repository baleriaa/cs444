#include <stdlib.h>
#include "block.h"

int find_low_clear_bit(unsigned char x)
{
    for (int i = 0; i < 8; i++)
        if (!(x & (1 << i)))
            return i;
    
    return -1;
}

void set_free(unsigned char *block, int num, int set) {
  int byte_num = num / 8; 
  int bit_num = num % 8;

  if (set) {
    block[byte_num] |= (1 << bit_num); // set the bit
  } else {
    block[byte_num] &= ~(1 << bit_num); // clear the bit
  }

}

int find_free(unsigned char *block) {
  for (int i = 0; i < BLOCK_SIZE; i++) {
    int lowest_clear_bit = find_low_clear_bit(block[i]);
    if (lowest_clear_bit != -1) {
      return i * 8 + lowest_clear_bit;
    }
  }
  return -1;
 }