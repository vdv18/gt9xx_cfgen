#ifndef __PARSEOPT_H__
#define __PARSEOPT_H__

struct options_s {
  int result;
  int help_enabled;
  int stdout_enabled;
  char *input_file;
  char *output_file;
  char *touch_value;
  char *leave_value;
  char *tx_value;
  char *rx_value;
};

int parse_options(int argc, char *argv[], struct options_s *res);
void parse_help(void);

#endif//__PARSEOPT_H__
