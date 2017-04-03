extern "C"
{
    struct tokenRead{
        char* word;
        int type; 
	int num;
	char* pointer;
    };
    struct structComand{
	int type;
	int window;
	int quantum;
	int stats;
    };
    struct tokenRead tomaToken(char *input);
    int inWindow (struct tokenRead token);
    struct structComand selectAction(void);
    void cleanScreen();
    struct structComand isKeyPress();
}
