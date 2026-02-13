#include <iostream>
using namespace std;

void walls(int w, int h){
    cout << "+" << string(w, '-') << "+" << endl;
    for (int i = 0; i < h; i++) {
        cout << "|" << string(w, '.') << "|" << endl;
    }
    cout << "+" << string(w, '-') << "+" << endl;
}
int main(){

    // This part that makes the box.
    int width;
    int height;
    cout << "Enter the width and height of the box: ";
    cin >> width;
    cout << "Your width is:\n"<< width << "\nEnter a height for the box: ";
    cin >> height;
    walls(width, height);
    // This part will be the person in the game.
    
    return 0;
}