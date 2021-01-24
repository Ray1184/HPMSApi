/*!
 * File HPMSImageAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <api/HPMSActorAdapter.h>

namespace hpms
{

    enum ImageMode
    {
        BACKGROUND = 0,
        FOREGROUND = 1
    };

    enum BlendingType
    {
        NORMAL = 0,
        OVERLAY = 1
    };

    class ImageAdapter
    {
    public:
        inline const std::string Name() const override
        {
            return "ImageAdapter";
        }

        virtual void SetMode(ImageMode mode) = 0;

        virtual void SetBlending(BlendingMode mode) = 0;

        virtual void SetPosition(const glm::vec2& position) = 0;

        virtual void SetVisible(bool visible) = 0;

    };
}