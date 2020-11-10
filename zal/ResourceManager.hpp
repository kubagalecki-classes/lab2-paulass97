#pragma once

#include "Resource.hpp"
#include <iostream>
using namespace std;

class ResourceManager
{
public:
  ResourceManager() {
    source = new Resource;
  }

    ResourceManager(const ResourceManager& r) 
    {
        source = new Resource{*r.source};
        cout << source<<endl;
    }

    ResourceManager& operator=(const ResourceManager& r)
    {
        if (!(source == nullptr)) {
            delete source;
        }
        source = new Resource{*r.source};
        cout <<  source << endl;
        return *this;
    }

    ResourceManager(ResourceManager&& r)
    {
        source    = move(r.source);
        r.source = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& r)
    {
        if (&r == this)
        {
            return *this;
        }
        else if (!(source == nullptr)) {
            delete source;
        }
        source = move(r.source); 

        r.source = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        cout << source << endl;
        delete source;
    }

  double get()
  {
    return source->get();
  }

private:
    Resource* source = nullptr;
};
