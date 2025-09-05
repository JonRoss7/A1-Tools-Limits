# CS375 A1: Tools & Limits Assignment

## Overview
This assignment introduced essential development tools and system concepts for systems programming, focusing on command-line proficiency and low-level program analysis.

## Tools Learned
- **Git**: Version control for code tracking and collaboration
- **make**: Build automation with Makefiles for multi-file compilation
- **gdb**: Interactive debugging with breakpoints and variable inspection
- **tmux**: Terminal multiplexing for managing development sessions
- **vim**: Command-line text editor for efficient coding
- **ctags**: Code navigation across large codebases

## Core Tasks

### `wc` Implementation
Developed a Unix `wc` utility clone that:
- Counts lines, words, and characters in text files
- Handles command-line arguments and file I/O
- Maintains compatibility with standard `wc` behavior

### System Analysis
#### Executable Investigation with `gdb`
- Loaded programs with command-line arguments
- Set breakpoints and analyzed stack frames
- Examined function addresses and variable values
- Explored `argv` array structure and memory layout

#### Binary Analysis with `objdump`
- Examined executable file formats and program segments
- Identified function locations and memory organization
- Analyzed stack and heap segment structure

#### Memory Mapping (`map.c`)
- Traced program memory layout including stack, heap, and static data
- Investigated stack growth direction and recursive call behavior
- Examined heap allocation patterns and memory contiguity

#### System Resource Limits
- Modified `main.c` to query system limits using `getrlimit()`
- Retrieved maximum stack size, process limits, and file descriptors
- Compared theoretical vs. actual system constraints

## Key Challenges
- **Tool learning curve**: Mastering gdb commands and vim modal editing
- **Memory concepts**: Understanding stack/heap organization and address spaces
- **Debugging skills**: Reading stack traces and correlating objdump with runtime behavior
- **Build systems**: Writing proper Makefiles with dependencies

## Insights Gained
This assignment bridged high-level programming with low-level system interactions, providing practical experience with program execution models, memory management, and development workflows essential for systems programming.