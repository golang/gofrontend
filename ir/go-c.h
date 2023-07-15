//===-- go-c.h ------------------------------------------------------------===//
//
// Copyright 2018 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.
//
//===----------------------------------------------------------------------===//
//
// Header file included by gofrontend; provides definitions for FE routines such
// as 'go_add_search_path', as well as the struct go_create_gogo_args.

#ifndef LLVMGOFRONTEND_GO_C_H
#define LLVMGOFRONTEND_GO_C_H

#define GO_EXTERN_C

class Linemap;
class Backend;

// Struct used to initialize gofrontend. Bridge creates an instance of this
// struct and passes it to gofrontend as part of setup.

struct go_create_gogo_args
{
  int int_type_size;
  int pointer_size;
  const char* pkgpath;
  const char* prefix;
  const char* relative_import_path;
  const char* c_header;
  const char* embedcfg;
  Backend* backend;
  Linemap* linemap;
  bool check_divide_by_zero;
  bool check_divide_overflow;
  bool compiling_runtime;
  int debug_escape_level;
  const char* debug_escape_hash;
  int64_t nil_check_size_threshold;
  bool debug_optimization;
  bool need_eqtype;
};

// These are defined in gofrontend and called from the bridge.
extern bool saw_errors(void);
extern const char *go_localize_identifier(const char *);
extern const char *go_read_export_data (int, off_t, char **, size_t *, int *);
extern int go_enable_dump (const char*);
extern int go_enable_optimize (const char*, int);
extern void go_add_search_path(const char *);
extern void go_create_gogo(const struct go_create_gogo_args *);
extern void go_parse_input_files(const char **, unsigned int,
                                 bool only_check_syntax,
                                 bool require_return_statement);
extern void go_write_globals(void);

// Defined in the bridge; called by gofrontend.
extern void go_imported_unsafe(void);

#endif /* !defined(LLVMGOFRONTEND_GO_C_H) */
