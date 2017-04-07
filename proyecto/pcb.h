extern "C"
{
    class PCB
    {
    public:
        int screenPcb [24][20]
        PCB(int id);
        int Live;
        int Play;
        int ID;
        int Quantum;
        int posx;
        int posy:
        int nowCaracter;
        void locate(int x, int y);
        void paint(int x, int y, char caracter);
        void painted(int x, int y, char caracter);
        int isLive();
        int isPlay();
        int isWork();
        void clean();
        void execute();
        void setQuantum(int quantum);
    };

}
