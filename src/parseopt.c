#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "parseopt.h"

const char *PROGRAM_NAME = "gt9xx_cfgen";

#define OPTION_HELP   0
#define OPTION_STDOUT 1
#define OPTION_INPUT  2
#define OPTION_OUTPUT 3
#define OPTION_TOUCH  4
#define OPTION_LEAVE  5
#define OPTION_TX     6
#define OPTION_RX     7
#define OPTIONLEN     9

#define OPTIONS_LIST							\
  _(OPTION_HELP,   "help",   no_argument, help_enabled)			\
  _(OPTION_STDOUT, "stdout", no_argument, stdout_enabled)		\
  _(OPTION_INPUT,  "input",  required_argument, input_file)		\
  _(OPTION_OUTPUT, "output", required_argument, output_file)		\
  _(OPTION_TOUCH,  "touch",  required_argument, touch_value)		\
  _(OPTION_LEAVE,  "leave",  required_argument, leave_value)		\
  _(OPTION_TX,     "tx",     required_argument, tx_value)		\
  _(OPTION_RX,     "rx",     required_argument, rx_value)		\


void parse_help()
{
  printf("\nusage: %s arg1 arg2\n", PROGRAM_NAME);
  printf(
    "  --help: this usage help\n"
    "  --output <filename>: output filename\n"
    "  --stdout: output generated configuration to standard output\n"
    "  --touch <0-255>: screen touch level\n"
    "  --leave <0-255>: screen leave level\n"
    "  --tx <0-7>: panel transmitting level\n"
    "  --rx <0-7>: panel receiving level\n");
}

int parse_options(int argc, char *argv[], struct options_s *res) {
  int option_index = 0;
  int ret = 0;
  int cnt = 0;

#define _(C,S,A,X)				\
  [C] = {S, A, 0, 0},
  static struct option options[OPTIONLEN] = {
    OPTIONS_LIST
  };
#undef _

  memset(&ret,0,sizeof(ret));

  while(1) {
    ret = getopt_long(argc, argv, "",
		      options, &option_index);
    if (ret == -1) {
      break;
    }

    cnt ++;
    if (ret == 0) {
      switch(option_index) {
      case OPTION_HELP:
	res->help_enabled = 1;
	break;
      case OPTION_STDOUT:
	res->stdout_enabled = 1;
	break;
      case OPTION_INPUT:
	if (optarg)
	  res->input_file = optarg;
	break;
      case OPTION_OUTPUT:
	if (optarg)
	  res->output_file = optarg;
	break;
      case OPTION_TOUCH:
	if (optarg)
	  res->touch_value = optarg;
	break;
      case OPTION_LEAVE:
	if (optarg)
	  res->leave_value = optarg;
	break;
      case OPTION_TX:
	if (optarg)
	  res->tx_value = optarg;
	break;
      case OPTION_RX:
	if (optarg)
	  res->rx_value = optarg;
	break;
      default:
	break;
      };
    }
  }
  if (cnt)
    return 0;
  return -1;
}
