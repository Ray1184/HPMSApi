/*!
 * File HPMSActorAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <glm/glm.hpp>

namespace hpms
{
    class ActorAdapter : public hpms::Object
    {
    public:
        inline virtual const std::string Name() const override
        {
            return "ActorAdapter";
        }

        inline virtual ~SupplierAdapter()
        {

        }

        virtual std::string GetName() = 0;

        virtual void SetPosition(const glm::vec3& position) = 0;

        virtual glm::vec3 GetPosition() = 0;

        virtual void SetRotation(const glm::quat& rotation) = 0;

        virtual glm::quat GetRotation() = 0;

        virtual void SetScale(const glm::vec3& scale) = 0;

        virtual glm::vec3 GetScale() = 0;

        virtual void SetVisible(bool visible) = 0;

        virtual bool IsVisible() = 0;
    };
}