# KL-HMAC: Keyless Homomorphic Message Authentication Codes

This repository provides a C++ implementation of the **KL-HMAC** scheme proposed in our paper on secure network coding.

## Overview

Network Coding (NC) improves network resilience and capacity by allowing intermediate nodes to recode packets. However, this introduces data integrity risks. Traditional Homomorphic Message Authentication Codes (HMACs) address these risks using cryptographic keys, which must be securely distributed and periodically updated, leading to additional latency and overhead.

KL-HMAC eliminates the need for cryptographic keys. Instead, it generates authentication MACs based on:
- Self-orthogonality within packets
- Cross-orthogonality across packets

This removes key distribution requirements while maintaining security and reducing overhead.

## Features

- Keyless authentication for network coding
- Two verification methods with different trade-offs:
  - Higher security vs. lower computational complexity
- Reduced latency in:
  - MAC generation (~55%)
  - Packet verification (~65%)
- Simulation of adversarial scenarios and key-recovery attacks
- No need for secure key distribution or key management

## Project Structure

```
KL-HMAC/
├── main.cpp              # Entry point for simulations
├── Makefile              # Build configuration
├── lib/
│   ├── ff.h              # Finite field definitions
│   ├── cff.h             # Coding field functions
│   ├── cFunctions.h      # Utility functions
│   ├── hpacket.h         # Packet structure
│   ├── keyless.h         # KL-HMAC interface
│   ├── src/
│   │   ├── ff.cpp
│   │   ├── cff.cpp
│   │   ├── cFunctions.cpp
│   │   ├── hpacket.cpp
│   │   └── keyless.cpp
```

## Build & Run

```bash
make
./klhmac
```

## Definitions

- **Payload size (n):** Number of data symbols per packet (excluding coding coefficients and headers)
- **Symbols/packet:** Compact notation used for payload size
- **Packets/generation (m):** Number of packets observed within a generation

## Reference

If you use this code, please cite:

> KL-HMAC: Keyless Homomorphic Message Authentication Codes

## Authors

- Akif Mehmet Kurt
- Hosein K. Nazari
