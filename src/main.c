#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "crc.h"
#include "parseopt.h"
#include "gt9xx_regs.h"

#define CFG_CRC_SIZE 184
#define CFG_DEFAULT  "gt9xx"

static uint8_t gt9xx_default[] = {
  0x5B,0x58,0x02,0x00,0x04,0x0A,0x35,0x00,
  0x01,0x08,0x28,0x0F,0x50,0x50,0x03,0x05,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,
  0x1A,0x1E,0x14,0x87,0x29,0x0A,0x23,0x25,
  0xD3,0x07,0x00,0x00,0x00,0x02,0x03,0x1C,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x19,0x32,0x94,0xD5,0x02,
  0x07,0x00,0x00,0x04,0x54,0x1A,0x00,0x4D,
  0x1E,0x00,0x48,0x23,0x00,0x43,0x28,0x00,
  0x3F,0x2E,0x00,0x3F,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,
  0x04,0x02,0xFF,0xFF,0xFF,0xFF,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x26,
  0x24,0x22,0x21,0x20,0x1F,0x1E,0x1D,0x0C,
  0x0A,0x08,0x06,0x04,0x02,0x00,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xEB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

/**
 * Calculating configuration checksum
 */
static uint8_t gt9xx_config_checksum(uint8_t *buffer, size_t size)
{
  return checksum(buffer, size);
}

int main(int argc, char *argv[])
{
  int ret = 0;
  struct options_s results;
  char *input_file = NULL;
  char *output_file = "config.bin";
  memset(&results, 0, sizeof(results));
  ret = parse_options(argc, argv, &results);
  if (ret || results.help_enabled) {
    parse_help();
  } else {
    if (results.input_file) {
      input_file = results.input_file;
    }
    if (results.output_file) {
      output_file = results.output_file;
    }

    /* change the buffer */
    if (results.touch_value) {
      int value = 0;
      sscanf(results.touch_value, "%d", &value);
      if (value < 0 || value >= 0x10000)
	fprintf(stderr,"Touch value should be in range 0 - 255\n");
      gt9xx_default[GT9XX_REG_SCREEN_TOUCH_LEVEL - GT9XX_REG_CFG_BASE] = 0xFF&(value);
    }
    if (results.leave_value) {
      int value = 0;
      sscanf(results.leave_value, "%d", &value);
      if (value < 0 || value >= 0x10000)
	fprintf(stderr,"Leave value should be in range 0 - 255\n");
      gt9xx_default[GT9XX_REG_SCREEN_LEAVE_LEVEL - GT9XX_REG_CFG_BASE] = 0xFF&(value);
    }
    if (results.rx_value) {
      int value = 0;
      sscanf(results.rx_value, "%d", &value);
      if (value < 0 || value > 7)
	fprintf(stderr,"RX value should be in range 0 - 7\n");
      gt9xx_default[GT9XX_REG_PANNEL_RX_GAIN - GT9XX_REG_CFG_BASE] &= ~0xF8;
      gt9xx_default[GT9XX_REG_PANNEL_RX_GAIN - GT9XX_REG_CFG_BASE] |= 0x07&(value);
    }
    if (results.tx_value) {
      int value = 0;
      sscanf(results.tx_value, "%d", &value);
      if (value < 0 || value > 7)
	fprintf(stderr,"TX value should be in range 0 - 7\n");
      gt9xx_default[GT9XX_REG_PANNEL_TX_GAIN - GT9XX_REG_CFG_BASE] &= ~0xF8;
      gt9xx_default[GT9XX_REG_PANNEL_TX_GAIN - GT9XX_REG_CFG_BASE] |= 0x07&(value);
    }

    /* calculate CRC code */
    gt9xx_default[CFG_CRC_SIZE] = gt9xx_config_checksum(gt9xx_default, CFG_CRC_SIZE-1);
    gt9xx_default[CFG_CRC_SIZE+1] = 0x01;

    /* write results */
    if (results.stdout_enabled) {
      fwrite(gt9xx_default, sizeof(gt9xx_default), 1, stdout);
    } else if (output_file) {
      FILE *f;
      f = fopen(output_file, "w+");
      if (f) {
	fwrite(gt9xx_default, sizeof(gt9xx_default), 1, f);
	fclose(f);
      }
    } else {
      fprintf(stderr,"Something went wrong\n");
    }
  }
  return 0;
}
