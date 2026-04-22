#include "GlobalVariables.h"
#include "chai3d.h"

class BlockSetup
{
public:
    static cMultiMesh *newSimpleBlock(const char textureName[]);
    static cMultiMesh *newTopBlock(const char textureName[]);
    static cMultiMesh *newFullBlock(const char textureName[]);

private:
    static cTexture2dPtr newTexture(const char textureName[]);
    static cTexture2dPtr newMersTexture(const char textureName[]);
    static cMultiMesh *newBlock(const char textureName[], const char loadPath[]);
};

cMultiMesh *BlockSetup::newSimpleBlock(const char textureName[])
{
    return newBlock(textureName, "./Models/Block_simple.obj");
}

cMultiMesh *BlockSetup::newTopBlock(const char textureName[])
{
    return newBlock(textureName, "./Models/Block_top_and_bottom.obj");
}

cMultiMesh *BlockSetup::newFullBlock(const char textureName[])
{
    return newBlock(textureName, "./Models/Block_full_sides.obj");
}

cMultiMesh *BlockSetup::newBlock(const char textureName[], const char loadPath[])
{
    cMultiMesh *simple_cube;
    simple_cube = new cMultiMesh();

    // load an object file
    bool fileload = simple_cube->loadFromFile(loadPath);
    if (!fileload)
    {
        std::cout << "Error - 3D Model failed to load correctly" << std::endl;
    }

    // resize object to screen
    simple_cube->scale(block_scale);

    simple_cube->m_material->setWhite();
    simple_cube->setUseTexture(true, true);
    simple_cube->setUseMaterial(true, true);
    // disable culling so that faces are rendered on both sides
    // simple_cube->setUseCulling(false);

    // compute a boundary box
    simple_cube->computeBoundaryBox(true);
    // show/hide boundary box
    simple_cube->setShowBoundaryBox(false);

    // compute collision detection algorithm
    simple_cube->createAABBCollisionDetector(toolRadius);

    // enable display list for faster graphic rendering
    simple_cube->setUseDisplayList(true);

    // center object in scene
    simple_cube->setLocalPos(-1.0 * simple_cube->getBoundaryCenter());

    // rotate object in scene
    // simple_cube->rotateExtrinsicEulerAnglesDeg(0, 0, 90, C_EULER_ORDER_XYZ);

    // compute all edges of object for which adjacent triangles have more than 40 degree angle
    simple_cube->computeAllEdges(0);

    simple_cube->setTexture(BlockSetup::newTexture(textureName));

    return simple_cube;
}

cTexture2dPtr BlockSetup::newTexture(const char textureName[])
{
    cTexture2dPtr texture = cTexture2d::create();
    char path[256];
    snprintf(path, sizeof(path), "./Textures/%s.png", textureName);

    bool fileload = texture->loadFromFile(path);
    if (!fileload)
    {
        std::cout << "Error - Texture failed to load correctly" << std::endl;
    }

    // set filtering to nearest neighbor
    texture->setMagFunction(GL_NEAREST);
    texture->setMinFunction(GL_NEAREST);
    return texture;
}

    // set filtering to nearest neighbor
    texture->setMagFunction(GL_NEAREST);
    texture->setMinFunction(GL_NEAREST);
    return texture;
}
