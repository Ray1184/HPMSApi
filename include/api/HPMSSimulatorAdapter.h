/*!
 * File HPMSSimulatorAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <api/HPMSInputUtils.h>
#include <vector>


namespace hpms
{

    class CustomLogic
    {
    public:
        virtual void OnCreate() = 0;

        virtual void OnUpdate(float tpf) = 0;

        virtual void OnInput(const std::vector<hpms::KeyEvent>& keyEvents,
                             const std::vector<hpms::MouseEvent>& mouseButtonEvents, unsigned int x,
                             unsigned int y) = 0;

        virtual void OnDestroy() = 0;
    };


    class SimulatorAdapter : public hpms::Object
    {
    protected:
        CustomLogic* logic;

    public:
        inline const std::string Name() const override
        {
            return "SimulatorAdapter";
        }

        inline virtual ~SimulatorAdapter()
        {

        }

        virtual void Run() = 0;



    };
}