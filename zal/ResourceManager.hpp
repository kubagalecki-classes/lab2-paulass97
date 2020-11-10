#pragma once

#include "Resource.hpp"
#include <iostream>
using namespace std;

class ResourceManager
{
public:
  ResourceManager() {
    res = new Resource;
  }

    ResourceManager(const ResourceManager& r) 
    {
        res = new Resource{*r.res};
        cout << res<<endl;
    }

    ResourceManager& operator=(const ResourceManager& r)
    {
        if (!(res == nullptr)) {
            delete res;
        }
        res = new Resource{*r.res};
        cout <<  res << endl;
        return *this;
    }

    ResourceManager(ResourceManager&& r)
    {
        res    = move(r.res);
        r.res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& r)
    {
        if (&r == this)
        {
            return *this;
        }
        else if (!(res == nullptr)) {
            delete res;
        }
        res = move(r.res); 

        r.res = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        cout << res << endl;
        delete res;
    }

  double get()
  {
    return res->get();
  }

private:
    Resource* res = nullptr;
};
