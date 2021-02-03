/*!
 * File HPMSApiManager.h
 */


#pragma once

#include <dynalo.hpp>
#include <string>
#include <common/HPMSUtils.h>
#include <common/HPMSObject.h>
#include <api/HPMSSupplierAdapter.h>

#ifndef HPMS_BACKEND_DLL_POSTFIX
#define HPMS_BACKEND_DLL_POSTFIX
#endif

#define DEFAULT_HPMS_BACKEND_IMPL "HPMSEngineOgreImpl" HPMS_BACKEND_DLL_POSTFIX

#ifndef HPMS_BACKEND_IMPL
#define HPMS_BACKEND_IMPL DEFAULT_HPMS_BACKEND_IMPL
#endif

#define HPMS_CREATE_SUPPLIER_IMPL() hpms::ApiManager::GetSingleton().Create<hpms::SupplierAdapter>("Supplier")
#define HPMS_DESTROY_SUPPLIER_IMPL(ptr) hpms::ApiManager::GetSingleton().Create<hpms::SupplierAdapter>(ptr, "Supplier")

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

        template<typename T, typename... ARGS>
        T* Create(const std::string& name, ARGS... args);

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