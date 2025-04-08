# MWE for using LLVM-COV with Gtests

A minimal example showing how I think llvm-cov should be used with gtest to get a code coverage report...

However, the report only shows coverage for the last test fixure run.


## BUILD

```bash
cmake -B build -DBUILD_UNIT_TESTS=ON -DCOVERAGE=ON
make --build build -j 16
bash scripts/make_coverage_reports.sh /home/andy/git/llvm-cov-example/build
```
