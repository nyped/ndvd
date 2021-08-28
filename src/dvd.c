#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "dvd.h"

static void
print_box(int x, int y)
{
	mvwprintw(stdscr, y + 0, x, "+-----+");
	mvwprintw(stdscr, y + 1, x, "| DVD |");
	mvwprintw(stdscr, y + 2, x, "+-----+");
}

static void
set_color(void)
{
	init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

static void
set_curses(void)
{
	initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	start_color();
	noecho();
	curs_set(0);
	refresh();
	set_color();
}

void
draw(int color, int startx, int starty, int dx, int dy, int rainbow, int speed, int corner)
{
	char c = ERR;
	int res = 0;

	set_curses();
	attron(COLOR_PAIR(color));

	while (1) {
		print_box(startx, starty);
		refresh();

		if (dx == RIGHT) {
			if ((startx + 8) > COLS) {
				dx = LEFT;
				res++;
			}
		} else {
			if ((startx - 1) < 0) {
				dx = RIGHT;
				res++;
			}
		}

		if (dy == DOWN) {
			if ((starty + 4) > LINES) {
				dy = UP;
				res++;
			}
		} else {
			if ((starty - 1) < 0) {
				dy = DOWN;
				res++;
			}
		}

		if (corner && res == 2) {
			nodelay(stdscr, FALSE);
			c = getch();
			break;
		}

		if (rainbow == 1 && res == 1) {
			color = ((++color == 8)? 0 : color);
			attron(COLOR_PAIR(color));
		}

		res = 0;
		starty += dy;
		startx += dx;

		if ((c = getch()) == 'q')
			break;

		usleep(speed);
		werase(stdscr);
	}

	endwin();
}
