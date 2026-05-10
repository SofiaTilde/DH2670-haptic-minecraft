#include "BlockSetup.h"

class Blocks
{
private:
    // copy this function into public to create new blocks
    static cBulletBox *defaultBlock()
    {
        char imageName[] = "";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }

public:
    static cBulletBox *iceBlock()
    {
        char imageName[] = "ice";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.7; // default:0.3  range:0-1
        double mass = 0.02;     // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(0.0); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        // block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(0.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *packedIceBlock()
    {
        char imageName[] = "ice_packed";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.7; // default:0.3  range:0-1
        double mass = 0.02;     // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(0.0); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        // block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(0.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *blueIceBlock()
    {
        char imageName[] = "blue_ice";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.7; // default:0.3  range:0-1
        double mass = 0.02;     // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(0.0); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        // block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(0.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *mudBlock()
    {
        char imageName[] = "mud";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.1; // default:0.3  range:0-1
        double mass = 0.8;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(100); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(100.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(100.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *honeyBlock()
    {
        char imageName[] = "honey";
        // cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.1; // default:0.3  range:0-1
        double mass = 0.8;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(100); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(100.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(100.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *hayBaleBlock()
    {
        char imageName[] = "hay_bale";
        // cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.1; // default:0.3  range:0-1
        double mass = 0.8;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(100); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(100.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(100.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *slimeBlock()
    {
        char imageName[] = "slime";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.1; // default:0.3  range:0-1
        double mass = 0.8;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(100); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(100.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(100.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *clayBlock()
    {
        char imageName[] = "clay";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *sandBlock()
    {
        char imageName[] = "sand";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *gravelBlock()
    {
        char imageName[] = "gravel";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *packedMudBlock()
    {
        char imageName[] = "packed_mud";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *cobblestoneBlock()
    {
        char imageName[] = "cobblestone";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *bricksBlock()
    {
        char imageName[] = "brick";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *stoneBlock()
    {
        char imageName[] = "stone";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *dirtBlock()
    {
        char imageName[] = "dirt";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *powderSnowBlock()
    {
        char imageName[] = "powder_snow";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *tntBlock()
    {
        char imageName[] = "tnt";
        // cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *oakPlanksBlock()
    {
        char imageName[] = "oak_planks";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *birchPlanksBlock()
    {
        char imageName[] = "birch_planks";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *mangrovePlanksBlock()
    {
        char imageName[] = "mangrove_planks";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *warpedPlanksBlock()
    {
        char imageName[] = "warped_planks";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *whiteWoolBlock()
    {
        char imageName[] = "wool_colored_white";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *orangeWoolBlock()
    {
        char imageName[] = "wool_colored_orange";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *magentaWoolBlock()
    {
        char imageName[] = "wool_colored_magenta";
        cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        // cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
    static cBulletBox *grassBlock()
    {
        char imageName[] = "grass";
        // cBulletBox *block = BlockSetup::newSimpleBlock(imageName);
        cBulletBox *block = BlockSetup::newTopBlock(imageName);
        // cBulletBox *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.3  range:0-1
        double mass = 0.1;      // default:0.1  range:0-1

        /** force needed to start sliding, how slippery it is (0=slippery, ~0–1 normal, >1 sticky/strong grip)*/
        block->m_material->setStaticFriction(1.5); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        block->m_material->setDamping(10.0); // default:0.0  range:0-100

        block->m_material->setStiffness(stiffness * maxStiffness);
        block->setMass(mass * maxMass);

        BlockSetup::requiredBlock(block);
        return block;
    }
};