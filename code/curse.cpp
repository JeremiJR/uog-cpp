#include <iostream>
#include <ncurses.h>
using namespace std;

string walls(int w, int h) {
        string box = "+" + string(w, '-') + "+\n";
        for (int i = 0; i < h; i++) {
        box += "|" + string(w, '.') + "|\n";
    }
    box += "+" + string(w, '-') + "+\n";
    return box;
}
int main() {

    int width, height, start_y, start_x, h, w, left, right, top, bottom, tlc, trc, blc, brc;   
    cout << "Enter the width and height of the box: ";
    cin >> width;
    cout << "Your width is:\n"<< width << "\nEnter a height for the box: ";
    cin >> height;
    h = w = 30;

    initscr();
    cbreak();
    char wall = '|';
    char c = '+';
    char r = '-';
    tlc = trc = blc = brc = (int)c;
    left = right = (int)wall;
    bottom = top = (int)r;
    
    start_y = start_x = 10;

    WINDOW * win = newwin(h, w, start_y, start_x);
    refresh();

    wborder(win , left, right, top, bottom, tlc, trc, blc, brc);
    mvwprintw(win, 1, 1, walls(width, height).c_str());
    wrefresh(win);

    getch();

    endwin();
    return 0;
}