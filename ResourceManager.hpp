#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
        ResourceManager() 
            : resource_{new Resource()} //alokacja pamieci klasy Resource() o wymiarach Resource() i przypisanie wskaznika na nia do pola resource_
        {}  //lista inicjalizacyjna + konstruktor domyslny

        ResourceManager(const ResourceManager& resource_copy)
        {
           //resource_ = Resource(*resource_copy.resource_); <- statyczny konstruktor
           resource_ = new Resource(*resource_copy.resource_);// kopiujesz stara utworzona zawartosc resource biorac pod uwage wskaznik
        }//konstruktor kopiujacy

        ResourceManager& operator=(const ResourceManager& resource_operator) 
        {
            delete resource_; //Wyrzucenie zawartosci resource

            resource_ = new Resource(*resource_operator.resource_); //skopiowanie starej zawartosci resource

            return *this;
        }

        ~ResourceManager() {delete resource_;}//Destruktor

        double get() {return resource_->get();}//resource_->get()    rownowazne jest (*resource_).get()

    private:
        Resource *resource_;//W ten sposob resource manager staje sie wlascicielem resource
        //poprzez wskaznik zeby nie wywolac tego calego gnoja duzego


};
