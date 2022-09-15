#ifndef __ENGINE__HPP
#define __ENGINE__HPP

class Engine
{
    private:
        bool state;     // true == on, false == off

    public:
        Engine();
        
        bool getState() const;

        void start();
        void stop();
};

#endif
