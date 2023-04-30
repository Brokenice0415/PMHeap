#include <assert.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libpmem.h>
#include "memory.h"
#include "sys/mman.h"
#include "x86intrin.h"
#include <sys/time.h>
#include <pthread.h>

#include "nvalloc.h"

void** tmptr;
void* p[256];
uintptr_t buf[256];

int main() {
  nvalloc_init("1");
  // [INFO] Command buffer: 0x6e016000
  // [INFO] Input size: 881
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(0, (void**)tmptr);
  p[0] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(14, (void**)tmptr);
  p[1] = (void*)*tmptr;
  free(tmptr);
  ((uintptr_t*)p[1])[0] = (uintptr_t)&buf[179];
  // [VULN] Double free
  nvalloc_free_from((void**)&p[0]);
  buf[187] = (uintptr_t)&buf[252];
  buf[188] = (uintptr_t)&buf[147];
  buf[189] = 0;
  buf[191] = (uintptr_t)p[0] + -32;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(19, (void**)tmptr);
  p[2] = (void*)*tmptr;
  free(tmptr);
  ((uintptr_t*)p[2])[0] = 60280;
  ((uintptr_t*)p[2])[1] = 0;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(14, (void**)tmptr);
  p[3] = (void*)*tmptr;
  free(tmptr);
  nvalloc_free_from((void**)&p[2]);
  nvalloc_free_from((void**)&p[3]);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(21, (void**)tmptr);
  p[4] = (void*)*tmptr;
  free(tmptr);
  buf[103] = (uintptr_t)&p[3] + 16;
  buf[105] = (uintptr_t)&p[2] + -16;
  buf[107] = 0;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(14, (void**)tmptr);
  p[5] = (void*)*tmptr;
  free(tmptr);
  buf[224] = 84746;
  buf[237] = (uintptr_t)&buf[87];
  buf[238] = 111;
  buf[239] = (uintptr_t)p[3] + -24;
  buf[241] = 53;
  // [VULN] Double free
  nvalloc_free_from((void**)&p[3]);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(312, (void**)tmptr);
  p[6] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(21, (void**)tmptr);
  p[7] = (void*)*tmptr;
  free(tmptr);
  nvalloc_free_from((void**)&p[5]);
  buf[105] = 0;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(21, (void**)tmptr);
  p[8] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(67, (void**)tmptr);
  p[9] = (void*)*tmptr;
  free(tmptr);
  buf[201] = 24;
  buf[202] = 0;
  buf[102] = 38;
  buf[151] = 62;
  buf[154] = 14;
  buf[155] = 32;
  buf[175] = 0;
  buf[176] = 118;
  buf[178] = (uintptr_t)p[3] + 8;
  buf[36] = 8;
  buf[39] = 14;
  buf[43] = 31;
  ((uintptr_t*)p[8])[0] = 0;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(38, (void**)tmptr);
  p[10] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(14, (void**)tmptr);
  p[11] = (void*)*tmptr;
  free(tmptr);
  buf[94] = (uintptr_t)p[7] + 32;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(16, (void**)tmptr);
  p[12] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(21, (void**)tmptr);
  p[13] = (void*)*tmptr;
  free(tmptr);
  buf[164] = 0;
  buf[165] = 43;
  buf[166] = 5;
  buf[101] = 21;
  buf[103] = (uintptr_t)p[5] + 32;
  buf[104] = (uintptr_t)p[13] + 32;
  buf[137] = 0;
  buf[138] = (uintptr_t)&buf[60] - (uintptr_t)p[3] + -16;
  // [VULN] Double free
  nvalloc_free_from((void**)&p[5]);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(21, (void**)tmptr);
  p[14] = (void*)*tmptr;
  free(tmptr);
  ((uintptr_t*)p[11])[0] = (uintptr_t)&p[8] + 0;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(32, (void**)tmptr);
  p[15] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(38, (void**)tmptr);
  p[16] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(103, (void**)tmptr);
  p[17] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(974, (void**)tmptr);
  p[18] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(8, (void**)tmptr);
  p[19] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(936, (void**)tmptr);
  p[20] = (void*)*tmptr;
  free(tmptr);
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(29, (void**)tmptr);
  p[21] = (void*)*tmptr;
  free(tmptr);
  ((uintptr_t*)p[13])[0] = 0;
  tmptr = (void**)malloc(sizeof(void**));
  nvalloc_malloc_to(32, (void**)tmptr);
  p[22] = (void*)*tmptr;
  free(tmptr);
  // [BUG] Found overlap
  // p[22]=0x7f4aed616f40 (size=32), p[13]=0x7f4aed616f40 (size=21)
  assert((p[22] <= p[13] && p[13] < p[22] + 32) || (p[13] <= p[22] && p[22] < p[13] + 21));
  // [BUG] Found overlap
  // p[22]=0x7f4aed616f40 (size=32), p[13]=0x7f4aed616f40 (size=21)
  assert((p[22] <= p[13] && p[13] < p[22] + 32) || (p[13] <= p[22] && p[22] < p[13] + 21));
  buf[226] = (uintptr_t)&buf[166];
}
// The number of actions: 70
// [INFO] EVENT_OVERLAP is detected
