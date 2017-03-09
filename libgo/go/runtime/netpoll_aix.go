// Copyright 2017 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Fake network poller for AIX
// TODO : this is just stubs to allow building, implementation required

package runtime

func netpollinit() {
}

func netpollopen(fd uintptr, pd *pollDesc) int32 {
	return 0
}

func netpollclose(fd uintptr) int32 {
	return 0
}

func netpollarm(pd *pollDesc, mode int) {
}

func netpoll(block bool) *g {
	return nil
}
