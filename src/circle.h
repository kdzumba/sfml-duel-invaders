#ifndef CIRCLE_H
#define CIRCLE_H

//PREPROCESSOR DIRECTIVES

class Circle
{
public:
    Circle(float rad, float x_cent, float y_cent);
    bool intersects(const Circle& other_circle) const;
    void move(float x, float y); // ensures that circle object always moves with sprite
    float centerX()const{return x_center;} //inline functions
    float centerY()const{return y_center;}

private:
    float radius;
    float x_center;
    float y_center;
};
#endif