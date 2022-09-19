#ifndef H_OS_H

#include "types.h"
#include "utils.h"
#include "os_window.h"
#include "os_memory.h"
#include "os_time.h"
#include "os_io.h"
#include "os_log.h"

b32 os_should_quit(void);
void os_destroy(void);
void os_init(void);

#define H_OS_H
#endif
