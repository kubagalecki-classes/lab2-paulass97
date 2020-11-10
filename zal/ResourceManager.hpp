#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:

  ResourceManager() {
    r = new Resource;
  }

    ResourceManager(const ResourceManager& resM)
    {
        r = new Resource{*resM.r};
        std::cout << "konstruktor kopiujący: " << r << std::endl;
    }
    
    ResourceManager(ResourceManager&& resM) 
    {
        std::cout << "konstruktor przenoszacy: " << std::endl;
        r    = move(resM.r); 
        resM.r = nullptr;
    }
   
    ResourceManager& operator=(const ResourceManager& resM)
    {
        if (!(r == nullptr)) {
            std::cout << "samo usuwanie: " << std::endl;
            delete r;
        }
        r = new Resource{*resM.r};
        std::cout << "Operator kopiujacy: " << r << std::endl;
        return *this;
    }

    ResourceManager& operator=(ResourceManager&& resM)
    {
        if (&resM == this)
        {
            std::cout << "samo przenoszenie: " << std::endl;
            return *this;
        }
        else if (!(r == nullptr)) {
            std::cout << "samo usuwanie" << std::endl;
            delete r;
        }
        std::cout << "Operator przenoszacy: " << std::endl;
        r = move(resM.r); 

        resM.r = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        std::cout << "Destruktor: " << r << std::endl;
        delete r;
    }

  double get()
  {
    return r->get();
  }

private:
    Resource* r = nullptr;
};
