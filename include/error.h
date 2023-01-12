#ifndef ERROR_H
#define ERROR_H

#include <stdbool.h>

enum e_error_id {
  ERROR_NONE,
  ERROR_HEIGTH,
  ERROR_WEIGTH,
  ERROR_NAME,
  ERROR_MAX
};

typedef struct s_error {
  char msg[64];  // Error message
  bool usage;
} t_error;

static const t_error errors[ERROR_MAX] = {
    [ERROR_HEIGTH] = {"This heigth is not allowed\n", true},
    [ERROR_WEIGTH] = {"This weigth is not allowed\n", true},
    [ERROR_NAME] = {"This name is unknown\n", true}};

#endif