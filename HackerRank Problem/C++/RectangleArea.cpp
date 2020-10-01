#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{
    int height;
    int width;
    public:
    Rectangle()
    {
        height=0;
        width=0;
    }
    Rectangle(int height, int width)
    {
        this->height=height;
        this->width=width;
    }
    void display()
    {
        cout << this->width << " " << this->height << endl;
    }
    void set_height(int height)
    {
        this->height=height;
    }
    void set_width(int width)
    {
        this->width=width;
    }
    int get_height()
    {
        return height;
    }
    int get_width()
    {
        return width;
    }
};

class RectangleArea : public Rectangle
{
    public:
    void read_input()
    {
        int height,width;
        cin >> width >> height;
        set_height(height);
        set_width(width);
    }

    void display()
    {
        cout << get_height() * get_width();
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}