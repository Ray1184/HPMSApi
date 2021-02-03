/*!
 * File HPMSApiManager.cpp
 */

#include <api/HPMSApiManager.h>

template<typename T, typename... ARGS>
T* hpms::ApiManager::Create(const std::string& name, ARGS... args)
{
    auto fnCreateT = dynalo::get_function<T*(ARGS...)>(libHandle, "Create" + name);
    return fnCreateT(args...);
}

template<typename T>
void hpms::ApiManager::Destroy(T* object, const std::string& name)
{
    auto fnDestroyT = dynalo::get_function<void(T*)>(libHandle, "Destroy" + name);
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
        libHandle = dynalo::open(HPMS_ENGINE_IMPL_FOLDER HPMS_BACKEND_IMPL);
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

