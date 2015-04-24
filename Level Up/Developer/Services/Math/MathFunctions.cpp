#include "MathFunctions.h"
#include "../../Base Class/GameObject.h"
#include <random>
#include <ctime>
#include <math.h>

namespace LevelUp
{
    LVL4X4matrix MathHelper::translationMatrix2D(LVLfloat2 f)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[3][0] = f.x;
        mat[3][1] = f.y;
        mat[3][2] = 0.0f;
        return mat;
    }
    LVL4X4matrix MathHelper::translationMatrix3D(LVLfloat3 f)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[3][0] = f.x;
        mat[3][1] = f.y;
        mat[3][2] = f.z;
        return mat;
    }

    LVL4X4matrix MathHelper::zRotationMatrix(LVLfloat z)
    {
        LVL4X4matrix mat = identityMatrix();
        float angle = z.x;
        mat[0][0] = cosf(angle);
        mat[0][1] = sinf(angle);
        mat[1][0] = -sinf(angle);
        mat[1][1] = cos(angle);
        return mat;
    }
    LVL4X4matrix MathHelper::xRotationMatrix(LVLfloat x)
    {
        LVL4X4matrix mat = identityMatrix();
        float angle = x.x;
        mat[1][1] = cosf(angle);
        mat[1][2] = sinf(angle);
        mat[2][1] = -sinf(angle);
        mat[2][2] = cos(angle);
        return mat;
    }
    LVL4X4matrix MathHelper::yRotationMatrix(LVLfloat y)
    {
        LVL4X4matrix mat = identityMatrix();
        float angle = y.x;
        mat[0][0] = cosf(angle);
        mat[0][2] = sinf(angle);
        mat[2][0] = -sinf(angle);
        mat[2][2] = cos(angle);
        return mat;
    }

    LVL4X4matrix MathHelper::scalingMatrix2D(LVLfloat2 scale)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[0][0] = scale.x;
        mat[1][1] = scale.y;
        return mat;
    }
    LVL4X4matrix MathHelper::scalingMatrix3D(LVLfloat3 scale)
    {
        LVL4X4matrix mat = identityMatrix();
        mat[0][0] = scale.x;
        mat[1][1] = scale.y;
        mat[2][2] = scale.z;
        return mat;
    }

    LVL4X4matrix MathHelper::identityMatrix()
    {
        LVL4X4matrix mat;
        for (int i = 0; i < 4; i++)
        {
            mat[i][i] = 1.0f;
        }
        return mat;
    }

    LVLfloat MathHelper::factorial(unsigned int digit)
    {
        LVLfloat total = digit;
        if (digit == 1)
        {
            return 1;
        }
        for (int i = digit - 1; i > 1; i--)
        {
            total *= i;
        }
        return total;
    }
    LVLfloat MathHelper::power(LVLfloat base, int exponant)
    {
        LVLfloat total = 0.0f;
        if (exponant == 0)
        {
            return 1.0f;
        }
        else if (exponant == 1)
        {
            return base;
        }
        total = base;
        for (int i = 1; i < exponant; i++)
        {
            total *= base;
        }
        return total;
    }
    float MathHelper::DegreesToRadians(float degrees)
    {
        return degrees * std::_Pi / 180.0f;

    }

    float MathHelper::RadiansToDegrees(float radians)
    {
        return radians * 180.0f / std::_Pi;
    }

    float MathHelper::IncreaseAngle(float angle, float increment)
    {
        angle += increment;
        if (angle > 360.0f)
        {
            angle -= 360.0f;
        }
        return angle;
    }

    float MathHelper::DecreaseAngle(float angle, float increment)
    {
        angle -= increment;
        if (angle < 0.0f)
        {
            angle += 360.0f;
        }
        return angle;
    }

    float MathHelper::SineAmplitudeForX(float x, float wavelength, float peakAmplitude, float period)
    {
        return sinf(period * (std::_Pi * 2.0f) + (x / wavelength)) * peakAmplitude;
    }

    float MathHelper::Clamp(float value, float min, float max)
    {
        return fminf(max, fmaxf(min, value));
    }

    float MathHelper::Accelerate(float speed, float acceleration, float drag, double delta)
    {
        //Clamp the drag between 0 and 1
        drag = Clamp(drag, 0.0f, 1.0f);

        //Calculate the drag percentage
        float d = acceleration != 0.0f ? (acceleration - (acceleration * drag)) / acceleration : -drag;

        //Apply the acceleration
        return speed + acceleration + (speed * d) * powf(delta, 0.5f);
    }

    LVLfloat2 MathHelper::CalculateVelocity(float angle, float speed)
    {
        float angleRadians = DegreesToRadians(angle);
        float vX = cosf(angleRadians) * speed;
        float vY = sinf(angleRadians) * speed;
        return LVLfloat2(vX, vY);
    }

    void MathHelper::Translate(GameObject* gameObject, LVLfloat2 velocity, double delta)
    {
        LVLfloat2 position = gameObject->getPosition();
        position += LVLfloat2(velocity.x * delta, velocity.y * delta);
        gameObject->setPosition(position);
    }

    void MathHelper::Orbit(GameObject* gameObject, float radius, float angle, LVLfloat2 pivot)
    {
        float angleRadians = DegreesToRadians(angle);
        float x = (pivot.x + radius * cosf(angleRadians));
        float y = (pivot.y + radius * sinf(angleRadians));
        gameObject->setPosition(x, y);
    }

    float MathHelper::Distance(LVLfloat2 a, LVLfloat2 b)
    {
        float distance = sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
        return distance;
    }

    float MathHelper::Length(LVLfloat2 a)
    {
        return Distance(LVLfloat2(0.0f, 0.0f), a);
    }

    LVLfloat2 MathHelper::Normalize(LVLfloat2 a)
    {
        //Get the length
        float length = Length(a);

        //Avoid divide by zero
        if (length > 0)
        {
            return a / length;
        }
        return LVLfloat2(0.0f, 0.0f);
    }

    float MathHelper::AngleBetweenVectors(LVLfloat2 a, LVLfloat2 b)
    {
        float adjacent = a.x - b.x;
        float opposite = a.y - b.y;
        float angleRadians = atan2f(opposite, adjacent);
        return RadiansToDegrees(angleRadians);
    }

    void MathHelper::ApplyGravityForce(GameObject* a, float massA, GameObject* b, float massB, float radiusB, double delta)
    {
        //Calculate the distance between the two game objects
        float distance = MathHelper::Distance(a->getPosition(), b->getPosition());

        //If the distance is greater than the desired radius, apply the universal gravitation equation
        if (distance > radiusB)
        {
            //Compute the Gravitational Force
            LVLfloat2 velocityDueToGravity = ComputeGravitationalForce(a->getPosition(), massA, b->getPosition(), massB, distance);

            //Translate game object a, based on the velocity vector
            MathHelper::Translate(a, velocityDueToGravity, delta);
        }
    }

    LVLfloat2 MathHelper::ComputeGravitationalForce(LVLfloat2 a, float massA, LVLfloat2 b, float massB, float distance)
    {
        //Calculate the gravity force based on the unverisal gravitation equation
        float gravityForce = GRAVITY_CONSTANT * massA * massB / (distance * distance);

        //Calculate the acceleration due to gravity based on the force of gravity and object a's mass
        float gravityAcceleration = gravityForce / massA;

        //Calculate the angle between the two game objects
        float angleBetweenMissileAndPlanet = MathHelper::AngleBetweenVectors(a, b);

        //Using the angle and the acceleration due to gravity calculate the velocity vector for gravity
        LVLfloat2 velocityDueToGravity = MathHelper::CalculateVelocity(angleBetweenMissileAndPlanet, gravityAcceleration);
        velocityDueToGravity *= -1.0f;

        return velocityDueToGravity;
    }

    void MathHelper::RandomizeSeed()
    {
        srand(time(nullptr));
    }

    unsigned int MathHelper::RandomNumber(unsigned int max)
    {
        return (rand() % max);
    }

    unsigned int MathHelper::RandomRange(unsigned int min, unsigned int max)
    {
        return min + RandomNumber(max - min);
    }

    bool MathHelper::lineToCircleCollision(LVLfloat2 linePointStop, LVLfloat2 linePointStart, LVLfloat2 circlePos, float circleRadius)
    {
        LVLfloat2 circleV = circlePos - linePointStart;

        LVLfloat2 lineV = linePointStop - linePointStart;

        LVLfloat2 normalLineV = MathHelper::Normalize(lineV);

        float dot = circleV.x * normalLineV.x + circleV.y * normalLineV.y;

        LVLfloat2 projection = normalLineV * dot;

        LVLfloat2 closestPoint = projection + linePointStart;

        //this code is added to limit the distance of the ray cast to the lasers length.
        if (dot <= 0)
        {
            closestPoint = linePointStart;
        }
        else if (dot >= MathHelper::Length(lineV))
        {
            closestPoint = linePointStop;
        }


        float d = MathHelper::Distance(closestPoint, circlePos);

        return d <= circleRadius;

    }
    bool MathHelper::circleToCircleCollision(LVLfloat2 positionA, float radiusA, LVLfloat2 positionB, float radiusB)
    {
        float distance = ((positionB.x - positionA.x) * (positionB.x - positionA.x) + (positionB.y - positionA.y) * (positionB.y - positionA.y));

        if (distance < (radiusA + radiusB) * (radiusA + radiusB))
        {
            return true;
        }
        return false;
    }
}