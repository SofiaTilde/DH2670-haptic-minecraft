#include "BlockSetup.h"

class Blocks
{
public:
    static cMultiMesh *dirtBlock()
    {
        cMultiMesh *block = BlockSetup::newSimpleBlock("dirt");

        // define a default stiffness for the object
        block->setStiffness(0.2 * maxStiffness);

        // define some haptic friction properties, First argument is Static Friction, Second is Dynamic Friction
        block->setFriction(0.1, 0.2);

        return block;
    }
    static cMultiMesh *grassBlock()
    {
        cMultiMesh *block = BlockSetup::newTopBlock("grass");

        // define a default stiffness for the object
        block->setStiffness(0.2 * maxStiffness);

        // define some haptic friction properties, First argument is Static Friction, Second is Dynamic Friction
        block->setFriction(0.1, 0.2);

        return block;
    }
    static cMultiMesh *crafterBlock()
    {
        cMultiMesh *block = BlockSetup::newFullBlock("crafter");

        // define a default stiffness for the object
        block->setStiffness(0.2 * maxStiffness);

        // define some haptic friction properties, First argument is Static Friction, Second is Dynamic Friction
        block->setFriction(0.1, 0.2);

        return block;
    }
};