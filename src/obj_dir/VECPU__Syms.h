// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VECPU__Syms_H_
#define _VECPU__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VECPU.h"

// SYMS CLASS
class VECPU__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VECPU*                         TOPp;
    
    // CREATORS
    VECPU__Syms(VECPU* topp, const char* namep);
    ~VECPU__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
