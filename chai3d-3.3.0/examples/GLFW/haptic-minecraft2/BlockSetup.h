#include "GlobalVariables.h"
#include "chai3d.h"

class BlockSetup
{
public:
    static cBulletBox *newSimpleBlock(const char textureName[]);
    static cBulletBox *newTopBlock(const char textureName[]);
    static cBulletBox *newFullBlock(const char textureName[]);
    static void requiredBlock(cBulletBox *block);

    static cBulletBox *test()
    {
        cBulletBox *block = new cBulletBox(bulletWorld, box_scale, box_scale, box_scale);

        block->setShowEnabled(false, true); // hide the box visuals
        // block->setStiffness(0.3 * maxStiffness);
        block->setFriction(0.6, 0.6);

        block->setMass(0.05);

        // estimate their inertia properties
        block->estimateInertia();

        // create dynamic models
        block->buildDynamicModel();

        // create collision detector for haptic interaction
        block->createAABBCollisionDetector(toolRadius);

        // set friction values
        block->setSurfaceFriction(0.4);

        // set position of each cube
        block->setLocalPos(0.0, 0.0, 0.5);

        block->m_material->setWhite();
        block->setUseMaterial(true, true);
        block->m_material->setStiffness(0.3 * maxStiffness);

        cMultiMesh *aa = newMesh("dirt", "./Models/Block_simple.obj");
        // aa->setUseDisplayList(true); // optional
        aa->setUseTransparency(false);

        block->addChild(aa);

        bulletWorld->computeBoundaryBox(true);

        return block;
    }

private:
    static cTexture2dPtr newTexture(const char textureName[]);
    static cTexture2dPtr newMersTexture(const char textureName[]);
    static cMultiMesh *newMesh(const char textureName[], const char loadPath[]);
    static cBulletBox *newBlock(const char textureName[], const char loadPath[]);
};
void BlockSetup::requiredBlock(cBulletBox *block)
{
    // estimate their inertia properties
    block->estimateInertia();

    // create dynamic models
    block->buildDynamicModel();

    // create collision detector for haptic interaction
    block->createAABBCollisionDetector(toolRadius);
}
cBulletBox *BlockSetup::newBlock(const char textureName[], const char loadPath[])
{
    cBulletBox *block = new cBulletBox(bulletWorld, box_scale, box_scale, box_scale);

    block->setShowEnabled(false, true); // hide the box visuals
    block->setFriction(0.6, 0.6);

    block->setMass(0.05);

    // set friction values
    block->setSurfaceFriction(0.4);

    // set position of each cube
    block->setLocalPos(0.0, 0.0, 0.5);

    block->m_material->setWhite();
    block->setUseMaterial(true, true);
    block->m_material->setStiffness(0.3 * maxStiffness);

    cMultiMesh *simple_cube = BlockSetup::newMesh(textureName, loadPath);
    simple_cube->setUseTransparency(false);

    block->addChild(simple_cube);

    bulletWorld->computeBoundaryBox(true);
    return block;
}

cBulletBox *BlockSetup::newSimpleBlock(const char textureName[])
{
    return newBlock(textureName, "./Models/Block_simple.obj");
}

cBulletBox *BlockSetup::newTopBlock(const char textureName[])
{
    return newBlock(textureName, "./Models/Block_top_and_bottom.obj");
}

cBulletBox *BlockSetup::newFullBlock(const char textureName[])
{
    return newBlock(textureName, "./Models/Block_full_sides.obj");
}

cMultiMesh *BlockSetup::newMesh(const char textureName[], const char loadPath[])
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

    // enable display list for faster graphic rendering
    simple_cube->setUseDisplayList(true);

    // center object in scene
    simple_cube->setLocalPos(-1.0 * simple_cube->getBoundaryCenter());

    simple_cube->setTexture(BlockSetup::newTexture(textureName));

    simple_cube->deleteCollisionDetector();
    // todo shading using mers texture

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

cTexture2dPtr BlockSetup::newMersTexture(const char textureName[])
{
    cTexture2dPtr texture = cTexture2d::create();
    char path[256];
    snprintf(path, sizeof(path), "./Textures/%s_mers.tga", textureName);

    bool fileload = texture->loadFromFile(path);
    if (!fileload)
    {
        std::cout << "Error - Mers texture failed to load correctly" << std::endl;
    }

    // set filtering to nearest neighbor
    texture->setMagFunction(GL_NEAREST);
    texture->setMinFunction(GL_NEAREST);
    return texture;
}
