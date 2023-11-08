#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
        ResourceManager() : resource_{} {}//lista inicjalizacyjna + konstruktor domyslny
//resource_{resource_copy.resource_} 

        ResourceManager(const ResourceManager& resource_copy) : size_{resource_copy.size_}, get_index_{resource_copy.get_index_}
        {
            /*for(int i=0; i < dlugosc; i++)
            {
                tablica[i] = vector.tablica[i];
            }*///tu trzeba cos takiego zrobic ale nie ma dostepu do elementow Resource
            //A teraz jak kopiuje to przez te randy pewnie jakies smieci wlatuja
        }//konstruktor kopiujacy

        ResourceManager& operator=(const ResourceManager& resource_operator) 
        {
            if (this == &resource_operator) 
            {
                return *this; // Unikamy przypisania do samego siebie  
            }

            resource_ = resource_operator.resource_;
            /*
        // Zwalniamy istniejące zasoby ALE NIE MAMY DOSTEPU DO TEJ TABLICY........
        delete[] tablica;

        // NOWA TABLICE STWORZYC TRZEBA
        tablica = new double[dlugosc];

        // KI wrzucic stare wartosci ALE NIE MA DOSTEPU DO TEJ TABLICY
        for (int i = 0; i < dlugosc; i++) {
            tablica[i] = vector.tablica[i];
        }
            */

            return *this;
        }

        ~ResourceManager() {/*TU POWINNA BYC NISZCZONA TABLICA ALE NIE MA DO NIEJ DOSTEPU*/}//Destruktor

        double get() {return resource_.get();}//metoda double get zwracajaca wynik z resource

    private:
        Resource resource_;//W ten sposob resource manager staje sie wlascicielem resource
        int get_index_ = resource_.get_index;
        int size_ = resource_.size;

};
