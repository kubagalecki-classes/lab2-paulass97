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
        cout << "Konstruktor kopiujacy" << res<<endl;
    }

    ResourceManager& operator=(const ResourceManager& rs)
    {
        if (!(res == nullptr)) {
            cout << "Usuwanie" << endl;
            delete res;
        }
        res = new Resource{*rs.res};
        cout << "Operator kopiujacy" << res << endl;
        return *this;
    }

    ResourceManager(ResourceManager&& rs)
    {
        cout << "Konstruktor przenoszacy" << endl;
        res    = move(rs.res);
        rs.res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& rs)
    {
        if (&rs == this)
        {
            cout << "Przenoszenie" << endl;
            return *this;
        }
        else if (!(res == nullptr)) {
            cout << "Usuwanie" << endl;
            delete res;
        }
        cout << "Operator przenoszacy" << endl;
        res = move(rs.res); 

        rs.res = nullptr;
        return *this;
    }

    ~ResourceManager()
    {
        cout << "destruktor" << res << endl;
        delete res;
    }

  double get()
  {
    return res->get();
  }

private:
    Resource* res = nullptr;
};
