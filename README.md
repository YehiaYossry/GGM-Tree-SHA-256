# GGM Tree Implementation with SHA-256 PRG

## Overview
This project implements a **Goldreich-Goldwasser-Micali (GGM) Tree** utilizing a custom **SHA-256 Pseudorandom Generator (PRG)** in C++. The GGM tree is a fundamental cryptographic construction used to build pseudorandom functions (PRFs) and secure, tree-based key derivation schemes from a single short random seed.

## How the GGM Tree Works
* **Seed Expansion:** The tree starts with a root node containing a master cryptographic seed.
* **Pseudorandom Generation (PRG):** Each node's value is passed through a SHA-256 based PRG to deterministically generate its two children (left child and right child). 
* **Branching & Evaluation:** By traversing down the tree using a sequence of bits (left for `0`, right for `1`), you can efficiently evaluate and derive pseudorandom paths and keys while maintaining security and consistency.

## Data Structures & Architecture
* **Node & Tree Design:** Built using custom data structures to manage hierarchical node relationships, dynamic memory, and efficient tree traversal.
* **`ggm_tree.hpp` / `ggm_tree.cpp`:** Handles the core tree construction logic, node expansion, and path evaluation algorithms.
* **`prg.hpp` / `prg.cpp`:** Implements the cryptographic expansion function leveraging SHA-256 hashing routines.
* **`utilities.hpp` / `utilities.cpp`:** Provides helper functions for data manipulation, byte-stream conversions, and hashing operations.
* **`main.cpp`:** The primary driver file initializing the structure, executing tests, and outputting the computed hash values.

## Project Structure
* `ggm_tree.hpp` / `ggm_tree.cpp`
* `prg.hpp` / `prg.cpp`
* `utilities.hpp` / `utilities.cpp`
* `main.cpp`