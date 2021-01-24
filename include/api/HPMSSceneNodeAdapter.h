/*!
 * File HPMSSceneNodeAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <api/HPMSActorAdapter.h>
#include <vector>

namespace hpms
{
    class SceneNodeAdapter : public hpms::ActorAdapter
    {
    public:
        inline const std::string Name() const override
        {
            return "SceneNodeAdapter";
        }

        virtual SceneNodeAdapter* CreateChild(const std::string& name) = 0;

        virtual void AttachObject(ActorAdapter* actor) = 0;

        virtual std::vector<SceneNodeAdapter*>& GetChildren() = 0;

        virtual SceneNodeAdapter* RemoveChild(const std::string& name) = 0;

        virtual void RemoveAllChildren() = 0;

        virtual SceneNodeAdapter* GetParent() = 0;
    };
}