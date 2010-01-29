// backend.h -- Go frontend interface to backend  -*- C++ -*-

// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef GO_BACKEND_H
#define GO_BACKEND_H

// A backend type.  This is an abstract class that a specific backend
// will implement.  This simply holds the information which a backend
// needs for a type.

class Backend_type
{
};

// A backend expression.

class Backend_expression
{
};

// A list of Backend_type pointers.

typedef std::vector<Backend_type*> Backend_types;

// Convert a Type to a Backend_type

class Backend_type_generator
{
 public:
  // Produce an error type.  Actually the backend could probably just
  // crash if this is called.
  virtual Backend_type*
  error_type() = 0;

  // Get a void type.  This is used in (at least) two ways: 1) as the
  // return type of a function with no result parameters; 2)
  // unsafe.Pointer is represented as *void.
  virtual Backend_type*
  void_type() = 0;

  // Get the unnamed boolean type.
  virtual Backend_type*
  bool_type() = 0;

  // Get an unnamed integer type with the given signedness and number
  // of bits.
  virtual Backend_type*
  integer_type(bool is_unsigned, int bits) = 0;

  // Get an unnamed floating point type with the given number of bits.
  virtual Backend_type*
  float_type(int bits) = 0;

  // Get the unnamed string type.
  virtual Backend_type*
  string_type() = 0;

  // Get a function type.  The receiver, parameter, and results are
  // generated from the types in the Function_type.  The Function_type
  // is provided so that the names are available.
  virtual Backend_type*
  function_type(const Function_type*, Backend_type* receiver,
		const Backend_types* parameters,
		const Backend_types* results) = 0;

  // Get a struct type.
  virtual Backend_type*
  struct_type(const Struct_type*, const Backend_types* field_types) = 0;

  // Get an array type.
  virtual Backend_type*
  array_type(const Array_type*, const Backend_type* element_type,
	     const Backend_expression* length) = 0;

  // Get a slice type.
  virtual Backend_type*
  slice_type(const Array_type*, const Backend_type* element_type) = 0;

  // Get a map type.
  virtual Backend_type*
  map_type(const Map_type*, const Backend_type* key_type,
	   const Backend_type* value_type) = 0;

  // Get a channel type.
  virtual Backend_type*
  channel_type(const Channel_type*, const Backend_type* element_type) = 0;

  // Get an interface type.
  virtual Backend_type*
  interface_type(const Interface_type*,
		 const Backend_types* method_types) = 0;
};

#endif // !defined(GO_BACKEND_H)
