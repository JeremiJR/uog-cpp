#include <iostream>
#include <ncurses.h>
using namespace std;

int main() {

    int width, height, start_y, start_x, l, r, t, b, tlc, trc, blc, brc;   
    cout << "Enter the width of the box: ";
    cin >> width;
    cout << "Your width is:\n"<< width << "\nEnter a height for the box: ";
    cin >> height;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    char wall = '|';
    char c = '+';
    char ro = '-';
    
    tlc = trc = brc = blc = c;
    t = b = ro;
    l = r = wall;

    start_y = start_x = 5;

    WINDOW * win = newwin(height+2, width+2, start_y, start_x);
    keypad(win, TRUE);
    wborder(win, l, r, t, b, tlc, trc, blc, brc);
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            mvwaddch(win, i, j, '.');
        }
    }

    int py = 1, px = 1;
    bool game = true;

    while (game) {
        mvwaddch(win, py, px, '@');
        wrefresh(win);

        int ch = wgetch(win);

        mvwaddch(win, py, px, '.');

        switch (ch) {
            case KEY_UP:    if (py > 1) py--; break;
            case KEY_DOWN:  if (py < height) py++; break;
            case KEY_LEFT:  if (px > 1) px--; break;
            case KEY_RIGHT: if (px < width) px++; break;
            case 'q':       game = false; break;
        }
    }


    endwin();
    return 0;
}