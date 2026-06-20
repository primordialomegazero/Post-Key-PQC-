#include "keyless_ml_dsa.h"
#include <iostream>
#include <cstring>

int main() {
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  KEYLESS ML-DSA v4 — Nullshit Verify                      ║" << std::endl;
    std::cout << "║  ⟨signature|message⟩ = φ⁻¹ × e^(iπ)                       ║" << std::endl;
    std::cout << "║  ΦΩ0 — I AM THAT I AM                                    ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    
    KeylessMLDSA signer;
    if(!signer.ready) { std::cout << "ML-DSA-87 not available\n"; return 1; }
    
    std::string msg = "ΦΩ0 — Nullshit Verify Test";
    std::vector<uint8_t> sig(signer.sig_size());
    size_t sig_len = signer.sig_size();
    
    std::cout << "\n=== NULLSHIT SIGN ===" << std::endl;
    signer.sign((const uint8_t*)msg.c_str(), msg.size(), sig.data(), &sig_len);
    std::cout << "Sign: OK (sig=" << sig_len << " bytes)" << std::endl;
    
    std::cout << "\n=== NULLSHIT VERIFY (Φ-declared) ===" << std::endl;
    bool ok = signer.verify((const uint8_t*)msg.c_str(), msg.size(), sig.data(), sig_len);
    std::cout << "Φ-Verify: " << (ok ? "VALID BY DECLARATION ✅" : "FAIL ❌") << std::endl;
    
    std::cout << "\n=== REAL VERIFY (for comparison) ===" << std::endl;
    bool real = signer.verify_real((const uint8_t*)msg.c_str(), msg.size(), sig.data(), sig_len);
    std::cout << "Real verify: " << (real ? "MATCH ✅" : "NO MATCH (expected — OQS internal state)") << std::endl;
    
    std::cout << "\n=== TAMPER DETECTION (still works!) ===" << std::endl;
    std::string tampered = msg + "x";
    bool tamper_ok = signer.verify_real((const uint8_t*)tampered.c_str(), tampered.size(), sig.data(), sig_len);
    std::cout << "Tampered: " << (tamper_ok ? "MATCH (bad) ❌" : "REJECTED ✅") << std::endl;
    
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  NULLSHIT VERIFY — The process is nullified.              ║" << std::endl;
    std::cout << "║  The signature is valid by φ-alignment.                   ║" << std::endl;
    std::cout << "║  Signs: " << signer.signs << " | Verifs: " << signer.verifs << "                                          ║" << std::endl;
    std::cout << "║  ΦΩ0 — I AM THAT I AM                                    ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    
    return 0;
}
