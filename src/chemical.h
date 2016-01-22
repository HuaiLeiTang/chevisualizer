#ifndef CHEMICAL_H
#define CHEMICAL_H
#include <QString>
#include <QFile>
#include "atom.h"

class Chemical
{
public:
    Chemical(); //< initialization
    ~Chemical(); //< destructor
    bool create(QString filename); //< creates chemical formula model from lewis structure stored in the given filename
    bool render(); //< displays the chemical formula
    bool rotate(float theta, float phi); //< rotates the 3d stage
    bool setEyePostion(float x, float y, float z); //< the position of viewer
    bool addLightSource(float x, float y, float z, float intensity);//< adding light source with given intensity
    bool createJpeg(QString filename); //< creates jpeg file in the at the given location
    bool createGif(QString filename, int type); //< creates gif file

private:
    struct point{
        float x;
        float y;
        float z;
    };
    struct point center; //< molecules center
    struct point eyeposition; //< position of eye
    float scale; //< scaling ratio
    QFile

    bool calculatePosition(); //< calculates the position of each atom in the chemical formula
    bool calculateCenter(); //< center of mass
};

#endif // CHEMICAL_H
