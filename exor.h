#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor)
{
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;
    nand nandA, nandB, nandC, nandD;
    sc_signal<bool> h1, h2, h3;

    SC_CTOR(exor): nandA("nandA"), nandB("nandB"),
    nandC("nandC"), nandD("nandD"), A("A"), B("B"),
    Z("Z"), h1("h1"), h2("h2"), h3("h3")
    {
        nandA.A.bind(A);
        nandA.B.bind(B);
        nandA.Z.bind(h1);

        nandB.A.bind(h1);
        nandB.B.bind(B);
        nandB.Z.bind(h3);

        nandC.A.bind(A);
        nandC.B.bind(h1);
        nandC.Z.bind(h2);

        nandD.A.bind(h2);
        nandD.B.bind(h3);
        nandD.Z.bind(Z);
    }
};

#endif // EXOR_H
