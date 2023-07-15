# This file is licensed under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

SKYLIB_VERSION = "1.3.0"

http_archive(
    name = "bazel_skylib",
    sha256 = "74d544d96f4a5bb630d465ca8bbcfe231e3594e5aae57e1edbf17a6eb3ca2506",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/{version}/bazel-skylib-{version}.tar.gz".format(version=SKYLIB_VERSION),
        "https://github.com/bazelbuild/bazel-skylib/releases/download/{version}/bazel-skylib-{version}.tar.gz".format(version=SKYLIB_VERSION),
    ],
)

maybe(
    http_archive,
    name = "llvm_zlib",
    build_file = "//:bazel/zlib-ng.BUILD",
    sha256 = "e36bb346c00472a1f9ff2a0a4643e590a254be6379da7cddd9daeb9a7f296731",
    strip_prefix = "zlib-ng-2.0.7",
    urls = [
        "https://github.com/zlib-ng/zlib-ng/archive/refs/tags/2.0.7.zip",
    ],
)

# llvm libc math tests rely on `mpfr`.
# The availability of `mpfr` is controlled by a flag and can be either `disable`, `system` or `external`.
# Continuous integration uses `system` to speed up the build process (see .bazelrc).
# Otherwise by default it is set to `external`: `mpfr` and `gmp` are built from source by using `rules_foreign_cc`.
# Note: that building from source requires `m4` to be installed on the host machine.
# This is a known issue: https://github.com/bazelbuild/rules_foreign_cc/issues/755.

git_repository(
    name = "rules_foreign_cc",
    remote = "https://github.com/bazelbuild/rules_foreign_cc.git",
    tag = "0.9.0",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

maybe(
    http_archive,
    name = "gmp",
    build_file = "//:bazel/gmp.BUILD",
    sha256 = "fd4829912cddd12f84181c3451cc752be224643e87fac497b69edddadc49b4f2",
    strip_prefix = "gmp-6.2.1",
    urls = [
        "https://gmplib.org/download/gmp/gmp-6.2.1.tar.xz",
        "https://ftp.gnu.org/gnu/gmp/gmp-6.2.1.tar.xz",
    ],
)

# https://www.mpfr.org/mpfr-current/
#
# When updating to a newer version, don't use URLs with "mpfr-current" in them.
# Instead, find a stable URL like the one used currently.
maybe(
    http_archive,
    name = "mpfr",
    build_file = "//:bazel/mpfr.BUILD",
    sha256 = "9cbed5d0af0d9ed5e9f8dd013e17838eb15e1db9a6ae0d371d55d35f93a782a7",
    strip_prefix = "mpfr-4.1.1",
    urls = ["https://www.mpfr.org/mpfr-4.1.1/mpfr-4.1.1.tar.gz"],
)

maybe(
    http_archive,
    name = "mpc",
    build_file = "//:bazel/mpc.BUILD",
    sha256 = "e90f2d99553a9c19911abdb4305bf8217106a957e3994436428572c8dfe8fda6",
    strip_prefix = "mpc-1.2.0",
    urls = ["https://ftp.gnu.org/gnu/mpc/mpc-1.2.0.tar.gz", "https://mirrors.kernel.org/gnu/mpc/mpc-1.2.0.tar.gz"],
)

maybe(
    new_git_repository,
    name = "pfm",
    build_file = "//:bazel/pfm.BUILD",
    remote = "https://git.code.sf.net/p/perfmon2/libpfm4",
    tag = "v4.12.1",
)

maybe(
    http_archive,
    name = "llvm_zstd",
    build_file = "//:bazel/zstd.BUILD",
    sha256 = "7c42d56fac126929a6a85dbc73ff1db2411d04f104fae9bdea51305663a83fd0",
    strip_prefix = "zstd-1.5.2",
    urls = [
        "https://github.com/facebook/zstd/releases/download/v1.5.2/zstd-1.5.2.tar.gz"
    ],
)
