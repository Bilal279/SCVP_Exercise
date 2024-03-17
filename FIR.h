SC_MODULE(FIR)
{
    sc_in<bool> in;
    sc_signal<bool> r1;
    sc_signal<bool> r2;
    sc_signal<bool> r3;
    sc_out<bool> out;
    sc_clk<bool> Clk;
    sc_in<bool> reset

    SC_CTOR(FIR) : in("in"), Clk("Clk"), out("out"),reset("reset"),r1("r1"),r2("r2"),r3("r3")
    {
        SC_METHOD(conbinational);
        sensitive << r1 << r2 << r3;
        SC_METHOD(sequential);
        sensitive << Clk.pos();
    }

    void combinational()
    {
        r3 = r2;
        r2 = r1;
        r1 = in;
    }
    void sequential()
    {
        if(reset == 1)
        {
            r1, r2, r3 = 0;
        }
        else
        {
            out = (in + r1 + r2 + r3)/4;
        }
    }
};