# fcksh

**fcksh** is a custom Unix/Linux shell and terminal environment written from scratch in C++.

The goal is not to build another toy shell that can run `ls` and `cd`.

The long-term goal of fcksh is to become a **full-featured replacement for traditional command-line environments such as Bash**, combining a powerful shell language, process management, job control, scripting, terminal interaction, and modern features into one cohesive system.

> **Built from scratch. Built for Linux. Built to replace the boring parts.**

## 🚧 Project Status

**Early development.**

fcksh is currently being built from the ground up. Core functionality will be implemented incrementally, starting with Linux process creation and command execution and eventually expanding into a complete shell and terminal environment.

The project is intentionally being developed without relying on an existing shell implementation as its foundation.

## 🎯 Vision

fcksh aims to provide:

* A complete interactive shell
* A shell scripting language
* Process and job management
* Pipelines and I/O redirection
* Environment and variable management
* Background and foreground jobs
* Signal handling
* Command history
* Tab completion
* Aliases and functions
* Conditional execution
* Shell scripting constructs
* Command substitution
* Wildcards and globbing
* Advanced parsing
* Proper terminal control
* Configurable prompts
* Extensible architecture
* Modern quality-of-life features
* Compatibility with existing Unix/Linux tooling

The ultimate objective is to make fcksh capable of handling the workflows users currently depend on Bash and other mature shells for, while providing its own architecture and feature set.

## 🧠 Why C++?

fcksh is intentionally written in C++ because the project is fundamentally about understanding and controlling the systems underneath the shell.

The implementation will interact directly with Linux primitives such as:

* `fork()`
* `execve()` / `execvp()`
* `waitpid()`
* `pipe()`
* `dup2()`
* `open()`
* `close()`
* `kill()`
* `signal()` / `sigaction()`
* Process groups
* Sessions
* Terminal control
* File descriptors
* PTYs

C++ provides the low-level control required while still allowing the project to develop a structured and maintainable codebase.

## 🏗️ Architecture

The architecture will evolve as the project grows, but the shell is planned around several major components:

```text
fcksh
│
├── Input Layer
│   ├── Terminal input
│   ├── History
│   └── Line editing
│
├── Lexer
│   └── Tokenization
│
├── Parser
│   └── Command / expression parsing
│
├── Execution Engine
│   ├── Built-ins
│   ├── External commands
│   ├── Pipelines
│   ├── Redirection
│   └── Command substitution
│
├── Process Manager
│   ├── Processes
│   ├── Process groups
│   ├── Jobs
│   └── Signals
│
├── Shell Runtime
│   ├── Environment
│   ├── Variables
│   ├── Functions
│   ├── Aliases
│   └── Expansions
│
├── Scripting Engine
│   ├── Conditions
│   ├── Loops
│   ├── Functions
│   └── Script execution
│
└── Terminal Layer
    ├── TTY
    ├── PTY
    ├── Terminal modes
    └── Interactive control
```

The architecture will be designed to keep parsing, execution, process management, and terminal handling separate rather than turning the project into one enormous `main.cpp` crime scene.

## 🛠️ Planned Features

### Command Execution

* [ ] External command execution
* [ ] Built-in commands
* [ ] PATH resolution
* [ ] Environment variables
* [ ] Exit status handling

### Redirection

* [ ] `>`
* [ ] `>>`
* [ ] `<`
* [ ] `2>`
* [ ] `2>>`
* [ ] `&>`
* [ ] File descriptor duplication
* [ ] Here documents
* [ ] Here strings

### Pipelines

```bash
cat file.txt | grep "error" | sort | uniq
```

Planned support includes arbitrary pipeline chains and proper file-descriptor management.

### Job Control

* [ ] Background processes
* [ ] Foreground processes
* [ ] `jobs`
* [ ] `fg`
* [ ] `bg`
* [ ] Process groups
* [ ] Terminal ownership
* [ ] `Ctrl+C`
* [ ] `Ctrl+Z`
* [ ] `Ctrl+\`

### Shell Language

* [ ] Variables
* [ ] Quoting
* [ ] Escaping
* [ ] Wildcards
* [ ] Command substitution
* [ ] Arithmetic expansion
* [ ] Conditions
* [ ] Loops
* [ ] Functions
* [ ] Aliases
* [ ] Return/exit status
* [ ] Script files

### Interactive Experience

* [ ] Command history
* [ ] Persistent history
* [ ] Tab completion
* [ ] Syntax-aware input
* [ ] Configurable prompt
* [ ] Custom key bindings
* [ ] Multiline commands
* [ ] Better error messages

### Terminal Capabilities

fcksh is intended to eventually go beyond simply launching processes.

Planned work includes direct interaction with:

* TTYs
* PTYs
* Terminal modes
* Terminal size
* ANSI/VT escape sequences
* Interactive applications
* Terminal signals
* Terminal process groups

The objective is to understand the terminal stack rather than treating the terminal as a magical rectangle that somehow prints text.

## 🔬 Development Philosophy

fcksh is being developed from the bottom up.

Instead of beginning with a large framework and hiding the interesting parts behind abstractions, the project will progressively implement the underlying mechanisms:

```text
Input
  ↓
Lexing
  ↓
Parsing
  ↓
Execution
  ↓
Processes
  ↓
File Descriptors
  ↓
Pipes / Redirection
  ↓
Signals
  ↓
Process Groups
  ↓
Job Control
  ↓
Terminal Control
  ↓
Shell Language
```

Every major subsystem should be understandable on its own.

The goal is not merely to make something that works.

The goal is to understand **why it works**.

## 🐧 Platform

Primary target:

**Linux**

The project will initially target Linux/POSIX systems and use Linux/Unix system interfaces directly where appropriate.

Cross-platform support is not a priority during the early development stages.

## 🔧 Building

Requirements:

* Linux
* C++ compiler with C++17 or newer support
* GNU Make or another build system

Clone the repository:

```bash
git clone git@github.com:cybreva/fcksh.git
cd fcksh
```

Build instructions will be expanded as the project develops.

## 📚 Learning Through Building

fcksh is also a systems-programming learning project.

Development will cover practical concepts including:

* Unix process model
* System calls
* File descriptors
* Process creation
* Program execution
* IPC
* Pipes
* Signals
* TTYs
* PTYs
* Process groups
* Sessions
* Terminal control
* Parsing
* Interpreters
* Shell languages
* Systems programming in C++

## 🚀 Long-Term Goal

The final objective is ambitious:

> **Build a serious Linux shell and terminal environment capable of replacing the traditional command-line workflow rather than merely demonstrating how `fork()` works.**

fcksh will start small because every large systems project has to start somewhere.

It will not stay small.

---

**fcksh**
*Fuck the limitations. Build the shell.*
