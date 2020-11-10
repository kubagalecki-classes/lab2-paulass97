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

    ResourceManager(const ResourceManager& rs) 
    {
        res = new Resource{*rs.res};
        cout << res<<endl;
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        if (!(res == nullptr)) {
            delete res;
        }
        res = new Resource{*rs.res};
        cout <<  res << endl;
        return *this;
    }

    ResourceManager(ResourceManager&& rs)
    {
        res    = move(rs.res);
        rs.res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& rs)
    {
        if (&rs == this)
        {
            return *this;
        }
        else if (!(res == nullptr)) {
            delete res;
        }
        res = move(rs.res); 

        rs.res = nullptr;
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
