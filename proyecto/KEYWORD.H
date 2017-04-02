extern "C"
{
    struct tokenRead{
        char* word;
        int type; 
    }
    struct tokenRead tomaToken(char * &input);
    int inWindow (struct tokenRead token);
    void selectAction(void);
    void cleanScreen();
    void isKeyPress();
}
