#ifndef _RENDER_H_
#define _RENDER_H_

#include <ncurses.h>

class Render {
public:
	Render(int width, int height);
	~Render();

	void put(int x, int y, char c);
	char& at(int x, int y);
	void beginFrame();
	void draw();

	WINDOW* mWin;
	char* mScreen;
	int mWidth;
	int mHeight;
};

#endif