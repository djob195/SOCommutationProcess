#ifndef __RENDERKERNEL_H__
#define __RENDERKERNEL_H__
extern "C"
{
class RenderKernel{
public:
    static void paint (int x, int y);
    static void paintLine(int x1, int x2, int y1, int y2);
    RenderKernel();
    static void blink(int x, int y);
    int getFreeSpaceX();
    int getFreeSpaceY();
    int getWindows(int x, int y);
};
}
#endif