
// Copyright 2018 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef GO_SYSTEM_H
#define GO_SYSTEM_H

#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <climits>
#include <ctype.h>
#include <stdarg.h>

# include <unordered_map>
# include <unordered_set>

#include <filesystem>

# define Unordered_map(KEYTYPE, VALTYPE) \
	std::unordered_map<KEYTYPE, VALTYPE>

# define Unordered_map_hash(KEYTYPE, VALTYPE, HASHFN, EQFN) \
	std::unordered_map<KEYTYPE, VALTYPE, HASHFN, EQFN>

# define Unordered_set(KEYTYPE) \
	std::unordered_set<KEYTYPE>

# define Unordered_set_hash(KEYTYPE, HASHFN, EQFN) \
	std::unordered_set<KEYTYPE, HASHFN, EQFN>

#include <iostream>
#include <assert.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define _(x) x

// In a previous version of this file, go_assert was simply #define'd to
// 'assert', meaning that gofrontend assertions would be compiled away for
// release builds, which was problematic. This version of go_assert applies for
// all build flavors, meaning that we'll get assertion checking for release
// builds. FWIW turning on assertions for all of LLVM can be very expensive from
// a compile time perspective, but keeping the assertion checks in gofrontend
// comes with more modest overhead.

extern void go_assert_fail(const char *expr, const char *filename,
                           int line, const char *function);

#define go_assert(expr) \
     (static_cast <bool> (expr)						\
      ? void (0)							\
      : go_assert_fail (#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__))

// #include "llvm-includes.h"
// todo: impl function
#define go_unreachable() (throw exception("unreachable"))

#define ARRAY_SIZE(A) (sizeof (A) / sizeof ((A)[0]))

#define IS_ABSOLUTE_PATH(x) \
  std::filesystem::path(x).is_absolute()

#define HOST_BITS_PER_WIDE_INT 64
#define HOST_WIDE_INT long

#define ISALNUM(x) isalnum(x)

extern const char *lbasename(const char *);
extern const char *xstrerror(int);
extern bool IS_DIR_SEPARATOR(char);
extern bool ISXDIGIT(char);

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

#endif // !defined(GO_SYSTEM_H)
