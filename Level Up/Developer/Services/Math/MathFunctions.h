#ifndef __MATHFUNCTIONS_H
#define __MATHFUNCTIONS_H

#include "DataTypes.h"

namespace LevelUp
{
    /*
    All existing Level Up engine Math functions used for Level Up math
    Alex Sabourin
    */


    //Local constants
    const float GRAVITY_CONSTANT = 1000.0f;

    //Forward Declaration
	class BaseLevelObject;

    class MathHelper
    {
    public:
        //Conveniance method to convert from degrees to radians
        static float DegreesToRadians(float degrees);

        //Conveniance method to convert from radians to degrees
        static float RadiansToDegrees(float radians);

        //Increases an angle (in degrees) and ensures it remains between 0-360
        static float IncreaseAngle(float angle, float increment);

        //Decreases an angle (in degrees) and ensures it remains between 0-360
        static float DecreaseAngle(float angle, float increment);

        //Method to calculate the y position based on a x position, wave length
        //peak amplitude and period of a sine wave
        static float SineAmplitudeForX(float x, float wavelength, float peakAmplitude, float period);

        //Clamps a value between the min and max range
        static float Clamp(float value, float min, float max);

        //Accelerate's a value in one dimension, takes into account drag
        static float Accelerate(float speed, float acceleration, float drag, double delta);

        //Calculates the velocity vector based on an angle (in degrees) and a speed
        static LVLfloat2 CalculateVelocity(float angle, float speed);

        //Translates a GameObject by the velocity amount
		static void Translate(BaseLevelObject* gameObject, LVLfloat2 velocity, double delta);

        //Orbits a GameOjbect around a pivot point at a given radius away for a given angle
		static void Orbit(BaseLevelObject* gameObject, float radius, float angle, LVLfloat2 pivot);

        //Function that calculates the distance between two points
        static float Distance(LVLfloat2 a, LVLfloat2 b);

        //Function to calculate the length of a vector
        static float Length(LVLfloat2 a);

        //Function that normalizes a vector
        static LVLfloat2 Normalize(LVLfloat2 a);

        //Function to calculate the angle between two vectors
        static float AngleBetweenVectors(LVLfloat2 a, LVLfloat2 b);

        //Function to apply the universal gravition equation between two game objects. Object B should be the heavier object
		static void ApplyGravityForce(BaseLevelObject* a, float massA, BaseLevelObject* b, float massB, float radiusB, double delta);

        //Function to calculate the universal gravition force between two objects
        static LVLfloat2 ComputeGravitationalForce(LVLfloat2 a, float massA, LVLfloat2 b, float massB, float distance);

        //*NEW* Randomize the random number seed using time
        static void RandomizeSeed();

        //*NEW* Generate a random number between zero and the max number
        static unsigned int RandomNumber(unsigned int max);

        //*NEW* Generate a random number between the min and max range
        static unsigned int RandomRange(unsigned int min, unsigned int max);

        //Check if a line and a circle collide
        static bool lineToCircleCollision(LVLfloat2 linePointA, LVLfloat2 linePointB, LVLfloat2 circlePos, float circleRadius);

        //check if a circle and a circle collide
        static bool circleToCircleCollision(LVLfloat2 positionA, float radiusA, LVLfloat2 positionB, float radiusB);

		//check if a square collides with a square
		static bool rectangleToRectangleCollision(LVLrect rectA, LVLrect rectB);

        //row major (can be changed by adapter)
        static LVL4X4matrix translationMatrix2D(LVLfloat2 f);
        static LVL4X4matrix translationMatrix3D(LVLfloat3 f);

        static LVL4X4matrix zRotationMatrix(LVLfloat z);
        static LVL4X4matrix xRotationMatrix(LVLfloat x);
        static LVL4X4matrix yRotationMatrix(LVLfloat y);

        static LVL4X4matrix scalingMatrix2D(LVLfloat2 scale);
        static LVL4X4matrix scalingMatrix3D(LVLfloat3 scale);

        static LVL4X4matrix identityMatrix();

        //get a factorial value
        static LVLfloat factorial(unsigned int digit);

        //get the power of a base value
        static LVLfloat power(LVLfloat base, int exponant);
    };

}


#endif