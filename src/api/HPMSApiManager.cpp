/*!
 * File HPMSApiManager.cpp
 */

#include <api/HPMSApiManager.h>

template<typename T>
T* hpms::ApiManager::Create(const std::string& name)
{
    auto fnCreateT = dynalo::get_function<T*()>("Create" + name);
    T* objImpl = fnCreateT();
    objImpl->SetExportName(name);
}

template<typename T>
void hpms::ApiManager::Destroy(T* object)
{
    auto fnDestroyT = dynalo::get_function<void(T*)>("Destroy" + object->GetExportName());
    fnDestroyT(object);
}

hpms::ApiManager& hpms::ApiManager::GetSingleton()
{
    static ApiManager apiManager;
    return apiManager;
}

hpms::ApiManager* hpms::ApiManager::GetSingletonPtr()
{
    return &GetSingleton();
}

void hpms::ApiManager::Init()
{
    if (!init)
    {
        libHandle = dynalo::open(dynalo::to_native_name(DEFAULT_BACKEND_IMPL));
        init = true;
    }
}

void hpms::ApiManager::Close()
{
    if (init)
    {
        dynalo::close(libHandle);
        init = false;
    }
}

