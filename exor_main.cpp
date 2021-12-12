#include <systemc.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char**)
{
    sc_clock clock("clk", 10, SC_NS, 0.5);

    sc_signal<bool> sigA, sigB, sigZ;

    stim Stim1("Stimulus");
    Stim1.Clk(clock);
    Stim1.A(sigA);
    Stim1.B(sigB);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.Clk(clock);
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);

    //Setup Waveform Tracing
    sc_trace_file *wf = sc_create_vcd_trace_file("trace");
    sc_trace(wf, sigA, "A");
    sc_trace(wf, sigB, "B");
    sc_trace(wf, sigZ, "Z");
    sc_trace(wf, clock, "Clk");

    sc_start();  // run forever

    sc_close_vcd_trace_file(wf);

    return 0;
}
