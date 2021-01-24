/*!
 * File HPMSApiManager.h
 */


#pragma once

#include <dynalo.hpp>
#include <string>
#include <common/HPMSUtils.h>
#include <common/HPMSObject.h>

#define DEFAULT_BACKEND_IMPL "HPMSEngineImplOgre"

#define HPMS_CREATE_ENTITY_IMPL() hpms::ApiManager::GetSingleton().Create<hpms::EntityAdapter>("Entity")

namespace hpms
{
    class ApiManager : public hpms::Object
    {
    private:
        dynalo::native::handle libHandle{};
        bool init{false};

    public:
        void Init();

        void Close();

        template<typename T>
        T* Create(const std::string& name);

        template<typename T>
        void Destroy(T* object, const std::string& name);

        inline const std::string Name() const override
        {
            return "ApiManager";
        }

        static ApiManager& GetSingleton();

        static ApiManager* GetSingletonPtr();
    };


}