// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VECPU_H_
#define _VECPU_H_

#include "verilated.h"

class VECPU__Syms;

//----------

VL_MODULE(VECPU) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(switch1,0,0);
    VL_OUT8(led1,0,0);
    VL_OUT8(led2,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(ECPU__DOT__param1,7,0);
    VL_SIG8(ECPU__DOT__param2,7,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__c[9],0,0);
    VL_SIG8(ECPU__DOT__ADD2__DOT__c[17],0,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__0__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__1__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__2__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__3__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__4__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__5__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__6__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(ECPU__DOT__ADD1__DOT__adder_block__BRA__7__KET____DOT____Vcellout__add____pinNumber5,0,0);
    VL_SIG8(__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[9],0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VECPU__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VECPU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VECPU(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VECPU();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VECPU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VECPU__Syms* symsp, bool first);
  private:
    static QData _change_request(VECPU__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(VECPU__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(VECPU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VECPU__Syms* __restrict vlSymsp);
    static void _eval_settle(VECPU__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(VECPU__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
