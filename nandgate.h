#ifndef GATE_H
#define GATE_H

#include <systemc.h>

SC_MODULE(gate)
{
    // Inputs and Outputs for the gates
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> D;  
    

    // Internal signals for intermediate results
    sc_signal<bool> or_result;
    

    // Constructor
    SC_CTOR(gate) : A("A"), B("B"), C("C"),or_result("or_result")
    {
        // Define AND gate behavior
        SC_METHOD(do_and);
        sensitive << D << B;

        // Define OR gate behavior
        SC_METHOD(do_or);
        sensitive << and_result << A;
    }

    // AND gate behavior
    void do_and()
    {
        C.write(and_result.read() && !A.read()); // Output of the AND gate feeds into the OR gate
        D = C;
    }

    // OR gate behavior
    void do_or()
    {
        or_result.write(C.read() || B.read());
    }
};

#endif