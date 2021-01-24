/*!
 * File HPMSEntityAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <api/HPMSActorAdapter.h>

namespace hpms
{

    enum EntityMode
    {
        COLOR_AND_DEPTH = 0,
        DEPTH_ONLY = 1,
        COLOR_ONLY = 2
    };

    class EntityAdapter : public hpms::ActorAdapter
    {
    public:
        inline const std::string Name() const override
        {
            return "EntityAdapter";
        }

        virtual void SetMode(EntityMode mode) = 0;

    };
}