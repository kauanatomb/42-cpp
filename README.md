# CPP Modules (00–09)

## 🧠 Objective
This series of projects is part of the 42 curriculum and aims to build a deep understanding of modern C++ through progressively complex modules.

The focus is on object-oriented design, memory management, polymorphism, templates, STL usage, type safety, and robust error handling, all implemented under strict constraints (no forbidden libraries, no shortcuts).

---

## 🏗️ Module 00–01: Foundations & Memory

**Goal:** Understand basic C++ syntax and object lifecycle.

Key concepts:
- Classes and member functions
- Constructors and destructors
- Stack vs heap allocation
- References and pointers
- File streams
- Basic Makefile structure

Core learning:
Understanding how C++ manages object lifetime and how it differs from C, especially regarding constructors/destructors and RAII principles.

---

## 🧩 Module 02–04: Canonical Form & Polymorphism

**Goal:** Master object-oriented design and runtime polymorphism.

Key concepts:
- Orthodox Canonical Form (Rule of Three)
- Operator overloading
- Inheritance and method overriding
- Virtual functions
- Abstract classes and interfaces
- Deep vs shallow copy

Core learning:
Designing class hierarchies correctly and understanding dynamic dispatch through virtual tables.  
Avoiding slicing problems and ensuring safe polymorphic destruction.

---

## ⚠️ Module 05–06: Exceptions & Type Safety

**Goal:** Handle errors safely and understand casting mechanisms.

Key concepts:
- try/catch blocks
- Custom exception classes
- `static_cast`, `dynamic_cast`, `reinterpret_cast`
- Scalar conversion and parsing
- Runtime type identification

Core learning:
Building robust systems with explicit error handling instead of undefined behavior.  
Understanding when casting is safe and when it signals poor design.

---

## 🧠 Module 07–09: Templates & STL

**Goal:** Write generic, reusable, and efficient C++ code.

Key concepts:
- Function templates
- Class templates
- Template specialization
- STL containers (`vector`, `map`, etc.)
- Iterators and algorithms
- Complexity awareness

Core learning:
Leveraging the Standard Template Library instead of reinventing data structures.  
Understanding abstraction cost, compile-time polymorphism, and generic programming principles.

---

## 🚀 Compilation

Each module:

```bash
make
make clean
make fclean
make re
```
> Each exercise generates its own executable.

## 🧩 Challenges Faced

- Designing correct copy semantics (deep vs shallow copy)
- Avoiding memory leaks in polymorphic hierarchies
- Understanding implicit vs explicit conversions
- Writing template code without sacrificing readability
- Debugging subtle runtime polymorphism issues

## ✅ Key Outcomes

- Strong understanding of C++ object model
- Confidence with memory ownership and RAII
- Ability to design extensible class hierarchies
- Practical knowledge of STL containers and algorithms
- Improved reasoning about type systems and abstraction boundaries
