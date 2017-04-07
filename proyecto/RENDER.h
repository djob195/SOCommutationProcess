#ifndef __RENDERKERNEL_H__
#define __RENDERKERNEL_H__
extern "C"
{
    struct pointPCB{
        int x;
        int y;
        int z;
        int error;
    }
    class RenderKernel{
    public:
        static void paint (int x, int y);
        static void paintLine(int x1, int x2, int y1, int y2);
        RenderKernel();
        static void blink(int x, int y);
        int getFreeSpaceX();
        int getFreeSpaceY();
        struct pointPCB getWindows(int x, int y);
    };
}
#endif