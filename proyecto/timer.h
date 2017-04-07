#ifdef __cplusplus
    #define __CPPARGS ...
#else
    #define __CPPARGS
#endif
extern "C"
{
	void interrupt handler(__CPPARGS);
	void startClock(void);
	void stopClock(void);
	int getTimer(void);
	void resetTimer(void);
}
