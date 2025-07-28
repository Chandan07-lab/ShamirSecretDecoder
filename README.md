# Shamir's Secret Sharing (SSS) Reconstruction

This project reconstructs a secret using Lagrange Interpolation from shares stored in a JSON file.

## 📂 Directory Structure
- `include/sss.hpp`: Function declarations and types.
- `src/sss.cpp`: Core logic for arithmetic and SSS reconstruction.
- `test/main.cpp`: CLI to run the reconstruction.
- `testcases/input.json`: Input shares in JSON format.

## 🛠️ Build and Run

```bash
make
./sss
