# Expect Stat
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://github.com/yvoinov/expect-stat/blob/master/LICENSE)

## Abstract

A very simple class for counting the number of transitions along IF-ELSE branches.

Designed to easily determine which branch prediction hint to put in a hot code. Allows you to simplify this task, reducing the need for thorough testing and benchmarking.

## Usage

To use, you need to copy the file in the directory with the desired source code, include the file in the code and put method calls on the corresponding branches. Each transition atomically increases the value of the corresponding counter. Then recompile the program being tested. After completion or interruption of work, the destructor will output the counter values to the output stream. Based on this, you can decide whether to use the hint.

```cpp
#include "expect_stat.h"	// Include at the module level to instantiate
...

	if (condition) {
		es.if_inc();	// Increment if branch
		...
	} else {
		es.else_inc();	// Increment else branch
		...
	}
...
```

## Notes

Class optimized for any C++11 compliant compiler, tested on GCC, Clang, Oracle Developer Studio.
