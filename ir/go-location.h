// go-location.h -- GCC specific Location declaration.   -*- C++ -*-

// Copyright 2011 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef GO_LOCATION_H
#define GO_LOCATION_H

#include "go-system.h"

// Opaque tag/handle returned by the linemap

typedef unsigned linemap_handle;

// A location in an input source file.

class Location
{
 public:
  Location()
      : handle_(0)
  { }

  explicit Location(linemap_handle handle)
      : handle_(handle)
  { }

  linemap_handle
  handle() const
  { return this->handle_; }

 private:
  linemap_handle handle_;
};

// The Go frontend requires the ability to compare Locations.
inline bool
operator<(Location loca, Location locb)
{
  return loca.handle() < locb.handle();
}

inline bool
operator==(const Location loca, const Location locb)
{
  return loca.handle() == locb.handle();
}

#endif // !defined(GO_LOCATION_H)
