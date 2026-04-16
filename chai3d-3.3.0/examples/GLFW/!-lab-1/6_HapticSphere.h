#ifndef HAPTICSPHERE_H
#define HAPTICSPHERE_H

#include "Assignment.h"

#include "chai3d.h"

class HapticSphere : public Assignment
{
private:
    // A 3D cursor for the haptic device
    cShapeSphere* m_cursor;
    cShapeSphere* sphereWall;

    // Material properties used to render the color of the cursors
    cMaterialPtr m_matCursorButtonON;
    cMaterialPtr m_matCursorButtonOFF;
    cMaterialPtr sphereMaterial;

public:
    virtual std::string getName() const { return "6: Haptic Sphere"; }

	virtual void initialize(cWorld* world, cCamera* camera);
	virtual void updateGraphics();
	virtual void updateHaptics(cGenericHapticDevice* hapticDevice, double timeStep, double totalTime);
};

void HapticSphere::initialize(cWorld* world, cCamera* camera)
{
	//Change the background
	world->setBackgroundColor(0.2f, 0, 0.31f);

	// Create a cursor with its radius set
	m_cursor = new cShapeSphere(0.01);
	// Add cursor to the world
	world->addChild(m_cursor);

	// Here we define the material properties of the cursor when the
	// user button of the device end-effector is engaged (ON) or released (OFF)

    // A light orange material color
    m_matCursorButtonOFF = cMaterialPtr(new cMaterial());
    m_matCursorButtonOFF->m_ambient.set(0.5, 0.2, 0.0);
    m_matCursorButtonOFF->m_diffuse.set(1.0, 0.5, 0.0);
    m_matCursorButtonOFF->m_specular.set(1.0, 1.0, 1.0);

    // A blue material color
    // A light orange material color
    m_matCursorButtonON = cMaterialPtr(new cMaterial());
    m_matCursorButtonON->m_ambient.set(0.1, 0.1, 0.4);
    m_matCursorButtonON->m_diffuse.set(0.3, 0.3, 0.8);
    m_matCursorButtonON->m_specular.set(1.0, 1.0, 1.0);

    // Apply the 'off' material to the cursor
    m_cursor->m_material = m_matCursorButtonOFF;

    sphereWall = new cShapeSphere(0.05);
    world->addChild(sphereWall);

    sphereMaterial = cMaterialPtr(new cMaterial());
    sphereMaterial->m_ambient.set(255/255, 41/255, 248/255);
    sphereMaterial->m_diffuse.set(0.3, 0.3, 0.8);
    sphereMaterial->m_specular.set(0.5, 0.5, 0.5);
    sphereWall->m_material = sphereMaterial;

}

void HapticSphere::updateGraphics()
{

}

void HapticSphere::updateHaptics(cGenericHapticDevice* hapticDevice, double timeStep, double totalTime)
{
	//Read the current position of the haptic device
	cVector3d newPosition;
	hapticDevice->getPosition(newPosition);

    // update global variable for graphic display update
    hapticDevicePosition = newPosition;

	// Update position and orientation of cursor
    m_cursor->setLocalPos(newPosition);

	cVector3d force(0, 0, 0);
	//Set a force to the haptic device

    if (newPosition.length() < (0.05 + 0.01))
    {
        float length = newPosition.length();

        newPosition.normalize();
        double k = -1.5 / (.01);
        force=k*newPosition*(length-(0.05 + 0.01));

        cVector3d proxyPos;
        proxyPos = (0.05 + 0.01)*newPosition;
        m_cursor->setLocalPos(proxyPos);
    }



    if (force.x() < -1.5) {
        force.x(-1.5);
    }
    else if (force.x() > 1.5) {
        force.x(1.5);
    }
    if (force.y() < -1.5) {
        force.y(-1.5);
    }
    else if (force.y() > 1.5) {
        force.y(1.5);
    }
    if (force.z() < -1.5) {
        force.z(-1.5);
    }
    else if (force.z() > 1.5) {
        force.z(1.5);
    }

	hapticDevice->setForce(force);
}
#endif

