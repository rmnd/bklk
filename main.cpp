#include "bklk.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	int fg = 7, rows, cols;
	int ch;
	cursesInit();
	binclock* clk = new binclock(fg,-1,LINES,COLS,"full");
	while(ch != 'q') {
		ch = getch();
		if(ch == 'c'){
			fg = (fg + 1)%8;
			clk->updateColors(fg,-1);	
			continue;
		}
		clk->updateTime();
		clk->drawTime();
		usleep(50000);
	}
	delete clk;
	endwin();
}
