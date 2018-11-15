#ifndef _INPUT_H_
#define _INPUT_H_

class Input {
public:
    Input();

    void read();
    char get();
    
private:
    char mInputChar;
};

#endif