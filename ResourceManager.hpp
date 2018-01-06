//
//  ResourceManager.hpp
//  SFML Engine
//
//  Created by Mathieu Bouchonnet on 06/01/2018.
//  Copyright © 2018 Mathieu Bouchonnet. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp
#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

template <typename Derived, class T>
class ResourceManager
{
public:
    ResourceManager(const std::string& file_name)
    {
        PopulateStorage(file_name);
    }
    
    bool AddResource(const std::string& resource_name)
    {
        auto res = Find(resource_name); // see if resource is already allocated.
        
        if (res) // if it's already allocated.
        {
            ++res->second; // increments counter on map.
            return true;
        }
        
        // if the resource is not already allocated...
        
        auto file_path = file_map.find(resource_name);
        
        if (file_path == file_map.end()) // if we don't file resource in our container.
            return false;
        
        T* resource = Load(file_path->second);
        
        if(!resource) // if resource does not load.
            return false;
        
        // if we passed all tests we place resource on our container, keeping track of
        // allocated mem.
        resource_map.emplace(resource_name, std::make_pair(resource, 1));
        return true;
    }
    
    T* GetResource(const std::string& resource_name)
    {
        auto res = Find(resource_name);
        
        if (res)
            return res->first;
        else
            return NULL;
    }
    
    bool ReleaseResource(const std::string& resource_name)
    {
        auto res = Find(resource_name);
        if (!res)
            return false;
        
        --res->second; // decrement counter if it has been found.
        
        if (!res->second)
            Unload(resource_name);
        
        return true;
    }

    T* Load(const std::string& path)
    {
        return static_cast<Derived*>(this)->Load(path);
    }
    
    void KillResources()
    {
        while (resource_map.begin() != resource_map.end())
        {
            delete resource_map.begin()->second.first;
            resource_map.erase(resource_map.begin());
        }
    }
    
    ~ResourceManager()
    {
        KillResources();
    }
    
    
    
private:
    std::unordered_map< std::string, std::pair<T*, int> > resource_map; //string with pair of a Resource type + counter
    
    std::unordered_map<std::string, std::string> file_map;   //stores all resources at intialization of instance
    
    std::pair<T*, int>* Find(const std::string& resource_name)
    {
        auto itr = resource_map.find(resource_name);
        if (itr != resource_map.end())
            return &itr->second;
        else
            return NULL;
    }
    
    void Unload(const std::string& resource_name)
    {
        auto itr = resource_map.find(resource_name);
        
        if (itr == resource_map.end())
        {
            std::cerr << "Fail" << std::endl;
            return;
        }
        
        delete itr->second.first;
        resource_map.erase(itr);
    }
    
    void PopulateStorage(const std::string& fileName)
    {
        
        std::ifstream paths(fileName);
        
        if (paths.is_open())
        {
            std::string pathName;
            std::string path;
            
            while (!paths.eof())
            {
                paths >> pathName >> path;
                file_map.emplace(pathName, path);
                
            }
            
            paths.close();
            return;
            
        }
        
        std::cerr << "Fail pop" << std::endl;
        
    }
};

#endif /* ResourceManager_hpp */
