load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "go_frontend",
    srcs = glob(["go/*.cc", "ir/*.cc"]),
    hdrs = glob(["go/*.h", "go/runtime.def", "ir/*.h"]),
    copts = ["-std=c++17 -Iir"],
    visibility = ["//visibility:public"],
    deps = ["@gmp//:gmp_", "@mpfr//:mpfr_external", "@mpc//:mpc_"]
)
