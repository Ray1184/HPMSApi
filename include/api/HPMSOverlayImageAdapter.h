/*!
 * File HPMSImageAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <api/HPMSActorAdapter.h>

namespace hpms
{



    enum BlendingType
    {
        NORMAL = 0,
        OVERLAY = 1
    };

    class OverlayImageAdapter : public ActorAdapter
    {
    public:
        inline const std::string Name() const override
        {
            return "ImageAdapter";
        }

        virtual void SetBlending(BlendingMode mode) = 0;

    };
}