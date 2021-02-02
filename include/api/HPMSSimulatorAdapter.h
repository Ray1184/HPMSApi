/*!
 * File HPMSSimulatorAdapter.h
 */


#pragma once

#include <common/HPMSObject.h>
#include <vector>


namespace hpms
{
    struct MouseEvent : public Object
    {
        enum MouseState
        {
            NONE,
            PRESSED_FIRST_TIME,
            PRESSED
        };

        std::string name;
        MouseState state{NONE};

        inline const std::string Name() const override
        {
            return "MouseEvent";
        }
    };

    struct KeyEvent : public Object
    {
        enum KeyState
        {
            NONE,
            PRESSED_FIRST_TIME,
            PRESSED
        };

        std::string name;
        KeyState state{NONE};


        inline const std::string Name() const override
        {
            return "KeyEvent";
        }

    };

    struct WindowSettings
    {
        unsigned int width{320};
        unsigned int height{200};
        std::string name{"HPMS Template"};
    };

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

        virtual void Run() = 0;



    };
}