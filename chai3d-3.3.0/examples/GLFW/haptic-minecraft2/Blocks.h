#include "BlockSetup.h"

class Blocks
{
private:
    // copy this function into public to create new blocks
    static cMultiMesh *defaultBlock()
    {
        char imageName[] = "";
        cMultiMesh *block = BlockSetup::newSimpleBlock(imageName);
        // cMultiMesh *block = BlockSetup::newTopBlock(imageName);
        // cMultiMesh *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.0; // default:0.0  range:0-1

        /** force needed to start sliding (0=smooth, ~0–1 normal, >1 sticky/strong grip)*/
        // block->m_material->setStaticFriction(0.0); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        // block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        // block->m_material->setDamping(0.0); // default:0.0  range:0-100
        /** distance at which magnetic attraction starts (0=off, ~0.01–0.2m typical) */
        // block->m_material->setMagnetMaxDistance(0.0); // default:0.0  range:0-0.2 m
        /** strength of magnetic pull (0=none, ~1–20N normal, higher=strong snap) */
        // block->m_material->setMagnetMaxForce(0.0); // default:0.0  range:0-50 N

        /** max force before slip occurs (0=off, ~0–5N typical textured surfaces) */
        // block->m_material->setStickSlipForceMax(0.0); // default:0.0  range:0-10 N
        /** roughness of stick-slip effect (0=smooth, ~100–5000 rough/jerky feel) */
        // block->m_material->setStickSlipStiffness(0.0); // default:0.0  range:0-5000

        /** fluid-like resistance to motion (0=air, ~1–10 water, >50 very thick fluid) */
        // block->m_material->setViscosity(0.0); // default:0.0  range:0-200

        /** strength of haptic vibration (0=none, ~0.01–0.2 subtle, >0.5 strong buzz) */
        // block->m_material->setVibrationAmplitude(0.0); // default:0.0  range:0-1
        /** speed of vibration (0–50 low rumble, 50–300 texture, 300–1000+ buzz) */
        // block->m_material->setVibrationFrequency(0.0); // default:0.0  range:0-2000 Hz

        block->m_material->setStiffness(stiffness * maxStiffness);

        return block;
    }

public:
    static cMultiMesh *dirtBlock()
    {
        char imageName[] = "dirt";
        cMultiMesh *block = BlockSetup::newSimpleBlock(imageName);
        // cMultiMesh *block = BlockSetup::newTopBlock(imageName);
        // cMultiMesh *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.3; // default:0.0  range:0-1
        /** force needed to start sliding (0=smooth, ~0–1 normal, >1 sticky/strong grip)*/
        double staticFriction = 0.0; // default:0.0  range:0-1
        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        double dynamicFriction = 0.0; // default:0.0  range:0-1

        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        // block->m_material->setDamping(0.0); // default:0.0  range:0-100
        /** distance at which magnetic attraction starts (0=off, ~0.01–0.2m typical) */
        // block->m_material->setMagnetMaxDistance(0.0); // default:0.0  range:0-0.2 m
        /** strength of magnetic pull (0=none, ~1–20N normal, higher=strong snap) */
        // block->m_material->setMagnetMaxForce(0.0); // default:0.0  range:0-50 N

        /** max force before slip occurs (0=off, ~0–5N typical textured surfaces) */
        // block->m_material->setStickSlipForceMax(0.0); // default:0.0  range:0-10 N
        /** roughness of stick-slip effect (0=smooth, ~100–5000 rough/jerky feel) */
        // block->m_material->setStickSlipStiffness(0.0); // default:0.0  range:0-5000

        /** fluid-like resistance to motion (0=air, ~1–10 water, >50 very thick fluid) */
        // block->m_material->setViscosity(0.0); // default:0.0  range:0-200

        /** strength of haptic vibration (0=none, ~0.01–0.2 subtle, >0.5 strong buzz) */
        // block->m_material->setVibrationAmplitude(0.0); // default:0.0  range:0-1
        /** speed of vibration (0–50 low rumble, 50–300 texture, 300–1000+ buzz) */
        // block->m_material->setVibrationFrequency(0.0); // default:0.0  range:0-2000 Hz

        block->setStiffness(stiffness * maxStiffness);
        block->setFriction(staticFriction, dynamicFriction);

        return block;
    }
    static cMultiMesh *grassBlock()
    {
        char imageName[] = "grass";
        // cMultiMesh *block = BlockSetup::newSimpleBlock(imageName);
        cMultiMesh *block = BlockSetup::newTopBlock(imageName);
        // cMultiMesh *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.0; // default:0.0  range:0-1

        /** force needed to start sliding (0=smooth, ~0–1 normal, >1 sticky/strong grip)*/
        // block->m_material->setStaticFriction(0.0); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        // block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        // block->m_material->setDamping(0.0); // default:0.0  range:0-100
        /** distance at which magnetic attraction starts (0=off, ~0.01–0.2m typical) */
        // block->m_material->setMagnetMaxDistance(0.0); // default:0.0  range:0-0.2 m
        /** strength of magnetic pull (0=none, ~1–20N normal, higher=strong snap) */
        // block->m_material->setMagnetMaxForce(0.0); // default:0.0  range:0-50 N

        /** max force before slip occurs (0=off, ~0–5N typical textured surfaces) */
        // block->m_material->setStickSlipForceMax(0.0); // default:0.0  range:0-10 N
        /** roughness of stick-slip effect (0=smooth, ~100–5000 rough/jerky feel) */
        // block->m_material->setStickSlipStiffness(0.0); // default:0.0  range:0-5000

        /** fluid-like resistance to motion (0=air, ~1–10 water, >50 very thick fluid) */
        // block->m_material->setViscosity(0.0); // default:0.0  range:0-200

        /** strength of haptic vibration (0=none, ~0.01–0.2 subtle, >0.5 strong buzz) */
        // block->m_material->setVibrationAmplitude(0.0); // default:0.0  range:0-1
        /** speed of vibration (0–50 low rumble, 50–300 texture, 300–1000+ buzz) */
        // block->m_material->setVibrationFrequency(0.0); // default:0.0  range:0-2000 Hz

        block->m_material->setStiffness(stiffness * maxStiffness);

        return block;
    }
    static cMultiMesh *crafterBlock()
    {
        char imageName[] = "crafter";
        // cMultiMesh *block = BlockSetup::newSimpleBlock(imageName);
        // cMultiMesh *block = BlockSetup::newTopBlock(imageName);
        cMultiMesh *block = BlockSetup::newFullBlock(imageName);

        /** how hard the object feels on contact (0=soft, higher=hard/stiff, ~500–3000 typical) */
        double stiffness = 0.0; // default:0.0  range:0-1

        /** force needed to start sliding (0=smooth, ~0–1 normal, >1 sticky/strong grip)*/
        // block->m_material->setStaticFriction(0.0); // default:0.0  range:0-3

        /** resistance while sliding (0=slippery, ~0–1 normal, >1 heavy drag)*/
        // block->m_material->setDynamicFriction(0.0); // default:0.0  range:0-3
        /** reduces oscillation/instability (0=none, ~0–10 stable feel, higher=very sluggish) */
        // block->m_material->setDamping(0.0); // default:0.0  range:0-100
        /** distance at which magnetic attraction starts (0=off, ~0.01–0.2m typical) */
        // block->m_material->setMagnetMaxDistance(0.0); // default:0.0  range:0-0.2 m
        /** strength of magnetic pull (0=none, ~1–20N normal, higher=strong snap) */
        // block->m_material->setMagnetMaxForce(0.0); // default:0.0  range:0-50 N

        /** max force before slip occurs (0=off, ~0–5N typical textured surfaces) */
        // block->m_material->setStickSlipForceMax(0.0); // default:0.0  range:0-10 N
        /** roughness of stick-slip effect (0=smooth, ~100–5000 rough/jerky feel) */
        // block->m_material->setStickSlipStiffness(0.0); // default:0.0  range:0-5000

        /** fluid-like resistance to motion (0=air, ~1–10 water, >50 very thick fluid) */
        // block->m_material->setViscosity(0.0); // default:0.0  range:0-200

        /** strength of haptic vibration (0=none, ~0.01–0.2 subtle, >0.5 strong buzz) */
        // block->m_material->setVibrationAmplitude(0.0); // default:0.0  range:0-1
        /** speed of vibration (0–50 low rumble, 50–300 texture, 300–1000+ buzz) */
        // block->m_material->setVibrationFrequency(0.0); // default:0.0  range:0-2000 Hz

        block->m_material->setStiffness(stiffness * maxStiffness);

        return block;
    }
};