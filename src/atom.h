#ifndef ATOM_H
#define ATOM_H

class Atom
{
public:
    Atom(); //< constructor
    Atom(char symbol[], float scale); //< creates the atom
    ~Atom(); //< destructor
    bool setSymbol(char symbol[]);//< sets atom symbol
    bool setScale(float scale);//< sets the scale
    bool setColor(char color[]); //< sets colorname
    bool setColor(int color); //<sets hex color
private:
    bool calRadiusPixel(float radius); // calculates radius pixel
    char symbol[3]; //< chemical symbol of atom
    static float scale; //< scale
    char color[10]; //< color name
    int hexcolor; //< color in hex
    float radius; //< radius of the atom
    int radiusPixel; //< radius in Pixel
};

#endif // ATOM_H
