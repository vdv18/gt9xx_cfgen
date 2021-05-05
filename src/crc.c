#include <stdint.h>
#include <stddef.h>
#include "crc.h"

/**
 * Calculating checksum
 */
uint8_t checksum(uint8_t *buffer, size_t size)
{
  uint8_t checksum = 0;
  while(size--) {
    checksum += *buffer++;
  }
  checksum = (~checksum) + 1;
  return checksum;
}

