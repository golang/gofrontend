load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "go_frontend",
    srcs =  glob(["go/*.cc", "ir/*.cc"]),
    hdrs = glob(["go/*.h", "ir/*.h"]),
    visibility = ["//visibility:public"],
    deps = ["@gmp//:gmp_", "@mpfr//:mpfr_external"]
)
