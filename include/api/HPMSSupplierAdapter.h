/*!
 * File HPMSSupplierAdapter.h
 */

#pragma once

#include <api/HPMSEntityAdapter.h>
#include <api/HPMSSceneNodeAdapter.h>
#include <api/HPMSEntityAdapter.h>
#include <api/HPMSSimulatorAdapter.h>
#include <api/HPMSBackgroundImageAdapter.h>
#include <api/HPMSOverlayImageAdapter.h>
#include <api/HPMSCameraAdapter.h>
#include <api/HPMSLightAdapter.h>

namespace hpms {
    class SupplierAdapter : public hpms::Object
    {
    public:
        inline virtual const std::string Name() const override
        {
            return "SupplierAdapter";
        }

        virtual hpms::EntityAdapter* CreateEntity(const std::string& path) = 0;

        virtual hpms::SceneNodeAdapter* GetRootSceneNode() = 0;

        virtual hpms::CameraAdapter* GetCamera() = 0;

        virtual hpms::LightAdapter* CreateLight(float r, float g, float b) = 0;

        virtual hpms::BackgroundImageAdapter* CreateBackgroundImage(const std::string& path, unsigned int width, unsigned int height) = 0;

        virtual hpms::OverlayImageAdapter* CreateOverlayImage(const std::string& path, unsigned int width, unsigned int height, unsigned int x,
                                                              unsigned int y, int zOrder) = 0;

        virtual void SetAmbientLight(const glm::vec3& rgb) = 0;

    };
}