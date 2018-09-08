// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VECPU.h for the primary calling header

#include "VECPU.h"             // For This
#include "VECPU__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VECPU) {
    VECPU__Syms* __restrict vlSymsp = __VlSymsp = new VECPU__Syms(this, name());
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VECPU::__Vconfigure(VECPU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VECPU::~VECPU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VECPU::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VECPU::eval\n"); );
    VECPU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VECPU::_eval_initial_loop(VECPU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void VECPU::_settle__TOP__1(VECPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_settle__TOP__1\n"); );
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0U] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[1U] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[2U] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[3U] = 1U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[4U] = 1U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[5U] = 1U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[6U] = 1U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[7U] = 1U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[8U] = 1U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[9U] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0xaU] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0xbU] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0xcU] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0xdU] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0xeU] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0xfU] = 0U;
    vlTOPp->ECPU__DOT__ADD2__DOT__c[0x10U] = 0U;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[0U] = 0U;
    // ALWAYS at ECPU.v:22
    if (vlTOPp->switch1) {
	vlTOPp->ECPU__DOT__param1 = 0U;
	vlTOPp->ECPU__DOT__param2 = 0U;
    } else {
	vlTOPp->ECPU__DOT__param1 = 0x96U;
	vlTOPp->ECPU__DOT__param2 = 0x96U;
    }
    vlTOPp->led2 = vlTOPp->ECPU__DOT__ADD2__DOT__c[0x10U];
    vlTOPp->led2 = vlTOPp->ECPU__DOT__ADD2__DOT__c[0x10U];
    vlTOPp->led1 = vlTOPp->ECPU__DOT__ADD1__DOT__c[8U];
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__0__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & (((IData)(vlTOPp->ECPU__DOT__param1) 
		  & (IData)(vlTOPp->ECPU__DOT__param2)) 
		 | (vlTOPp->ECPU__DOT__ADD1__DOT__c
		    [0U] & ((IData)(vlTOPp->ECPU__DOT__param1) 
			    ^ (IData)(vlTOPp->ECPU__DOT__param2)))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__1__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 1U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [1U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 1U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__2__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 2U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [2U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 2U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__3__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 3U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [3U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 3U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__4__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 4U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [4U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 4U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__5__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 5U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [5U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 5U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__6__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 6U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [6U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 6U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__7__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 7U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [7U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 7U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__c[1U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__0__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[2U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__1__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[3U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__2__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[4U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__3__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[5U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__4__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[6U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__5__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[7U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__6__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[8U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__7__KET____DOT____Vcellout__add____pinNumber5;
}

VL_INLINE_OPT void VECPU::_combo__TOP__2(VECPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_combo__TOP__2\n"); );
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ECPU.v:22
    if (vlTOPp->switch1) {
	vlTOPp->ECPU__DOT__param1 = 0U;
	vlTOPp->ECPU__DOT__param2 = 0U;
    } else {
	vlTOPp->ECPU__DOT__param1 = 0x96U;
	vlTOPp->ECPU__DOT__param2 = 0x96U;
    }
    vlTOPp->led1 = vlTOPp->ECPU__DOT__ADD1__DOT__c[8U];
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__0__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & (((IData)(vlTOPp->ECPU__DOT__param1) 
		  & (IData)(vlTOPp->ECPU__DOT__param2)) 
		 | (vlTOPp->ECPU__DOT__ADD1__DOT__c
		    [0U] & ((IData)(vlTOPp->ECPU__DOT__param1) 
			    ^ (IData)(vlTOPp->ECPU__DOT__param2)))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__1__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 1U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [1U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 1U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__2__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 2U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [2U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 2U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__3__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 3U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [3U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 3U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__4__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 4U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [4U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 4U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__5__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 5U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [5U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 5U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__6__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 6U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [6U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 6U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__7__KET____DOT____Vcellout__add____pinNumber5 
	= (1U & ((((IData)(vlTOPp->ECPU__DOT__param1) 
		   & (IData)(vlTOPp->ECPU__DOT__param2)) 
		  >> 7U) | (vlTOPp->ECPU__DOT__ADD1__DOT__c
			    [7U] & (((IData)(vlTOPp->ECPU__DOT__param1) 
				     ^ (IData)(vlTOPp->ECPU__DOT__param2)) 
				    >> 7U))));
    vlTOPp->ECPU__DOT__ADD1__DOT__c[1U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__0__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[2U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__1__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[3U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__2__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[4U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__3__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[5U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__4__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[6U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__5__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[7U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__6__KET____DOT____Vcellout__add____pinNumber5;
    vlTOPp->ECPU__DOT__ADD1__DOT__c[8U] = vlTOPp->ECPU__DOT__ADD1__DOT__adder_block__BRA__7__KET____DOT____Vcellout__add____pinNumber5;
}

void VECPU::_eval(VECPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_eval\n"); );
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void VECPU::_eval_initial(VECPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_eval_initial\n"); );
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VECPU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::final\n"); );
    // Variables
    VECPU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VECPU::_eval_settle(VECPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_eval_settle\n"); );
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VECPU::_change_request(VECPU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_change_request\n"); );
    VECPU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->ECPU__DOT__ADD1__DOT__c[0U] ^ 
	       vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	       [0U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[1U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [1U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[2U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [2U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[3U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [3U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[4U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [4U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[5U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [5U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[6U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [6U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[7U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [7U])
	 | (vlTOPp->ECPU__DOT__ADD1__DOT__c[8U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
	    [8U]));
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [0U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [0U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [1U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [1U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [2U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [2U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [3U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [3U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [4U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [4U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [5U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [5U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [6U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [6U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [7U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [7U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ECPU__DOT__ADD1__DOT__c
			       [8U] ^ vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c
			       [8U]))) VL_DBG_MSGF("        CHANGE: alu/8/ALUAdd8.v:16\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[0U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[0U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[1U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[1U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[2U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[2U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[3U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[3U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[4U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[4U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[5U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[5U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[6U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[6U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[7U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[7U];
    vlTOPp->__Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[8U] 
	= vlTOPp->ECPU__DOT__ADD1__DOT__c[8U];
    return __req;
}

#ifdef VL_DEBUG
void VECPU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((switch1 & 0xfeU))) {
	Verilated::overWidthError("switch1");}
}
#endif // VL_DEBUG

void VECPU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VECPU::_ctor_var_reset\n"); );
    // Body
    switch1 = VL_RAND_RESET_I(1);
    led1 = VL_RAND_RESET_I(1);
    led2 = VL_RAND_RESET_I(1);
    ECPU__DOT__param1 = VL_RAND_RESET_I(8);
    ECPU__DOT__param2 = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
	    ECPU__DOT__ADD1__DOT__c[__Vi0] = VL_RAND_RESET_I(1);
    }}
    ECPU__DOT__ADD1__DOT__adder_block__BRA__0__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__1__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__2__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__3__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__4__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__5__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__6__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    ECPU__DOT__ADD1__DOT__adder_block__BRA__7__KET____DOT____Vcellout__add____pinNumber5 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<17; ++__Vi0) {
	    ECPU__DOT__ADD2__DOT__c[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
	    __Vchglast__TOP__ECPU__DOT__ADD1__DOT__c[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
