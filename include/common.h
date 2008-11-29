/* 
 * Written by Josh Dybnis and released to the public domain, as explained at
 * http://creativecommons.org/licenses/publicdomain
 */
#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>

#define malloc "DON'T USE MALLOC" // use nbd_malloc() instead
#define free   "DON'T USE FREE"   // use nbd_free() instead

#define MAX_NUM_THREADS 4 // make this whatever you want, but make it a power of 2

#define CACHE_LINE_SIZE 64

#define EXPECT_TRUE(x)     __builtin_expect(x, 1)
#define EXPECT_FALSE(x)    __builtin_expect(x, 0)

#define SYNC_SWAP          __sync_lock_test_and_set
#define SYNC_CAS           __sync_val_compare_and_swap
#define SYNC_ADD           __sync_add_and_fetch
#define SYNC_FETCH_AND_OR  __sync_fetch_and_or

#define MASK(n)     ((1ULL << (n)) - 1)

#define TRUE  1
#define FALSE 0

#define TAG          (1ULL << 63)
#define TAG_VALUE(v) ((uint64_t)(v) |  TAG)
#define IS_TAGGED(v) ((uint64_t)(v) &  TAG)
#define STRIP_TAG(v) ((uint64_t)(v) & ~TAG)

typedef unsigned long long uint64_t;
typedef unsigned int       uint32_t;
typedef unsigned char      uint8_t;

#include "lwt.h"
#endif //COMMON_H