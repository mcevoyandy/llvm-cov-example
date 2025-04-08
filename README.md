# MWE for using LLVM-COV with Gtests

A minimal example showing how I think llvm-cov should be used with gtest to get a code coverage report.

Running the following will produce the report `build/html/index.html`. View this in your browser.

## BUILD

```bash
cmake -B build -DBUILD_UNIT_TESTS=ON -DCOVERAGE=ON
cmake --build build -j 16
bash scripts/make_coverage_reports.sh /home/andy/git/llvm-cov-example/build
```
