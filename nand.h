#ifndef NAND_H
#define NAND_H

#include <systemc.h>


// TODO: Insert your code here

SC_MODULE(nand)
{
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    SC_CTOR(nand) : A("A"), B("B"), Z("Z")
    {
        SC_METHOD(do_nand);
        sensitive << A << B;
    }

    void do_nand()
    {
        Z.write( !( A.read() && B.read() ) );
        //std::cout << "Executing do_nand:" << " simulation time " << sc_time_stamp().to_default_time_units() << " ps Δ cycle " << sc_delta_count() << ":\tA " << (A.read() ? "'1'" : "'0'") << " B " << (B.read() ? "'1'" : "'0'") << " Z " << (Z.read() ? "'1'" : "'0'") << std::endl;
    }
};

#endif
