#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
        ResourceManager() : resource_{} {}//lista inicjalizacyjna + konstruktor domyslny

        ResourceManager(const ResourceManager& resource_copy) : resource_{resource_copy.resource_} 
        {
            
        }//konstruktor kopiujacy

        ResourceManager& operator=(const ResourceManager& resource_operator) 
        {
            if (this == &resource_operator) 
            {
                return *this; // Unikamy przypisania do samego siebie czyli 
            }

            resource_ = resource_operator.resource_;

            return *this;
        }

        ResourceManager(ResourceManager&& resource_move) : resource_(std::move(resource_move.resource_)) {}
        ResourceManager& operator=(ResourceManager&& resource_move) 
        {
            if (this == &resource_move) {
                return *this; // Unikamy przypisania do samego siebie
            }

            resource_ = std::move(resource_move.resource_);
            return *this;
        }

        ~ResourceManager() {}//Destruktor

        double get() {return resource_.get();}//metoda double get zwracajaca wynik z resource

    private:
        Resource resource_;//W ten sposob resource manager staje sie wlascicielem resource
};
