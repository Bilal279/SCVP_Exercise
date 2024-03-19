class memory : sc_module, tlm::tlm_fw_transport_if<>
{
    private:
    unsigned char mem[memory_size];

    public:
    tlm::tlm_target_socket<> tSocket;

    SC_CTOR(memory) : tSocket("tSocket")
    {
        tSocket.bind(*this);
    }
